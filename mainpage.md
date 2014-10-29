GU Simple Whiteboard {#mainpage}
================================

`gusimplewhiteboard` is a high performance, shared-memory whiteboard that offers
atomic, lock-free access for single writer / multiple reader scenarios (multi-writer
locks are supported but deprecated).
The whiteboard architecture favours the use of asynchronous `get` and `set` operations
for itempotent messages, but also has limited support for the publish/subscribe paradigm.

# Programming Language Support #

The low-level whiteboard is written in plain `C` and supports any programming language that offers `C` bindings.
Each whiteboard message is stored in a dedicated slot in shared memory.
A convenience union is provided for accessing primitive (and simply structured) data
types.

A class-based `C++` layer is provided on top of the simple whiteboard that allows
access to the shared memory using simple setters and getters.

# Building the Whiteboard #

The whiteboard is structured as a library and needs to be built and installed before
using it.
The old reachover-make still works but is deprecated and will be phased out soon.

## MiPAL Infrastructure ##

Building using the MiPAL infrastructure uses `bmake` and is handled from within
`GUNao/posix/gusimplewhiteboard`.
A simple `bmake` will build the whiteboard for the host and the default target, as well as the whiteboard documentation. 

### Building for the Host ###
To build the Whiteboard for the host use `bmake host-local`.
To install the whiteboard use `sudo bmake install`

### Building for a Target ###
To build the Whiteboard for the default target, simply use `bmake robot-local`.  To install use `bmake install-local`.
Alternatively, you can copy the whiteboard library from the build folder to the target library directory.  To install the headers, create a `gusimplewhiteboard` folder in the target (cross-build) `include` directory and copy all `.h` files there.

To build the whiteboard for a different target, use `bmake target LOCAL=_LOCAL TARGET=`*targetname*.

### Creating the ROS Makefile ###

To export the whiteboard sources into `catkin_ws` for ROS, use `bmake catkin`.

## ROS ##

To build the Whiteboard for ROS, make sure you have copied the `gusimplewhiteboard`
sources into `catkin_ws`, then simply use `catkin_make gusimplewhiteboard`.  To permanently install the whiteboard, use `catkin_make install`.


# Using the Whiteboard #

Using the whiteboard from `C` is as simple as including `gusimplewhiteboard/gusimplewhiteboard.h` then using the functions described below.
Using the whiteboard from `C++` is even simpler, just include the header file for
the whiteboard class you want to use then use the setter and getter methods to post messages to the whiteboard or retrieve them from the whiteboard.

## Getting Messages off the Whiteboard ##
### C++ ###
In `C++` for every whiteboard class, there are two key types.  The class itself
represents the data structure that is stored on the whiteboard, while a corresponding
class with the same name but an added `_t` suffix represents the whiteboard location
for that class.  E.g., the `Point2D` class represents the coordinates of a
two-dimensional point, while `Point2D_t` represents the whiteboard message for that
class.  The following code snipped could be used to copy a `Point2D` variable off the
whiteboard:

    using namespace guWhiteboard;

    Point2D_t point_on_wb;                  // whiteboard location
    Point2D my_point = point_on_wb.get();   // copy the point off the whiteboard

    // now do something with my_point
    std::cout << "x = " << my_point.x() << std::endl;

### C ###
The low-level C code to get data of the whiteboard requires two locations.


 1. The address of the whiteboard (shared memory mapped into process space)
 2. The address of the whiteboard message of interest

The easiest way to get a pointer to the whiteboard is to use 
`get_local_singleton_whiteboard()` which returns a pointer to an
instance of the default whiteboard.
The pointer that is returned can then be used to get whiteboard messages using
`gsw_current_message()`, which simply takes a message number and returns the
memory location for the current generation of that message.


## Posting Messages on the Whiteboard ##
### C++ ###
The syntax for posting messages to the whiteboard works similar to getting messages
off the whiteboard (see above), but instead of the `get()` method, you use `post()`:

    using namespace guWhiteboard;

    Point2D my_point(100,200);              // create a point at coordinates 100,200
    Point2D_t wb;                           // whiteboard location of the Point2D message

    wb.post(my_point);                      // post the point on the whiteboard

### C ###
Posting to the whiteboard in `C` requires

1. a pointer to the whiteboard (see above),
2. a pointer to the next generation of the given whiteboard message; and
3. an operation that updates the current generation of the message

For (2), the `gsw_next_message()` returns the memory address of the next generation
of the given message.
Once you have this message pointer, you can simply fill the corresponding memory
with data (no lock is needed if you are the only entity posting that message).
Once done, use `gsw_increment()` to make the posted message permanent (3).
If you want to facilitate notifing subscribers and replicating whiteboards in
a distributed environment, you also need to call `gsw_increment_event_counter()`
to update the global event counter for the given message.
