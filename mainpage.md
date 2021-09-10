[gusimplewhiteboard](https://github.com/mipalgu/gusimplewhiteboard) {#mainpage}
===================================================================
\tableofcontents

A simple POSIX whiteboard library.

## Online Documentation

 * [Files](https://mipalgu.github.io/gusimplewhiteboard/files.html)
   - [gusimplewhiteboard.h](https://mipalgu.github.io/gusimplewhiteboard/gusimplewhiteboard_8h.html)
   - [gusimplewhiteboard.c](https://mipalgu.github.io/gusimplewhiteboard/gusimplewhiteboard_8c.html)
 * [Module](https://mipalgu.github.io/gusimplewhiteboard/globals_defs.html)
   - [Functions](https://mipalgu.github.io/gusimplewhiteboard/globals_func.html)
   - [Classes](https://mipalgu.github.io/gusimplewhiteboard/annotated.html)
   - [Macros](https://mipalgu.github.io/gusimplewhiteboard/globals_defs.html)

## Prerequisites

You need a posix system a C/C++ compiler, [cmake](https://cmake.org),
and a build system supported by cmake, such as
[Ninja](https://ninja-build.org) or
[gmake](https://www.gnu.org/software/make/).
You also need to install the following pre-requisite packages.
Follow the links below for instructions:

 * [gu_util](https://github.com/mipalgu/gu_util)
 * [guunits](https://github.com/mipalgu/guunits)
 * [gucoordinates](https://github.com/mipalgu/gucoordinates)

## Building and Installation

To build, you simply create a build directory (e.g. `build.ninja`)
using [cmake](https://cmake.org), then use your build system to
build and install. Here is an example using
[Ninja](https://ninja-build.org):

	mkdir ../build.ninja
	cd ../build.ninja
	cmake -G Ninja ../gusimplewhiteboard
	ninja
	ninja install

If you require root permissions, run `ninja install` as root,
e.g. by using [sudo](https://www.sudo.ws):

	sudo ninja install
