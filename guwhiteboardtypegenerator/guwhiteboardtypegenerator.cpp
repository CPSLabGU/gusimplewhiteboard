/*
 *  guwhiteboardtypegenerator.c
 *
 *  Created by Carl Lusty in 2013.
 *  Copyright (c) 2013 Carl Lusty
 *  All rights reserved.
 */

#include <string.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <time.h>

//#define DDEBUG

using namespace std;

static char *include_str = (char *)"\
/**                                                                     \n\
 *  /file guwhiteboardtypelist_generated.h                              \n\
 *                                                                      \n\
 *  Created by Carl Lusty in 2013.                                      \n\
 *  Copyright (c) 2013 Carl Lusty                                       \n\
 *  All rights reserved.                                                \n\
 */                                                                     \n\
                                                                        \n\
                                                                        \n\
#ifndef _GUWHITEBOARD_TYPELIST_H_                                       \n\
#define _GUWHITEBOARD_TYPELIST_H_                                       \n\
                                                                        \n\
#include \"gugenericwhiteboardobject.h\"                                \n\
                                                                        \n\
                                                                        \n\
";

static char *include_str_c = (char *)"\
/**                                                                     \n\
 *  /file guwhiteboardtypelist_c_generated.h                            \n\
 *                                                                      \n\
 *  Created by Carl Lusty in 2013.                                      \n\
 *  Copyright (c) 2013 Carl Lusty                                       \n\
 *  All rights reserved.                                                \n\
 */                                                                     \n\
\n\
\n\
#ifndef _GUWHITEBOARD_TYPELIST_C_H_                                     \n\
#define _GUWHITEBOARD_TYPELIST_C_H_                                     \n\
\n\
\n\
#define WANT_WB_STRINGS\n\
";

static char *include_str_c_typestrings = (char *)"\
/**                                                                     \n\
 *  /file guwhiteboardtypelist_c_typestrings_generated.c                \n\
 *                                                                      \n\
 *  Created by Carl Lusty in 2013.                                      \n\
 *  Copyright (c) 2013 Carl Lusty                                       \n\
 *  All rights reserved.                                                \n\
 */                                                                     \n\
\n\
\n\
";

static char *include_wbfunctor_extension = (char *)"\
/**                                                                     \n\
 *  /file WBFunctor_types_generated.h                                   \n\
 *                                                                      \n\
 *  Created by Carl Lusty in 2013.                                      \n\
 *  Copyright (c) 2013 Carl Lusty                                       \n\
 *  All rights reserved.                                                \n\
 */                                                                     \n\
\n\
\n\
";

static char *opening_namespace = (char *)"                              \n\
namespace guWhiteboard                                                  \n\
{                                                                       \n\
                                                                        \n\
extern \"C\"                                                            \n\
{                                                                       \n\
#include \"guwhiteboardtypelist_c_generated.h\"                         \n\
}                                                                       \n\
                                                                        \n\
";

static char *opening_enum = (char *)"        typedef enum wb_types      \n\
        {                                                               \n\
";

static char *closing_enum = (char *)"        } WBTypes;\n\n";

static char *extern_for_string_array = (char *)"        extern const char *WBTypes_stringValues[];\n";

static char *opening_string_array_definition = (char *)"const char *WBTypes_stringValues[] = \n{\n";

static char *closing_string_array_definition = (char *)"};      \n\n";

static char *closing_namespace = (char *)"}\n\n";

static char *end_include_str = (char *)"#endif                          \n\
";

enum ClassType {
	None = 0,
	POD_Class,
	Custom_Class
	};

struct gu_type_info {
	ClassType class_info;
	std::string class_name;
	std::string type_const_name;
	std::string type_name;
	std::string comment;
};

