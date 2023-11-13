#ifndef PARSER_H
#define PARSER_H

#include <datatypes/datatypes.h>

void file_parser(FILE* file,
                 Catalogs CATALOGS,
                 schema_name schema_name,
                 char* dataset_folder_path);

#endif