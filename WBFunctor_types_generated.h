/**                                                                     
 *  /file WBFunctor_types_generated.h                                   
 *                                                                      
 *  Created by Carl Lusty in 2013.                                      
 *  Copyright (c) 2013 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     


//Generated on: Thu Mar 28 14:45:24 2013
//Generated by user: rh

template <typename Print_WBFunctor_T >
class Print_WBFunctor: public WBFunctor<Print_WBFunctor_T > 
{
public:
        Print_WBFunctor(Print_WBFunctor_T* obj, void (Print_WBFunctor_T::*pFunc) (guWhiteboard::WBTypes, std::string &), guWhiteboard::WBTypes t): WBFunctor<Print_WBFunctor_T >(obj, (void (Print_WBFunctor_T::*) (guWhiteboard::WBTypes, gu_simple_message*))pFunc, t) { }

        void call(gu_simple_message *m)
        {
                std::string result = guWhiteboard::Print_t().get_from(m);
                Print_function_t funct((void (Print_WBFunctor_T::*)(guWhiteboard::WBTypes, std::string &))WBFunctor<Print_WBFunctor_T >::get_s_func_ptr());
                (WBFunctor<Print_WBFunctor_T >::fObject->*funct)(WBFunctor<Print_WBFunctor_T >::type_enum, result);
        }
        
        typedef void (Print_WBFunctor_T::*Print_function_t) (guWhiteboard::WBTypes, std::string &);

        static WBFunctorBase *bind(Print_WBFunctor_T *obj, void (Print_WBFunctor_T::*f)(guWhiteboard::WBTypes, std::string &), guWhiteboard::WBTypes t) { return new Print_WBFunctor<Print_WBFunctor_T >(obj, f, t); }
};



template <typename Say_WBFunctor_T >
class Say_WBFunctor: public WBFunctor<Say_WBFunctor_T > 
{
public:
        Say_WBFunctor(Say_WBFunctor_T* obj, void (Say_WBFunctor_T::*pFunc) (guWhiteboard::WBTypes, std::string &), guWhiteboard::WBTypes t): WBFunctor<Say_WBFunctor_T >(obj, (void (Say_WBFunctor_T::*) (guWhiteboard::WBTypes, gu_simple_message*))pFunc, t) { }

        void call(gu_simple_message *m)
        {
                std::string result = guWhiteboard::Say_t().get_from(m);
                Say_function_t funct((void (Say_WBFunctor_T::*)(guWhiteboard::WBTypes, std::string &))WBFunctor<Say_WBFunctor_T >::get_s_func_ptr());
                (WBFunctor<Say_WBFunctor_T >::fObject->*funct)(WBFunctor<Say_WBFunctor_T >::type_enum, result);
        }
        
        typedef void (Say_WBFunctor_T::*Say_function_t) (guWhiteboard::WBTypes, std::string &);

        static WBFunctorBase *bind(Say_WBFunctor_T *obj, void (Say_WBFunctor_T::*f)(guWhiteboard::WBTypes, std::string &), guWhiteboard::WBTypes t) { return new Say_WBFunctor<Say_WBFunctor_T >(obj, f, t); }
};



template <typename Speech_WBFunctor_T >
class Speech_WBFunctor: public WBFunctor<Speech_WBFunctor_T > 
{
public:
        Speech_WBFunctor(Speech_WBFunctor_T* obj, void (Speech_WBFunctor_T::*pFunc) (guWhiteboard::WBTypes, std::string &), guWhiteboard::WBTypes t): WBFunctor<Speech_WBFunctor_T >(obj, (void (Speech_WBFunctor_T::*) (guWhiteboard::WBTypes, gu_simple_message*))pFunc, t) { }

        void call(gu_simple_message *m)
        {
                std::string result = guWhiteboard::Speech_t().get_from(m);
                Speech_function_t funct((void (Speech_WBFunctor_T::*)(guWhiteboard::WBTypes, std::string &))WBFunctor<Speech_WBFunctor_T >::get_s_func_ptr());
                (WBFunctor<Speech_WBFunctor_T >::fObject->*funct)(WBFunctor<Speech_WBFunctor_T >::type_enum, result);
        }
        
        typedef void (Speech_WBFunctor_T::*Speech_function_t) (guWhiteboard::WBTypes, std::string &);

        static WBFunctorBase *bind(Speech_WBFunctor_T *obj, void (Speech_WBFunctor_T::*f)(guWhiteboard::WBTypes, std::string &), guWhiteboard::WBTypes t) { return new Speech_WBFunctor<Speech_WBFunctor_T >(obj, f, t); }
};



template <typename QSay_WBFunctor_T >
class QSay_WBFunctor: public WBFunctor<QSay_WBFunctor_T > 
{
public:
        QSay_WBFunctor(QSay_WBFunctor_T* obj, void (QSay_WBFunctor_T::*pFunc) (guWhiteboard::WBTypes, std::string &), guWhiteboard::WBTypes t): WBFunctor<QSay_WBFunctor_T >(obj, (void (QSay_WBFunctor_T::*) (guWhiteboard::WBTypes, gu_simple_message*))pFunc, t) { }

        void call(gu_simple_message *m)
        {
                std::string result = guWhiteboard::QSay_t().get_from(m);
                QSay_function_t funct((void (QSay_WBFunctor_T::*)(guWhiteboard::WBTypes, std::string &))WBFunctor<QSay_WBFunctor_T >::get_s_func_ptr());
                (WBFunctor<QSay_WBFunctor_T >::fObject->*funct)(WBFunctor<QSay_WBFunctor_T >::type_enum, result);
        }
        
        typedef void (QSay_WBFunctor_T::*QSay_function_t) (guWhiteboard::WBTypes, std::string &);

        static WBFunctorBase *bind(QSay_WBFunctor_T *obj, void (QSay_WBFunctor_T::*f)(guWhiteboard::WBTypes, std::string &), guWhiteboard::WBTypes t) { return new QSay_WBFunctor<QSay_WBFunctor_T >(obj, f, t); }
};



template <typename QSpeech_WBFunctor_T >
class QSpeech_WBFunctor: public WBFunctor<QSpeech_WBFunctor_T > 
{
public:
        QSpeech_WBFunctor(QSpeech_WBFunctor_T* obj, void (QSpeech_WBFunctor_T::*pFunc) (guWhiteboard::WBTypes, std::string &), guWhiteboard::WBTypes t): WBFunctor<QSpeech_WBFunctor_T >(obj, (void (QSpeech_WBFunctor_T::*) (guWhiteboard::WBTypes, gu_simple_message*))pFunc, t) { }

        void call(gu_simple_message *m)
        {
                std::string result = guWhiteboard::QSpeech_t().get_from(m);
                QSpeech_function_t funct((void (QSpeech_WBFunctor_T::*)(guWhiteboard::WBTypes, std::string &))WBFunctor<QSpeech_WBFunctor_T >::get_s_func_ptr());
                (WBFunctor<QSpeech_WBFunctor_T >::fObject->*funct)(WBFunctor<QSpeech_WBFunctor_T >::type_enum, result);
        }
        
        typedef void (QSpeech_WBFunctor_T::*QSpeech_function_t) (guWhiteboard::WBTypes, std::string &);

        static WBFunctorBase *bind(QSpeech_WBFunctor_T *obj, void (QSpeech_WBFunctor_T::*f)(guWhiteboard::WBTypes, std::string &), guWhiteboard::WBTypes t) { return new QSpeech_WBFunctor<QSpeech_WBFunctor_T >(obj, f, t); }
};



template <typename SpeechOutput_WBFunctor_T >
class SpeechOutput_WBFunctor: public WBFunctor<SpeechOutput_WBFunctor_T > 
{
public:
        SpeechOutput_WBFunctor(SpeechOutput_WBFunctor_T* obj, void (SpeechOutput_WBFunctor_T::*pFunc) (guWhiteboard::WBTypes, bool &), guWhiteboard::WBTypes t): WBFunctor<SpeechOutput_WBFunctor_T >(obj, (void (SpeechOutput_WBFunctor_T::*) (guWhiteboard::WBTypes, gu_simple_message*))pFunc, t) { }

        void call(gu_simple_message *m)
        {
                bool result = guWhiteboard::SpeechOutput_t().get_from(m);
                SpeechOutput_function_t funct((void (SpeechOutput_WBFunctor_T::*)(guWhiteboard::WBTypes, bool &))WBFunctor<SpeechOutput_WBFunctor_T >::get_s_func_ptr());
                (WBFunctor<SpeechOutput_WBFunctor_T >::fObject->*funct)(WBFunctor<SpeechOutput_WBFunctor_T >::type_enum, result);
        }
        
        typedef void (SpeechOutput_WBFunctor_T::*SpeechOutput_function_t) (guWhiteboard::WBTypes, bool &);

        static WBFunctorBase *bind(SpeechOutput_WBFunctor_T *obj, void (SpeechOutput_WBFunctor_T::*f)(guWhiteboard::WBTypes, bool &), guWhiteboard::WBTypes t) { return new SpeechOutput_WBFunctor<SpeechOutput_WBFunctor_T >(obj, f, t); }
};



template <typename BoolExample_WBFunctor_T >
class BoolExample_WBFunctor: public WBFunctor<BoolExample_WBFunctor_T > 
{
public:
        BoolExample_WBFunctor(BoolExample_WBFunctor_T* obj, void (BoolExample_WBFunctor_T::*pFunc) (guWhiteboard::WBTypes, bool &), guWhiteboard::WBTypes t): WBFunctor<BoolExample_WBFunctor_T >(obj, (void (BoolExample_WBFunctor_T::*) (guWhiteboard::WBTypes, gu_simple_message*))pFunc, t) { }

        void call(gu_simple_message *m)
        {
                bool result = guWhiteboard::BoolExample_t().get_from(m);
                BoolExample_function_t funct((void (BoolExample_WBFunctor_T::*)(guWhiteboard::WBTypes, bool &))WBFunctor<BoolExample_WBFunctor_T >::get_s_func_ptr());
                (WBFunctor<BoolExample_WBFunctor_T >::fObject->*funct)(WBFunctor<BoolExample_WBFunctor_T >::type_enum, result);
        }
        
        typedef void (BoolExample_WBFunctor_T::*BoolExample_function_t) (guWhiteboard::WBTypes, bool &);

        static WBFunctorBase *bind(BoolExample_WBFunctor_T *obj, void (BoolExample_WBFunctor_T::*f)(guWhiteboard::WBTypes, bool &), guWhiteboard::WBTypes t) { return new BoolExample_WBFunctor<BoolExample_WBFunctor_T >(obj, f, t); }
};



#ifdef CustClass_DEFINED
template <typename CustomClassExample_WBFunctor_T >
class CustomClassExample_WBFunctor: public WBFunctor<CustomClassExample_WBFunctor_T > 
{
public:
        CustomClassExample_WBFunctor(CustomClassExample_WBFunctor_T* obj, void (CustomClassExample_WBFunctor_T::*pFunc) (guWhiteboard::WBTypes, guWhiteboard::CustClass &), guWhiteboard::WBTypes t): WBFunctor<CustomClassExample_WBFunctor_T >(obj, (void (CustomClassExample_WBFunctor_T::*) (guWhiteboard::WBTypes, gu_simple_message*))pFunc, t) { }

        void call(gu_simple_message *m)
        {
                guWhiteboard::CustClass result = guWhiteboard::CustomClassExample_t().get_from(m);
                CustomClassExample_function_t funct((void (CustomClassExample_WBFunctor_T::*)(guWhiteboard::WBTypes, guWhiteboard::CustClass &))WBFunctor<CustomClassExample_WBFunctor_T >::get_s_func_ptr());
                (WBFunctor<CustomClassExample_WBFunctor_T >::fObject->*funct)(WBFunctor<CustomClassExample_WBFunctor_T >::type_enum, result);
        }
        
        typedef void (CustomClassExample_WBFunctor_T::*CustomClassExample_function_t) (guWhiteboard::WBTypes, guWhiteboard::CustClass &);

        static WBFunctorBase *bind(CustomClassExample_WBFunctor_T *obj, void (CustomClassExample_WBFunctor_T::*f)(guWhiteboard::WBTypes, guWhiteboard::CustClass &), guWhiteboard::WBTypes t) { return new CustomClassExample_WBFunctor<CustomClassExample_WBFunctor_T >(obj, f, t); }
};

#endif //CustClass_DEFINED


template <typename NaoMotionPlayer_WBFunctor_T >
class NaoMotionPlayer_WBFunctor: public WBFunctor<NaoMotionPlayer_WBFunctor_T > 
{
public:
        NaoMotionPlayer_WBFunctor(NaoMotionPlayer_WBFunctor_T* obj, void (NaoMotionPlayer_WBFunctor_T::*pFunc) (guWhiteboard::WBTypes, std::string &), guWhiteboard::WBTypes t): WBFunctor<NaoMotionPlayer_WBFunctor_T >(obj, (void (NaoMotionPlayer_WBFunctor_T::*) (guWhiteboard::WBTypes, gu_simple_message*))pFunc, t) { }

        void call(gu_simple_message *m)
        {
                std::string result = guWhiteboard::NaoMotionPlayer_t().get_from(m);
                NaoMotionPlayer_function_t funct((void (NaoMotionPlayer_WBFunctor_T::*)(guWhiteboard::WBTypes, std::string &))WBFunctor<NaoMotionPlayer_WBFunctor_T >::get_s_func_ptr());
                (WBFunctor<NaoMotionPlayer_WBFunctor_T >::fObject->*funct)(WBFunctor<NaoMotionPlayer_WBFunctor_T >::type_enum, result);
        }
        
        typedef void (NaoMotionPlayer_WBFunctor_T::*NaoMotionPlayer_function_t) (guWhiteboard::WBTypes, std::string &);

        static WBFunctorBase *bind(NaoMotionPlayer_WBFunctor_T *obj, void (NaoMotionPlayer_WBFunctor_T::*f)(guWhiteboard::WBTypes, std::string &), guWhiteboard::WBTypes t) { return new NaoMotionPlayer_WBFunctor<NaoMotionPlayer_WBFunctor_T >(obj, f, t); }
};



template <typename NaoMotionPlayerIsRunning_WBFunctor_T >
class NaoMotionPlayerIsRunning_WBFunctor: public WBFunctor<NaoMotionPlayerIsRunning_WBFunctor_T > 
{
public:
        NaoMotionPlayerIsRunning_WBFunctor(NaoMotionPlayerIsRunning_WBFunctor_T* obj, void (NaoMotionPlayerIsRunning_WBFunctor_T::*pFunc) (guWhiteboard::WBTypes, bool &), guWhiteboard::WBTypes t): WBFunctor<NaoMotionPlayerIsRunning_WBFunctor_T >(obj, (void (NaoMotionPlayerIsRunning_WBFunctor_T::*) (guWhiteboard::WBTypes, gu_simple_message*))pFunc, t) { }

        void call(gu_simple_message *m)
        {
                bool result = guWhiteboard::NaoMotionPlayerIsRunning_t().get_from(m);
                NaoMotionPlayerIsRunning_function_t funct((void (NaoMotionPlayerIsRunning_WBFunctor_T::*)(guWhiteboard::WBTypes, bool &))WBFunctor<NaoMotionPlayerIsRunning_WBFunctor_T >::get_s_func_ptr());
                (WBFunctor<NaoMotionPlayerIsRunning_WBFunctor_T >::fObject->*funct)(WBFunctor<NaoMotionPlayerIsRunning_WBFunctor_T >::type_enum, result);
        }
        
        typedef void (NaoMotionPlayerIsRunning_WBFunctor_T::*NaoMotionPlayerIsRunning_function_t) (guWhiteboard::WBTypes, bool &);

        static WBFunctorBase *bind(NaoMotionPlayerIsRunning_WBFunctor_T *obj, void (NaoMotionPlayerIsRunning_WBFunctor_T::*f)(guWhiteboard::WBTypes, bool &), guWhiteboard::WBTypes t) { return new NaoMotionPlayerIsRunning_WBFunctor<NaoMotionPlayerIsRunning_WBFunctor_T >(obj, f, t); }
};



template <typename NaoWalk_WBFunctor_T >
class NaoWalk_WBFunctor: public WBFunctor<NaoWalk_WBFunctor_T > 
{
public:
        NaoWalk_WBFunctor(NaoWalk_WBFunctor_T* obj, void (NaoWalk_WBFunctor_T::*pFunc) (guWhiteboard::WBTypes, std::vector<int> &), guWhiteboard::WBTypes t): WBFunctor<NaoWalk_WBFunctor_T >(obj, (void (NaoWalk_WBFunctor_T::*) (guWhiteboard::WBTypes, gu_simple_message*))pFunc, t) { }

        void call(gu_simple_message *m)
        {
                std::vector<int> result = guWhiteboard::NaoWalk_t().get_from(m);
                NaoWalk_function_t funct((void (NaoWalk_WBFunctor_T::*)(guWhiteboard::WBTypes, std::vector<int> &))WBFunctor<NaoWalk_WBFunctor_T >::get_s_func_ptr());
                (WBFunctor<NaoWalk_WBFunctor_T >::fObject->*funct)(WBFunctor<NaoWalk_WBFunctor_T >::type_enum, result);
        }
        
        typedef void (NaoWalk_WBFunctor_T::*NaoWalk_function_t) (guWhiteboard::WBTypes, std::vector<int> &);

        static WBFunctorBase *bind(NaoWalk_WBFunctor_T *obj, void (NaoWalk_WBFunctor_T::*f)(guWhiteboard::WBTypes, std::vector<int> &), guWhiteboard::WBTypes t) { return new NaoWalk_WBFunctor<NaoWalk_WBFunctor_T >(obj, f, t); }
};



template <typename NaoWalkIsRunning_WBFunctor_T >
class NaoWalkIsRunning_WBFunctor: public WBFunctor<NaoWalkIsRunning_WBFunctor_T > 
{
public:
        NaoWalkIsRunning_WBFunctor(NaoWalkIsRunning_WBFunctor_T* obj, void (NaoWalkIsRunning_WBFunctor_T::*pFunc) (guWhiteboard::WBTypes, bool &), guWhiteboard::WBTypes t): WBFunctor<NaoWalkIsRunning_WBFunctor_T >(obj, (void (NaoWalkIsRunning_WBFunctor_T::*) (guWhiteboard::WBTypes, gu_simple_message*))pFunc, t) { }

        void call(gu_simple_message *m)
        {
                bool result = guWhiteboard::NaoWalkIsRunning_t().get_from(m);
                NaoWalkIsRunning_function_t funct((void (NaoWalkIsRunning_WBFunctor_T::*)(guWhiteboard::WBTypes, bool &))WBFunctor<NaoWalkIsRunning_WBFunctor_T >::get_s_func_ptr());
                (WBFunctor<NaoWalkIsRunning_WBFunctor_T >::fObject->*funct)(WBFunctor<NaoWalkIsRunning_WBFunctor_T >::type_enum, result);
        }
        
        typedef void (NaoWalkIsRunning_WBFunctor_T::*NaoWalkIsRunning_function_t) (guWhiteboard::WBTypes, bool &);

        static WBFunctorBase *bind(NaoWalkIsRunning_WBFunctor_T *obj, void (NaoWalkIsRunning_WBFunctor_T::*f)(guWhiteboard::WBTypes, bool &), guWhiteboard::WBTypes t) { return new NaoWalkIsRunning_WBFunctor<NaoWalkIsRunning_WBFunctor_T >(obj, f, t); }
};



template <typename HeadStiffness_WBFunctor_T >
class HeadStiffness_WBFunctor: public WBFunctor<HeadStiffness_WBFunctor_T > 
{
public:
        HeadStiffness_WBFunctor(HeadStiffness_WBFunctor_T* obj, void (HeadStiffness_WBFunctor_T::*pFunc) (guWhiteboard::WBTypes, float &), guWhiteboard::WBTypes t): WBFunctor<HeadStiffness_WBFunctor_T >(obj, (void (HeadStiffness_WBFunctor_T::*) (guWhiteboard::WBTypes, gu_simple_message*))pFunc, t) { }

        void call(gu_simple_message *m)
        {
                float result = guWhiteboard::HeadStiffness_t().get_from(m);
                HeadStiffness_function_t funct((void (HeadStiffness_WBFunctor_T::*)(guWhiteboard::WBTypes, float &))WBFunctor<HeadStiffness_WBFunctor_T >::get_s_func_ptr());
                (WBFunctor<HeadStiffness_WBFunctor_T >::fObject->*funct)(WBFunctor<HeadStiffness_WBFunctor_T >::type_enum, result);
        }
        
        typedef void (HeadStiffness_WBFunctor_T::*HeadStiffness_function_t) (guWhiteboard::WBTypes, float &);

        static WBFunctorBase *bind(HeadStiffness_WBFunctor_T *obj, void (HeadStiffness_WBFunctor_T::*f)(guWhiteboard::WBTypes, float &), guWhiteboard::WBTypes t) { return new HeadStiffness_WBFunctor<HeadStiffness_WBFunctor_T >(obj, f, t); }
};



template <typename HoldingStiffness_WBFunctor_T >
class HoldingStiffness_WBFunctor: public WBFunctor<HoldingStiffness_WBFunctor_T > 
{
public:
        HoldingStiffness_WBFunctor(HoldingStiffness_WBFunctor_T* obj, void (HoldingStiffness_WBFunctor_T::*pFunc) (guWhiteboard::WBTypes, float &), guWhiteboard::WBTypes t): WBFunctor<HoldingStiffness_WBFunctor_T >(obj, (void (HoldingStiffness_WBFunctor_T::*) (guWhiteboard::WBTypes, gu_simple_message*))pFunc, t) { }

        void call(gu_simple_message *m)
        {
                float result = guWhiteboard::HoldingStiffness_t().get_from(m);
                HoldingStiffness_function_t funct((void (HoldingStiffness_WBFunctor_T::*)(guWhiteboard::WBTypes, float &))WBFunctor<HoldingStiffness_WBFunctor_T >::get_s_func_ptr());
                (WBFunctor<HoldingStiffness_WBFunctor_T >::fObject->*funct)(WBFunctor<HoldingStiffness_WBFunctor_T >::type_enum, result);
        }
        
        typedef void (HoldingStiffness_WBFunctor_T::*HoldingStiffness_function_t) (guWhiteboard::WBTypes, float &);

        static WBFunctorBase *bind(HoldingStiffness_WBFunctor_T *obj, void (HoldingStiffness_WBFunctor_T::*f)(guWhiteboard::WBTypes, float &), guWhiteboard::WBTypes t) { return new HoldingStiffness_WBFunctor<HoldingStiffness_WBFunctor_T >(obj, f, t); }
};



template <typename GenericAngleChange_WBFunctor_T >
class GenericAngleChange_WBFunctor: public WBFunctor<GenericAngleChange_WBFunctor_T > 
{
public:
        GenericAngleChange_WBFunctor(GenericAngleChange_WBFunctor_T* obj, void (GenericAngleChange_WBFunctor_T::*pFunc) (guWhiteboard::WBTypes, std::vector<int> &), guWhiteboard::WBTypes t): WBFunctor<GenericAngleChange_WBFunctor_T >(obj, (void (GenericAngleChange_WBFunctor_T::*) (guWhiteboard::WBTypes, gu_simple_message*))pFunc, t) { }

        void call(gu_simple_message *m)
        {
                std::vector<int> result = guWhiteboard::GenericAngleChange_t().get_from(m);
                GenericAngleChange_function_t funct((void (GenericAngleChange_WBFunctor_T::*)(guWhiteboard::WBTypes, std::vector<int> &))WBFunctor<GenericAngleChange_WBFunctor_T >::get_s_func_ptr());
                (WBFunctor<GenericAngleChange_WBFunctor_T >::fObject->*funct)(WBFunctor<GenericAngleChange_WBFunctor_T >::type_enum, result);
        }
        
        typedef void (GenericAngleChange_WBFunctor_T::*GenericAngleChange_function_t) (guWhiteboard::WBTypes, std::vector<int> &);

        static WBFunctorBase *bind(GenericAngleChange_WBFunctor_T *obj, void (GenericAngleChange_WBFunctor_T::*f)(guWhiteboard::WBTypes, std::vector<int> &), guWhiteboard::WBTypes t) { return new GenericAngleChange_WBFunctor<GenericAngleChange_WBFunctor_T >(obj, f, t); }
};



template <typename GenericAngleChangeIsRunning_WBFunctor_T >
class GenericAngleChangeIsRunning_WBFunctor: public WBFunctor<GenericAngleChangeIsRunning_WBFunctor_T > 
{
public:
        GenericAngleChangeIsRunning_WBFunctor(GenericAngleChangeIsRunning_WBFunctor_T* obj, void (GenericAngleChangeIsRunning_WBFunctor_T::*pFunc) (guWhiteboard::WBTypes, bool &), guWhiteboard::WBTypes t): WBFunctor<GenericAngleChangeIsRunning_WBFunctor_T >(obj, (void (GenericAngleChangeIsRunning_WBFunctor_T::*) (guWhiteboard::WBTypes, gu_simple_message*))pFunc, t) { }

        void call(gu_simple_message *m)
        {
                bool result = guWhiteboard::GenericAngleChangeIsRunning_t().get_from(m);
                GenericAngleChangeIsRunning_function_t funct((void (GenericAngleChangeIsRunning_WBFunctor_T::*)(guWhiteboard::WBTypes, bool &))WBFunctor<GenericAngleChangeIsRunning_WBFunctor_T >::get_s_func_ptr());
                (WBFunctor<GenericAngleChangeIsRunning_WBFunctor_T >::fObject->*funct)(WBFunctor<GenericAngleChangeIsRunning_WBFunctor_T >::type_enum, result);
        }
        
        typedef void (GenericAngleChangeIsRunning_WBFunctor_T::*GenericAngleChangeIsRunning_function_t) (guWhiteboard::WBTypes, bool &);

        static WBFunctorBase *bind(GenericAngleChangeIsRunning_WBFunctor_T *obj, void (GenericAngleChangeIsRunning_WBFunctor_T::*f)(guWhiteboard::WBTypes, bool &), guWhiteboard::WBTypes t) { return new GenericAngleChangeIsRunning_WBFunctor<GenericAngleChangeIsRunning_WBFunctor_T >(obj, f, t); }
};



#ifdef HAL_HeadTarget_DEFINED
template <typename HAL_HeadTarget_WBFunctor_T >
class HAL_HeadTarget_WBFunctor: public WBFunctor<HAL_HeadTarget_WBFunctor_T > 
{
public:
        HAL_HeadTarget_WBFunctor(HAL_HeadTarget_WBFunctor_T* obj, void (HAL_HeadTarget_WBFunctor_T::*pFunc) (guWhiteboard::WBTypes, guWhiteboard::HAL_HeadTarget &), guWhiteboard::WBTypes t): WBFunctor<HAL_HeadTarget_WBFunctor_T >(obj, (void (HAL_HeadTarget_WBFunctor_T::*) (guWhiteboard::WBTypes, gu_simple_message*))pFunc, t) { }

        void call(gu_simple_message *m)
        {
                guWhiteboard::HAL_HeadTarget result = guWhiteboard::HAL_HeadTarget_t().get_from(m);
                HAL_HeadTarget_function_t funct((void (HAL_HeadTarget_WBFunctor_T::*)(guWhiteboard::WBTypes, guWhiteboard::HAL_HeadTarget &))WBFunctor<HAL_HeadTarget_WBFunctor_T >::get_s_func_ptr());
                (WBFunctor<HAL_HeadTarget_WBFunctor_T >::fObject->*funct)(WBFunctor<HAL_HeadTarget_WBFunctor_T >::type_enum, result);
        }
        
        typedef void (HAL_HeadTarget_WBFunctor_T::*HAL_HeadTarget_function_t) (guWhiteboard::WBTypes, guWhiteboard::HAL_HeadTarget &);

        static WBFunctorBase *bind(HAL_HeadTarget_WBFunctor_T *obj, void (HAL_HeadTarget_WBFunctor_T::*f)(guWhiteboard::WBTypes, guWhiteboard::HAL_HeadTarget &), guWhiteboard::WBTypes t) { return new HAL_HeadTarget_WBFunctor<HAL_HeadTarget_WBFunctor_T >(obj, f, t); }
};

#endif //HAL_HeadTarget_DEFINED


#ifdef SENSORS_FootSensors_DEFINED
template <typename SENSORS_FootSensors_WBFunctor_T >
class SENSORS_FootSensors_WBFunctor: public WBFunctor<SENSORS_FootSensors_WBFunctor_T > 
{
public:
        SENSORS_FootSensors_WBFunctor(SENSORS_FootSensors_WBFunctor_T* obj, void (SENSORS_FootSensors_WBFunctor_T::*pFunc) (guWhiteboard::WBTypes, guWhiteboard::SENSORS_FootSensors &), guWhiteboard::WBTypes t): WBFunctor<SENSORS_FootSensors_WBFunctor_T >(obj, (void (SENSORS_FootSensors_WBFunctor_T::*) (guWhiteboard::WBTypes, gu_simple_message*))pFunc, t) { }

        void call(gu_simple_message *m)
        {
                guWhiteboard::SENSORS_FootSensors result = guWhiteboard::SENSORS_FootSensors_t().get_from(m);
                SENSORS_FootSensors_function_t funct((void (SENSORS_FootSensors_WBFunctor_T::*)(guWhiteboard::WBTypes, guWhiteboard::SENSORS_FootSensors &))WBFunctor<SENSORS_FootSensors_WBFunctor_T >::get_s_func_ptr());
                (WBFunctor<SENSORS_FootSensors_WBFunctor_T >::fObject->*funct)(WBFunctor<SENSORS_FootSensors_WBFunctor_T >::type_enum, result);
        }
        
        typedef void (SENSORS_FootSensors_WBFunctor_T::*SENSORS_FootSensors_function_t) (guWhiteboard::WBTypes, guWhiteboard::SENSORS_FootSensors &);

        static WBFunctorBase *bind(SENSORS_FootSensors_WBFunctor_T *obj, void (SENSORS_FootSensors_WBFunctor_T::*f)(guWhiteboard::WBTypes, guWhiteboard::SENSORS_FootSensors &), guWhiteboard::WBTypes t) { return new SENSORS_FootSensors_WBFunctor<SENSORS_FootSensors_WBFunctor_T >(obj, f, t); }
};

#endif //SENSORS_FootSensors_DEFINED


#ifdef SENSORS_BodySensors_DEFINED
template <typename SENSORS_BodySensors_WBFunctor_T >
class SENSORS_BodySensors_WBFunctor: public WBFunctor<SENSORS_BodySensors_WBFunctor_T > 
{
public:
        SENSORS_BodySensors_WBFunctor(SENSORS_BodySensors_WBFunctor_T* obj, void (SENSORS_BodySensors_WBFunctor_T::*pFunc) (guWhiteboard::WBTypes, guWhiteboard::SENSORS_BodySensors &), guWhiteboard::WBTypes t): WBFunctor<SENSORS_BodySensors_WBFunctor_T >(obj, (void (SENSORS_BodySensors_WBFunctor_T::*) (guWhiteboard::WBTypes, gu_simple_message*))pFunc, t) { }

        void call(gu_simple_message *m)
        {
                guWhiteboard::SENSORS_BodySensors result = guWhiteboard::SENSORS_BodySensors_t().get_from(m);
                SENSORS_BodySensors_function_t funct((void (SENSORS_BodySensors_WBFunctor_T::*)(guWhiteboard::WBTypes, guWhiteboard::SENSORS_BodySensors &))WBFunctor<SENSORS_BodySensors_WBFunctor_T >::get_s_func_ptr());
                (WBFunctor<SENSORS_BodySensors_WBFunctor_T >::fObject->*funct)(WBFunctor<SENSORS_BodySensors_WBFunctor_T >::type_enum, result);
        }
        
        typedef void (SENSORS_BodySensors_WBFunctor_T::*SENSORS_BodySensors_function_t) (guWhiteboard::WBTypes, guWhiteboard::SENSORS_BodySensors &);

        static WBFunctorBase *bind(SENSORS_BodySensors_WBFunctor_T *obj, void (SENSORS_BodySensors_WBFunctor_T::*f)(guWhiteboard::WBTypes, guWhiteboard::SENSORS_BodySensors &), guWhiteboard::WBTypes t) { return new SENSORS_BodySensors_WBFunctor<SENSORS_BodySensors_WBFunctor_T >(obj, f, t); }
};

#endif //SENSORS_BodySensors_DEFINED


#ifdef SENSORS_LedsSensors_DEFINED
template <typename SENSORS_LedsSensors_WBFunctor_T >
class SENSORS_LedsSensors_WBFunctor: public WBFunctor<SENSORS_LedsSensors_WBFunctor_T > 
{
public:
        SENSORS_LedsSensors_WBFunctor(SENSORS_LedsSensors_WBFunctor_T* obj, void (SENSORS_LedsSensors_WBFunctor_T::*pFunc) (guWhiteboard::WBTypes, guWhiteboard::SENSORS_LedsSensors &), guWhiteboard::WBTypes t): WBFunctor<SENSORS_LedsSensors_WBFunctor_T >(obj, (void (SENSORS_LedsSensors_WBFunctor_T::*) (guWhiteboard::WBTypes, gu_simple_message*))pFunc, t) { }

        void call(gu_simple_message *m)
        {
                guWhiteboard::SENSORS_LedsSensors result = guWhiteboard::SENSORS_LedsSensors_t().get_from(m);
                SENSORS_LedsSensors_function_t funct((void (SENSORS_LedsSensors_WBFunctor_T::*)(guWhiteboard::WBTypes, guWhiteboard::SENSORS_LedsSensors &))WBFunctor<SENSORS_LedsSensors_WBFunctor_T >::get_s_func_ptr());
                (WBFunctor<SENSORS_LedsSensors_WBFunctor_T >::fObject->*funct)(WBFunctor<SENSORS_LedsSensors_WBFunctor_T >::type_enum, result);
        }
        
        typedef void (SENSORS_LedsSensors_WBFunctor_T::*SENSORS_LedsSensors_function_t) (guWhiteboard::WBTypes, guWhiteboard::SENSORS_LedsSensors &);

        static WBFunctorBase *bind(SENSORS_LedsSensors_WBFunctor_T *obj, void (SENSORS_LedsSensors_WBFunctor_T::*f)(guWhiteboard::WBTypes, guWhiteboard::SENSORS_LedsSensors &), guWhiteboard::WBTypes t) { return new SENSORS_LedsSensors_WBFunctor<SENSORS_LedsSensors_WBFunctor_T >(obj, f, t); }
};

#endif //SENSORS_LedsSensors_DEFINED


#ifdef SENSORS_LegJointTemps_DEFINED
template <typename SENSORS_LegJointTemps_WBFunctor_T >
class SENSORS_LegJointTemps_WBFunctor: public WBFunctor<SENSORS_LegJointTemps_WBFunctor_T > 
{
public:
        SENSORS_LegJointTemps_WBFunctor(SENSORS_LegJointTemps_WBFunctor_T* obj, void (SENSORS_LegJointTemps_WBFunctor_T::*pFunc) (guWhiteboard::WBTypes, guWhiteboard::SENSORS_LegJointTemps &), guWhiteboard::WBTypes t): WBFunctor<SENSORS_LegJointTemps_WBFunctor_T >(obj, (void (SENSORS_LegJointTemps_WBFunctor_T::*) (guWhiteboard::WBTypes, gu_simple_message*))pFunc, t) { }

        void call(gu_simple_message *m)
        {
                guWhiteboard::SENSORS_LegJointTemps result = guWhiteboard::SENSORS_LegJointTemps_t().get_from(m);
                SENSORS_LegJointTemps_function_t funct((void (SENSORS_LegJointTemps_WBFunctor_T::*)(guWhiteboard::WBTypes, guWhiteboard::SENSORS_LegJointTemps &))WBFunctor<SENSORS_LegJointTemps_WBFunctor_T >::get_s_func_ptr());
                (WBFunctor<SENSORS_LegJointTemps_WBFunctor_T >::fObject->*funct)(WBFunctor<SENSORS_LegJointTemps_WBFunctor_T >::type_enum, result);
        }
        
        typedef void (SENSORS_LegJointTemps_WBFunctor_T::*SENSORS_LegJointTemps_function_t) (guWhiteboard::WBTypes, guWhiteboard::SENSORS_LegJointTemps &);

        static WBFunctorBase *bind(SENSORS_LegJointTemps_WBFunctor_T *obj, void (SENSORS_LegJointTemps_WBFunctor_T::*f)(guWhiteboard::WBTypes, guWhiteboard::SENSORS_LegJointTemps &), guWhiteboard::WBTypes t) { return new SENSORS_LegJointTemps_WBFunctor<SENSORS_LegJointTemps_WBFunctor_T >(obj, f, t); }
};

#endif //SENSORS_LegJointTemps_DEFINED


#ifdef SENSORS_TorsoJointTemps_DEFINED
template <typename SENSORS_TorsoJointTemps_WBFunctor_T >
class SENSORS_TorsoJointTemps_WBFunctor: public WBFunctor<SENSORS_TorsoJointTemps_WBFunctor_T > 
{
public:
        SENSORS_TorsoJointTemps_WBFunctor(SENSORS_TorsoJointTemps_WBFunctor_T* obj, void (SENSORS_TorsoJointTemps_WBFunctor_T::*pFunc) (guWhiteboard::WBTypes, guWhiteboard::SENSORS_TorsoJointTemps &), guWhiteboard::WBTypes t): WBFunctor<SENSORS_TorsoJointTemps_WBFunctor_T >(obj, (void (SENSORS_TorsoJointTemps_WBFunctor_T::*) (guWhiteboard::WBTypes, gu_simple_message*))pFunc, t) { }

        void call(gu_simple_message *m)
        {
                guWhiteboard::SENSORS_TorsoJointTemps result = guWhiteboard::SENSORS_TorsoJointTemps_t().get_from(m);
                SENSORS_TorsoJointTemps_function_t funct((void (SENSORS_TorsoJointTemps_WBFunctor_T::*)(guWhiteboard::WBTypes, guWhiteboard::SENSORS_TorsoJointTemps &))WBFunctor<SENSORS_TorsoJointTemps_WBFunctor_T >::get_s_func_ptr());
                (WBFunctor<SENSORS_TorsoJointTemps_WBFunctor_T >::fObject->*funct)(WBFunctor<SENSORS_TorsoJointTemps_WBFunctor_T >::type_enum, result);
        }
        
        typedef void (SENSORS_TorsoJointTemps_WBFunctor_T::*SENSORS_TorsoJointTemps_function_t) (guWhiteboard::WBTypes, guWhiteboard::SENSORS_TorsoJointTemps &);

        static WBFunctorBase *bind(SENSORS_TorsoJointTemps_WBFunctor_T *obj, void (SENSORS_TorsoJointTemps_WBFunctor_T::*f)(guWhiteboard::WBTypes, guWhiteboard::SENSORS_TorsoJointTemps &), guWhiteboard::WBTypes t) { return new SENSORS_TorsoJointTemps_WBFunctor<SENSORS_TorsoJointTemps_WBFunctor_T >(obj, f, t); }
};

#endif //SENSORS_TorsoJointTemps_DEFINED


#ifdef SENSORS_LegJointSensors_DEFINED
template <typename SENSORS_LegJointSensors_WBFunctor_T >
class SENSORS_LegJointSensors_WBFunctor: public WBFunctor<SENSORS_LegJointSensors_WBFunctor_T > 
{
public:
        SENSORS_LegJointSensors_WBFunctor(SENSORS_LegJointSensors_WBFunctor_T* obj, void (SENSORS_LegJointSensors_WBFunctor_T::*pFunc) (guWhiteboard::WBTypes, guWhiteboard::SENSORS_LegJointSensors &), guWhiteboard::WBTypes t): WBFunctor<SENSORS_LegJointSensors_WBFunctor_T >(obj, (void (SENSORS_LegJointSensors_WBFunctor_T::*) (guWhiteboard::WBTypes, gu_simple_message*))pFunc, t) { }

        void call(gu_simple_message *m)
        {
                guWhiteboard::SENSORS_LegJointSensors result = guWhiteboard::SENSORS_LegJointSensors_t().get_from(m);
                SENSORS_LegJointSensors_function_t funct((void (SENSORS_LegJointSensors_WBFunctor_T::*)(guWhiteboard::WBTypes, guWhiteboard::SENSORS_LegJointSensors &))WBFunctor<SENSORS_LegJointSensors_WBFunctor_T >::get_s_func_ptr());
                (WBFunctor<SENSORS_LegJointSensors_WBFunctor_T >::fObject->*funct)(WBFunctor<SENSORS_LegJointSensors_WBFunctor_T >::type_enum, result);
        }
        
        typedef void (SENSORS_LegJointSensors_WBFunctor_T::*SENSORS_LegJointSensors_function_t) (guWhiteboard::WBTypes, guWhiteboard::SENSORS_LegJointSensors &);

        static WBFunctorBase *bind(SENSORS_LegJointSensors_WBFunctor_T *obj, void (SENSORS_LegJointSensors_WBFunctor_T::*f)(guWhiteboard::WBTypes, guWhiteboard::SENSORS_LegJointSensors &), guWhiteboard::WBTypes t) { return new SENSORS_LegJointSensors_WBFunctor<SENSORS_LegJointSensors_WBFunctor_T >(obj, f, t); }
};

#endif //SENSORS_LegJointSensors_DEFINED


#ifdef SENSORS_TorsoJointSensors_DEFINED
template <typename SENSORS_TorsoJointSensors_WBFunctor_T >
class SENSORS_TorsoJointSensors_WBFunctor: public WBFunctor<SENSORS_TorsoJointSensors_WBFunctor_T > 
{
public:
        SENSORS_TorsoJointSensors_WBFunctor(SENSORS_TorsoJointSensors_WBFunctor_T* obj, void (SENSORS_TorsoJointSensors_WBFunctor_T::*pFunc) (guWhiteboard::WBTypes, guWhiteboard::SENSORS_TorsoJointSensors &), guWhiteboard::WBTypes t): WBFunctor<SENSORS_TorsoJointSensors_WBFunctor_T >(obj, (void (SENSORS_TorsoJointSensors_WBFunctor_T::*) (guWhiteboard::WBTypes, gu_simple_message*))pFunc, t) { }

        void call(gu_simple_message *m)
        {
                guWhiteboard::SENSORS_TorsoJointSensors result = guWhiteboard::SENSORS_TorsoJointSensors_t().get_from(m);
                SENSORS_TorsoJointSensors_function_t funct((void (SENSORS_TorsoJointSensors_WBFunctor_T::*)(guWhiteboard::WBTypes, guWhiteboard::SENSORS_TorsoJointSensors &))WBFunctor<SENSORS_TorsoJointSensors_WBFunctor_T >::get_s_func_ptr());
                (WBFunctor<SENSORS_TorsoJointSensors_WBFunctor_T >::fObject->*funct)(WBFunctor<SENSORS_TorsoJointSensors_WBFunctor_T >::type_enum, result);
        }
        
        typedef void (SENSORS_TorsoJointSensors_WBFunctor_T::*SENSORS_TorsoJointSensors_function_t) (guWhiteboard::WBTypes, guWhiteboard::SENSORS_TorsoJointSensors &);

        static WBFunctorBase *bind(SENSORS_TorsoJointSensors_WBFunctor_T *obj, void (SENSORS_TorsoJointSensors_WBFunctor_T::*f)(guWhiteboard::WBTypes, guWhiteboard::SENSORS_TorsoJointSensors &), guWhiteboard::WBTypes t) { return new SENSORS_TorsoJointSensors_WBFunctor<SENSORS_TorsoJointSensors_WBFunctor_T >(obj, f, t); }
};

#endif //SENSORS_TorsoJointSensors_DEFINED


#ifdef SENSORS_SonarSensors_DEFINED
template <typename SENSORS_SonarSensors_WBFunctor_T >
class SENSORS_SonarSensors_WBFunctor: public WBFunctor<SENSORS_SonarSensors_WBFunctor_T > 
{
public:
        SENSORS_SonarSensors_WBFunctor(SENSORS_SonarSensors_WBFunctor_T* obj, void (SENSORS_SonarSensors_WBFunctor_T::*pFunc) (guWhiteboard::WBTypes, guWhiteboard::SENSORS_SonarSensors &), guWhiteboard::WBTypes t): WBFunctor<SENSORS_SonarSensors_WBFunctor_T >(obj, (void (SENSORS_SonarSensors_WBFunctor_T::*) (guWhiteboard::WBTypes, gu_simple_message*))pFunc, t) { }

        void call(gu_simple_message *m)
        {
                guWhiteboard::SENSORS_SonarSensors result = guWhiteboard::SENSORS_SonarSensors_t().get_from(m);
                SENSORS_SonarSensors_function_t funct((void (SENSORS_SonarSensors_WBFunctor_T::*)(guWhiteboard::WBTypes, guWhiteboard::SENSORS_SonarSensors &))WBFunctor<SENSORS_SonarSensors_WBFunctor_T >::get_s_func_ptr());
                (WBFunctor<SENSORS_SonarSensors_WBFunctor_T >::fObject->*funct)(WBFunctor<SENSORS_SonarSensors_WBFunctor_T >::type_enum, result);
        }
        
        typedef void (SENSORS_SonarSensors_WBFunctor_T::*SENSORS_SonarSensors_function_t) (guWhiteboard::WBTypes, guWhiteboard::SENSORS_SonarSensors &);

        static WBFunctorBase *bind(SENSORS_SonarSensors_WBFunctor_T *obj, void (SENSORS_SonarSensors_WBFunctor_T::*f)(guWhiteboard::WBTypes, guWhiteboard::SENSORS_SonarSensors &), guWhiteboard::WBTypes t) { return new SENSORS_SonarSensors_WBFunctor<SENSORS_SonarSensors_WBFunctor_T >(obj, f, t); }
};

#endif //SENSORS_SonarSensors_DEFINED


#ifdef FSMControlStatus_DEFINED
template <typename FSM_Control_WBFunctor_T >
class FSM_Control_WBFunctor: public WBFunctor<FSM_Control_WBFunctor_T > 
{
public:
        FSM_Control_WBFunctor(FSM_Control_WBFunctor_T* obj, void (FSM_Control_WBFunctor_T::*pFunc) (guWhiteboard::WBTypes, guWhiteboard::FSMControlStatus &), guWhiteboard::WBTypes t): WBFunctor<FSM_Control_WBFunctor_T >(obj, (void (FSM_Control_WBFunctor_T::*) (guWhiteboard::WBTypes, gu_simple_message*))pFunc, t) { }

        void call(gu_simple_message *m)
        {
                guWhiteboard::FSMControlStatus result = guWhiteboard::FSM_Control_t().get_from(m);
                FSM_Control_function_t funct((void (FSM_Control_WBFunctor_T::*)(guWhiteboard::WBTypes, guWhiteboard::FSMControlStatus &))WBFunctor<FSM_Control_WBFunctor_T >::get_s_func_ptr());
                (WBFunctor<FSM_Control_WBFunctor_T >::fObject->*funct)(WBFunctor<FSM_Control_WBFunctor_T >::type_enum, result);
        }
        
        typedef void (FSM_Control_WBFunctor_T::*FSM_Control_function_t) (guWhiteboard::WBTypes, guWhiteboard::FSMControlStatus &);

        static WBFunctorBase *bind(FSM_Control_WBFunctor_T *obj, void (FSM_Control_WBFunctor_T::*f)(guWhiteboard::WBTypes, guWhiteboard::FSMControlStatus &), guWhiteboard::WBTypes t) { return new FSM_Control_WBFunctor<FSM_Control_WBFunctor_T >(obj, f, t); }
};

#endif //FSMControlStatus_DEFINED


#ifdef FSMControlStatus_DEFINED
template <typename FSM_Status_WBFunctor_T >
class FSM_Status_WBFunctor: public WBFunctor<FSM_Status_WBFunctor_T > 
{
public:
        FSM_Status_WBFunctor(FSM_Status_WBFunctor_T* obj, void (FSM_Status_WBFunctor_T::*pFunc) (guWhiteboard::WBTypes, guWhiteboard::FSMControlStatus &), guWhiteboard::WBTypes t): WBFunctor<FSM_Status_WBFunctor_T >(obj, (void (FSM_Status_WBFunctor_T::*) (guWhiteboard::WBTypes, gu_simple_message*))pFunc, t) { }

        void call(gu_simple_message *m)
        {
                guWhiteboard::FSMControlStatus result = guWhiteboard::FSM_Status_t().get_from(m);
                FSM_Status_function_t funct((void (FSM_Status_WBFunctor_T::*)(guWhiteboard::WBTypes, guWhiteboard::FSMControlStatus &))WBFunctor<FSM_Status_WBFunctor_T >::get_s_func_ptr());
                (WBFunctor<FSM_Status_WBFunctor_T >::fObject->*funct)(WBFunctor<FSM_Status_WBFunctor_T >::type_enum, result);
        }
        
        typedef void (FSM_Status_WBFunctor_T::*FSM_Status_function_t) (guWhiteboard::WBTypes, guWhiteboard::FSMControlStatus &);

        static WBFunctorBase *bind(FSM_Status_WBFunctor_T *obj, void (FSM_Status_WBFunctor_T::*f)(guWhiteboard::WBTypes, guWhiteboard::FSMControlStatus &), guWhiteboard::WBTypes t) { return new FSM_Status_WBFunctor<FSM_Status_WBFunctor_T >(obj, f, t); }
};

#endif //FSMControlStatus_DEFINED


#ifdef FSMNames_DEFINED
template <typename FSM_Names_WBFunctor_T >
class FSM_Names_WBFunctor: public WBFunctor<FSM_Names_WBFunctor_T > 
{
public:
        FSM_Names_WBFunctor(FSM_Names_WBFunctor_T* obj, void (FSM_Names_WBFunctor_T::*pFunc) (guWhiteboard::WBTypes, guWhiteboard::FSMNames &), guWhiteboard::WBTypes t): WBFunctor<FSM_Names_WBFunctor_T >(obj, (void (FSM_Names_WBFunctor_T::*) (guWhiteboard::WBTypes, gu_simple_message*))pFunc, t) { }

        void call(gu_simple_message *m)
        {
                guWhiteboard::FSMNames result = guWhiteboard::FSM_Names_t().get_from(m);
                FSM_Names_function_t funct((void (FSM_Names_WBFunctor_T::*)(guWhiteboard::WBTypes, guWhiteboard::FSMNames &))WBFunctor<FSM_Names_WBFunctor_T >::get_s_func_ptr());
                (WBFunctor<FSM_Names_WBFunctor_T >::fObject->*funct)(WBFunctor<FSM_Names_WBFunctor_T >::type_enum, result);
        }
        
        typedef void (FSM_Names_WBFunctor_T::*FSM_Names_function_t) (guWhiteboard::WBTypes, guWhiteboard::FSMNames &);

        static WBFunctorBase *bind(FSM_Names_WBFunctor_T *obj, void (FSM_Names_WBFunctor_T::*f)(guWhiteboard::WBTypes, guWhiteboard::FSMNames &), guWhiteboard::WBTypes t) { return new FSM_Names_WBFunctor<FSM_Names_WBFunctor_T >(obj, f, t); }
};

#endif //FSMNames_DEFINED


