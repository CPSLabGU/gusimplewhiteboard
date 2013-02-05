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
#include "gusimplewhiteboard.h"

using namespace std;

static char *include_str = (char *)"\
/*                                                                      \n\
 *  guwhiteboardtypelist_generated.h                                    \n\
 *                                                                      \n\
 *  Created by Carl Lusty in 2013.                                      \n\
 *  Copyright (c) 2013 Carl Lusty                                       \n\
 *  All rights reserved.                                                \n\
 */                                                                     \n\
                                                                        \n\
                                                                        \n\
#ifndef _GUGENERICWHITEBOARDOBJECT_H_                                   \n\
#define _GUGENERICWHITEBOARDOBJECT_H_                                   \n\
                                                                        \n\
#include \"guwhiteboardtypegenerator/create_map.h\" //std::map template creation shorthand        \n\
                                                                        \n\
";

static char *opening_namespace = (char *)"                              \n\
namespace guWhiteboard                                                  \n\
{                                                                       \n\
";

static char *opening_enum = (char *)"        typedef enum wb_types      \n\
        {                                                               \n\
";

static char *closing_enum = (char *)"        } WBTypes;\n\n";

static char *opening_map_definition = (char *)"        static std::map<int, int> type_map = create_map<int, int>";

static char *closing_map_definition = (char *)";\n\n";

static char *opening_string_array_definition = (char *)"        const std::string WBTypes_stringValues[] = {    \n";

static char *closing_string_array_definition = (char *)"        };      \n";

static char *closing_namespace = (char *)"}\n\n";

static char *end_include_str = (char *)"#endif // _GUGENERICWHITEBOARDOBJECT_H_                                 \n\
";

int main(int argc, char **argv)
{
        gu_simple_whiteboard_descriptor *_wbd;
        char *name = (char *)GSW_DEFAULT_NAME;

        if (!(_wbd = gsw_new_numbered_whiteboard(name, 0)))
        {
                cerr << "Unable to create whiteboard ";
                exit(EXIT_FAILURE);
        }
        
        
        ifstream list_h;
        ifstream list_c;
        ofstream output_file;
        list_h.open ("../guwhiteboardtypelist.h");
        list_c.open ("../guwhiteboardtypelist.c");
        output_file.open ("../guwhiteboardtypelist_generated.h");

        if(!list_h.is_open() || !list_c.is_open() || !output_file.is_open())
        {
                //just incase someone runs it from inside the build directory
                list_h.open ("../../guwhiteboardtypelist.h");
                list_c.open ("../../guwhiteboardtypelist.c");
                output_file.open ("../../guwhiteboardtypelist_generated.h");
                
                if(!list_h.is_open() || !list_c.is_open() || !output_file.is_open())
                {
                        perror("could not open one of the files");
                        return EXIT_FAILURE;
                }
        }

        std::stringstream h_file_stream;
        std::stringstream c_file_stream;
        h_file_stream << list_h.rdbuf();
        c_file_stream << list_c.rdbuf();
        
        std::string h_file_str = h_file_stream.str();
        std::string c_file_str = c_file_stream.str();
        
        std::string header_token = std::string("extern const char *");

        std::vector<std::string> const_names;
        int pos = 0;
        while((pos = h_file_str.find(header_token, pos+header_token.length())) != string::npos)
        {
                int start_p = pos+header_token.length();
                int end_p = h_file_str.find(";", start_p);
                const_names.push_back(h_file_str.substr(start_p, end_p-start_p));
        }
        
        std::string start_c_token = std::string("const char *");
        std::vector<std::string> const_values;
        
        for (int i = 0; i < const_names.size(); i++) {
                std::string full_c_token = start_c_token;
                full_c_token.append(const_names[i]);
                
                if((pos = c_file_str.find(full_c_token)) == string::npos)
                {
                        fprintf(stderr, "parsing issue, could not find definition to match the type const: '%s', exiting...\n", (char *)const_names[i].c_str());
                        exit(EXIT_FAILURE);
                }
                
                int start_p = c_file_str.find("\"", pos+full_c_token.length())+1;
                int end_p = c_file_str.find("\"", start_p);
                const_values.push_back(c_file_str.substr(start_p, end_p-start_p));
        }

        std::map<std::string, int> enum_pairs;  //const name, hash offset
        std::vector<std::string> array_values;  //index in array, index in string array
        std::map<int, int> map_pairs;           //hash offset, index in string array
        
        for (int i = 0; i < const_names.size(); i++)
        {
                std::string type_const_name = const_names[i];
                std::string type_const_value = const_values[i];

                //get hash offset
                int hash_offset = gsw_offset_for_message_type(_wbd, (char *)type_const_value.c_str());
                
                //add to enum
                enum_pairs[type_const_name] = hash_offset;
                
                //string to array
                array_values.push_back(type_const_value);
                
                //add length of array to hash offset in map
                map_pairs[hash_offset] = array_values.size()-1;
        }
         
        
        output_file << include_str;
        
        //print current date
        time_t rawtime;
        struct tm * timeinfo;
        time ( &rawtime );
        timeinfo = localtime ( &rawtime );
        output_file << "//Generated on: " << asctime (timeinfo);
        
        
        output_file << opening_namespace;
        output_file << opening_enum;
        //enum
        std::map<std::string,int>::iterator enum_it;
        
        for (std::map<std::string,int>::iterator enum_it = enum_pairs.begin(); enum_it != enum_pairs.end(); ++enum_it)
        {
                output_file << "                " << (char *)enum_it->first.c_str() << " = " << enum_it->second;
                ++enum_it != enum_pairs.end() ? output_file << ",\n" : output_file << "\n";
                enum_it--;
        }
        
        output_file << closing_enum;
        output_file << opening_map_definition;
        //map
        std::map<int,int>::iterator map_it;
        
        for (std::map<int,int>::iterator map_it = map_pairs.begin(); map_it != map_pairs.end(); ++map_it)
        {
                output_file << "(" << map_it->first << "," << map_it->second << ")";
        }
        
        output_file << closing_map_definition;
        output_file << opening_string_array_definition;
        //string array
        for (int i = 0; i < array_values.size(); i++)
        {//                "US/Left/Sensor/Value",
                output_file << "                \"" << (char *)array_values[i].c_str();
                i+1 != array_values.size() ? output_file << "\",\n" : output_file << "\"\n";
        }
        
        output_file << closing_string_array_definition;
        output_file << closing_namespace;
        output_file << end_include_str;
        
        
        list_h.close();
        list_c.close();
}
