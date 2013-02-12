/* MiPAL 2010
Author: Tyrone Trevorrow & Carl Lusty
Purpose: Provides a more generic mechanism for function callbacks.
		 Feel free to extend this to support any function's parameter lists.
 Change Log:
        21/1/2013 - Extended to add simple wb compatability, Carl.
*/
#ifndef WBFUNCTOR_H
#define WBFUNCTOR_H

#include "WBMsg.h"
#include "guwhiteboardtypelist_generated.h" //for type enum
#include "gusimplewhiteboard.h" //for gu_simple_message
#define WB_BIND( f ) createWBFunctor(this, &f)
#define WB_TYPE_BIND( t, f ) createWBFunctor(this, &f, t)

class WBFunctorBase
{
public:
	virtual void call(std::string s, WBMsg* m) = 0;                         //old wbmsg format for callbacks
	virtual void call(gu_simple_message* m) = 0;                            //new simple_message callbacks
	virtual void call(guWhiteboard::WBTypes t, gu_simple_message* m) = 0;   //new simple_message callbacks (with type overwrite for subscribe to all special type)
        virtual guWhiteboard::WBTypes get_type() = 0;
        virtual uint16_t get_event_count() = 0;
        virtual void set_event_count(uint16_t e) = 0;
        virtual bool is_simple_wb_version() = 0;
	virtual ~WBFunctorBase(){}
};

template <typename C>
class WBFunctor: public WBFunctorBase
{
public:
	WBFunctor(C* obj, void (C::*pFunc) (std::string, WBMsg*)):
		fObject(obj), fFunction(pFunc), simple_wb_version(false) { };
	WBFunctor(C* obj, void (C::*pFunc) (guWhiteboard::WBTypes, gu_simple_message*), guWhiteboard::WBTypes t):
                fObject(obj), s_fFunction(pFunc), type_enum(t), event_count(0), simple_wb_version(true) { };
	
	void call(std::string s, WBMsg* m)
	{
		(fObject->*fFunction)(s,m);
	};
        void call(gu_simple_message* m)
        {
		(fObject->*s_fFunction)(type_enum, m);
        };
        void call(guWhiteboard::WBTypes t, gu_simple_message* m)
        {
		(fObject->*s_fFunction)(t, m);
        };
        guWhiteboard::WBTypes get_type() { return type_enum; };
        uint16_t get_event_count() { return event_count; };
        void set_event_count(uint16_t e) { event_count = e; };
        bool is_simple_wb_version() { return simple_wb_version; };
private:
	C* fObject;
	typedef void (C::*func) (std::string, WBMsg*);
	func fFunction;
	typedef void (C::*s_func) (guWhiteboard::WBTypes, gu_simple_message*); //simple wb implementation
	s_func s_fFunction;
        guWhiteboard::WBTypes type_enum;
        uint16_t event_count;
        bool simple_wb_version;
};

template <typename C>
WBFunctorBase* createWBFunctor(C *obj, void (C::*f) (std::string, WBMsg*))
{
	return new WBFunctor<C>(obj, f);
}
template <typename C>
WBFunctorBase* createWBFunctor(C *obj, void (C::*f) (guWhiteboard::WBTypes, gu_simple_message*), guWhiteboard::WBTypes t)
{
	return new WBFunctor<C>(obj, f, t);
}

#endif
