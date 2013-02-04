/*
 *  guwhiteboardtypegenerator.c
 *
 *  Created by Carl Lusty in 2013.
 *  Copyright (c) 2013 Carl Lusty
 *  All rights reserved.
 */

#include <string.h>
#include <vector>
#include <iostream>
#include <map>
#include <fstream>


using namespace std;

static char *include_str = "\
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
#include \"create_map.h\" //std::map template creation shorthand        \n\
                                                                        \n\
";

static char *opening_namespace = "                                      \n\
namespace guWhiteboard                                                  \n\
{                                                                       \n\
";

static char *opening_enum = "        typedef enum wb_types              \n\
        {                                                               \n\
";

static char *closing_enum = "        } WBTypes;\n\n";

static char *opening_map_definition = "        static std::map<int, int> mymap = create_map<int, int >";

static char *closing_map_definition = ";\n\n";

static char *opening_string_array_definition = "        const std::string WBTypes_stringValues[] = {    \n\
";

static char *closing_string_array_definition = "        };\n";

static char *closing_namespace = "}\n\n";

static char *end_include_str = "#endif // _GUGENERICWHITEBOARDOBJECT_H_                                 \n\
";

int main(int argc, char **argv)
{
        fstream list_h;
        fstream list_c;
        ofstream output_file;
        list_h.open ("guwhiteboardtypelist.h");
        list_c.open ("guwhiteboardtypelist.c");
        output_file.open ("guwhiteboardtypelist_generated.h");

        if(!list_h.is_open() || !list_c.is_open() || !output_file.is_open())
        {
                perror("could not open one of the files");
                return EXIT_FAILURE;
        }

        vector<char> header;
        vector<char> implementation;
        char temp;
        
        while(list_h >> temp)
        {
                header.push_back(temp);
        }
        while(list_c >> temp)
        {
                implementation.push_back(temp);
        }
        
        char *h_file_str = (char *)&header[0];
        char *c_file_str = (char *)&implementation[0];
        fprintf(stderr, "%s", h_file_str);
        fprintf(stderr, "\n\n");
        fprintf(stderr, "%s", c_file_str);
        
        
        output_file << include_str;
        output_file << opening_namespace;
        output_file << opening_enum;
        //enum
        
        output_file << closing_enum;
        output_file << opening_map_definition;
        //map
        
        output_file << closing_map_definition;
        output_file << opening_string_array_definition;
        //string array
        
        output_file << closing_string_array_definition;
        output_file << closing_namespace;
        output_file << end_include_str;
        
        
        
        list_h.close();
        list_c.close();
}