int main()
{
	ifstream tsl_file;
        ofstream output_file;
        ofstream output_c_file;
        ofstream output_string_array_c_file;
        ofstream output_functor_templates;
	
        tsl_file.open ("../guwhiteboardtypelist.tsl");
        output_file.open ("../guwhiteboardtypelist_generated.h");
        output_c_file.open ("../guwhiteboardtypelist_c_generated.h");
        output_string_array_c_file.open ("../guwhiteboardtypelist_c_typestrings_generated.c");
        output_functor_templates.open ("../WBFunctor_types_generated.h");
	
        if(!tsl_file.is_open() || !output_file.is_open() || !output_c_file.is_open() || !output_string_array_c_file.is_open() || !output_functor_templates.is_open())
        {
                //just incase someone runs it from inside the build directory
                tsl_file.open ("../../guwhiteboardtypelist.tsl");
                output_file.open ("../../guwhiteboardtypelist_generated.h");
		output_c_file.open ("../../guwhiteboardtypelist_c_generated.h");
                output_string_array_c_file.open ("../../guwhiteboardtypelist_c_typestrings_generated.c");
                output_functor_templates.open ("../../WBFunctor_types_generated.h");
                
                if(!tsl_file.is_open() || !output_file.is_open() || !output_c_file.is_open() || !output_string_array_c_file.is_open() || !output_functor_templates.is_open())
                {
                        perror("could not open one of the files");
                        return EXIT_FAILURE;
                }
        }

        std::stringstream tsl_file_stream;
        tsl_file_stream << tsl_file.rdbuf();
        
        std::string tsl_file_str = tsl_file_stream.str();
        
        std::string header_token = std::string("\n");

        std::vector<gu_type_info> types;
        int pos = 0;
        do
        {
                int start_p = 0;
                if(pos > 0)
                        start_p = pos+(int)header_token.length();
                
                int end_p = (int)tsl_file_str.find("\n", start_p);
                pos = end_p;

		std::string type_line = tsl_file_str.substr(start_p, end_p-start_p);
                if((int)type_line.size() == 0)
                        break;

		std::string line_token = std::string(",");
		int line_pos = 0;
		std::vector<std::string> elements;
                
                for (int i = 0; i < 4; i++)
                {
                        int start = line_pos;
			int end = (int)type_line.find(line_token, start);
                        
                        line_pos = end+(int)line_token.length();

                        std::string type_info_element;
                        if(i == 3) //comment, just give me the rest of the string
                                type_info_element = type_line.substr(start, type_line.length()-start);
                        else
                                type_info_element = type_line.substr(start, end-start);
                        
                        int start_non_whitespace = (int)type_info_element.find_first_not_of(' ');
                        if(start_non_whitespace != (int)std::string::npos)
                                type_info_element.erase(0, start_non_whitespace);
                        
                        elements.push_back(type_info_element);
                }
		
		if((int)elements.size() != 4)
		{
			fprintf(stderr, "guwhiteboardtypegenerator: Parsing issue found, take a look at line: %d\nexiting...", (int)types.size());
			exit(1);
		}

		struct gu_type_info info;
		//Splitting logic from parsing
		for (int i = 0; i < (int)elements.size(); i++)
		{
			switch (i) {
				case 1:
				{
					info.type_const_name = elements.at(i);
#ifdef DDEBUG
					fprintf(stderr, "const:\t'%s'\n", (char *)info.type_const_name.c_str());
#endif
					break;
				}
				case 2:
				{
					info.type_name = elements.at(i).substr(1, elements.at(i).length()-2); //substr to remove the quotes
#ifdef DDEBUG
					fprintf(stderr, "value:\t'%s'\n", (char *)info.type_name.c_str());
#endif
					break;
				}
				case 0:
					if((int)elements.at(i).size() == 0)
					{
                                                //warning if no type is given, however allow it for now.
						info.class_info = None;
					}
					else
					{
						if((int)elements.at(i).find("class:") != (int)string::npos) //custom class?
						{
							info.class_info = Custom_Class;
							info.class_name = elements.at(i).substr(std::string("class:").length());
						}
						else
						{
							info.class_info = POD_Class;
							info.class_name = elements.at(i);
						}
					}
#ifdef DDEBUG
					switch (info.class_info) {
						case None:
							fprintf(stderr, "class info:\tNone, just a WB Type, no class\n");
							break;
						case POD_Class:
							fprintf(stderr, "class info:\tPOD_Class, type: %s\n", (char *)info.class_name.c_str());
							break;
						case Custom_Class:
							fprintf(stderr, "class info:\tCustom_Class, class name: %s\n", (char *)info.class_name.c_str());
							break;
						default:
							break;
					}
#endif
					break;
				case 3:
				{
					info.comment = elements.at(i);
#ifdef DDEBUG
					fprintf(stderr, "comments:\t'%s'\n", (char *)info.comment.c_str());
#endif
					break;
				}
				default:
					break;
			}
		}
		types.push_back(info);
	} while((pos = (int)tsl_file_str.find(header_token, pos)) != (int)string::npos);
		
	
	//output to file
        output_file << include_str;
        output_c_file << include_str_c;
        output_string_array_c_file << include_str_c_typestrings;
        output_functor_templates << include_wbfunctor_extension;

        
        output_c_file << "\n#define GSW_NUM_TYPES_DEFINED " << types.size() << "\n\n";
        output_c_file << "#if GSW_NUM_TYPES_DEFINED > GSW_NUM_RESERVED\n";
        output_c_file << "#error *** Error: gusimplewhiteboard: The number of defined types exceeds the total number of reserved types allowed. Increase GSW_NUM_RESERVED to solve this.\n";
        output_c_file << "#endif\n";      
        
        //print current date
        time_t rawtime;
        struct tm * timeinfo;
        time ( &rawtime );
        timeinfo = localtime ( &rawtime );
	//get user name
	char * pPath;
	pPath = getenv ("USER");
	
		
	
        output_file << "//Generated on: " << asctime (timeinfo) << "//Generated by user: ";
        output_c_file << "//Generated on: " << asctime (timeinfo) << "//Generated by user: ";
        output_string_array_c_file << "//Generated on: " << asctime (timeinfo) << "//Generated by user: ";
        output_functor_templates << "//Generated on: " << asctime (timeinfo) << "//Generated by user: ";
	if (pPath!=NULL)
	{
		output_file << pPath << "\n";
		output_string_array_c_file << pPath << "\n\n";
		output_c_file << pPath << "\n\n";
                output_functor_templates << pPath << "\n\n";
	}
	else
	{
		output_file << "unknown\n";
		output_string_array_c_file << "unknown\n\n";
		output_c_file << "unknown\n\n";
                output_functor_templates << "unknown\n\n";
	}

        
        output_file << opening_namespace;
	
		
	
        output_c_file << opening_enum;

        //enum
	for (int i = 0; i < (int)types.size(); i++)
	{
		int hash_offset = i;//gsw_offset_for_message_type(_wbd, (char *)types.at(i).type_name.c_str());
		output_c_file << "                " << (char *)types.at(i).type_const_name.c_str() << "_v = " << hash_offset;
                
                if(i+1 != (int)types.size())
                       output_c_file << ",";
		
		types.at(i).class_info == None ? output_c_file << "\t///<" << (char *)types.at(i).comment.c_str() : output_c_file << "";
		
		output_c_file << "\n";
	}
	
        output_c_file << closing_enum;
        output_c_file << extern_for_string_array;
        output_string_array_c_file << opening_string_array_definition;
        
        
	//string array
	for (int i = 0; i < (int)types.size(); i++)
	{
		output_string_array_c_file << "        \"" << (char *)types.at(i).type_name.c_str();
                i+1 != (int)types.size() ? output_string_array_c_file << "\",\n" : output_string_array_c_file << "\"\n";
	}

        output_string_array_c_file << closing_string_array_definition;
	
	//type classes
	for (int i = 0; i < (int)types.size(); i++)
	{
		switch (types.at(i).class_info) {
			case None:
				break;
			case POD_Class:
			{
				output_file << "\t///" <<  (char *)types.at(i).comment.c_str()<< "\n        class " << (char *)types.at(i).type_const_name.c_str() << "_t : public generic_whiteboard_object<" << (char *)types.at(i).class_name.c_str() << "> { public: " << (char *)types.at(i).type_const_name.c_str() << "_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<" << (char *)types.at(i).class_name.c_str() << ">(wbd, " << (char *)types.at(i).type_const_name.c_str() << "_v) {} };\n\n";
				break;
			}
			case Custom_Class:
			{
				output_file << "\t///" <<  (char *)types.at(i).comment.c_str()<< "\n        class " << (char *)types.at(i).type_const_name.c_str() << "_t : public generic_whiteboard_object<class " << (char *)types.at(i).class_name.c_str() << "> { public: " << (char *)types.at(i).type_const_name.c_str() << "_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class " << (char *)types.at(i).class_name.c_str() << ">(wbd, " << (char *)types.at(i).type_const_name.c_str() << "_v) {} };\n\n";
				break;
			}
		}
	}
	
	
        output_file << closing_namespace;
        output_file << end_include_str;
        output_c_file << end_include_str;
        
        
        //WBFunctor extension
        
        /*
         template <typename kSpeechOutput_WBFunctor_T>
         class kSpeechOutput_WBFunctor: public WBFunctor<kSpeechOutput_WBFunctor_T>
         {
         public:
         kSpeechOutput_WBFunctor(kSpeechOutput_WBFunctor_T* obj, void (kSpeechOutput_WBFunctor_T::*pFunc) (guWhiteboard::WBTypes, bool &), guWhiteboard::WBTypes t): WBFunctor<kSpeechOutput_WBFunctor_T>(obj, (void (kSpeechOutput_WBFunctor_T::*) (guWhiteboard::WBTypes, gu_simple_message*))pFunc, t) { };
         
         void call(gu_simple_message *m)
         {
         bool result = guWhiteboard::kSpeechOutput_t::get_from(m);
         kSpeechOutput_function_t funct((void (kSpeechOutput_WBFunctor_T::*)(guWhiteboard::WBTypes, bool &))WBFunctor<kSpeechOutput_WBFunctor_T>::get_s_func_ptr());
         (WBFunctor<kSpeechOutput_WBFunctor_T>::fObject->*funct)(WBFunctor<kSpeechOutput_WBFunctor_T>::type_enum, result);
         }
         
         typedef void (kSpeechOutput_WBFunctor_T::*kSpeechOutput_function_t) (guWhiteboard::WBTypes, bool &);
         
         static WBFunctorBase *bind(kSpeechOutput_WBFunctor_T *obj, void (kSpeechOutput_WBFunctor_T::*f)(guWhiteboard::WBTypes, bool &), guWhiteboard::WBTypes t) { return new kSpeechOutput_WBFunctor<kSpeechOutput_WBFunctor_T>(obj, f, t); }
         };
         */

	for (int i = 0; i < (int)types.size(); i++)
	{
                stringstream ss;
                ss << (char *)types.at(i).type_const_name.c_str() << "_WBFunctor";
                std::string class_name = ss.str();
                stringstream ss2;
                ss2 << (char *)types.at(i).type_const_name.c_str() << "_WBFunctor_T";
                std::string type_name = ss2.str();
                
                std::string datatype;
                if(types.at(i).class_info == POD_Class)
                        datatype = types.at(i).class_name;
                else
                        datatype = std::string("guWhiteboard::").append(types.at(i).class_name);
                
		if (types.at(i).class_info != None)
                {
                        if(types.at(i).class_info == Custom_Class)
                                output_functor_templates << "#ifdef " << types.at(i).class_name << "_DEFINED\n";
                        output_functor_templates        << "template <typename " << type_name << ">\n"
                        << "class " << class_name << ": public WBFunctor<" << type_name << "> \n{\n"
                        << "public:\n"
                        << "        " << class_name << "(" << type_name << "* obj, void (" << type_name << "::*pFunc) (guWhiteboard::WBTypes, " << datatype << " &), guWhiteboard::WBTypes t): WBFunctor<" << type_name << ">(obj, (void (" << type_name << "::*) (guWhiteboard::WBTypes, gu_simple_message*))pFunc, t) { };\n\n"
                        << "        void call(gu_simple_message *m)\n"
                        << "        {\n"
                        << "                " << datatype << " result = guWhiteboard::" << types.at(i).type_const_name << "_t().get_from(m);\n"
                        << "                " << types.at(i).type_const_name << "_function_t funct((void (" << type_name << "::*)(guWhiteboard::WBTypes, " << datatype << " &))WBFunctor<" << type_name << ">::get_s_func_ptr());\n"
                        << "                (WBFunctor<" << type_name << ">::fObject->*funct)(WBFunctor<" << type_name << ">::type_enum, result);\n"
                        << "        }\n"
                        << "        \n"
                        << "        typedef void (" << type_name << "::*" << types.at(i).type_const_name << "_function_t) (guWhiteboard::WBTypes, " << datatype << " &);\n\n"
                        << "        static WBFunctorBase *bind(" << type_name << " *obj, void (" << type_name << "::*f)(guWhiteboard::WBTypes, " << datatype << " &), guWhiteboard::WBTypes t) { return new " << class_name << "<" << type_name << ">(obj, f, t); }\n};\n\n";
                        
                        if(types.at(i).class_info == Custom_Class)
                                output_functor_templates << "#endif //" << types.at(i).class_name << "_DEFINED\n";
                        output_functor_templates << "\n\n";
		}
        }
        
        
        tsl_file.close();
        output_file.close();
	output_c_file.close();
        output_functor_templates.close();
}
