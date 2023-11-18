//! @file
#ifndef PARSER_H
#define PARSER_H

#include <datatypes/datatypes.h>

/**
 * @brief Parses multiple CSV files and processes each line.
 *
 * This function reads data from multiple CSV files, processes each line, and populates the provided catalog and schema
 * structures accordingly. The CSV files are expected to follow a specific structure defined by the provided schema
 * name.
 *
 * @param file The file pointer to the CSV file to be parsed.
 * @param CATALOGS The catalog structure to store the parsed data.
 * @param schema_name The name of the schema that defines the structure of the CSV file.
 * @param dataset_folder_path The path to the folder containing the CSV files.
 */

void file_parser(FILE* file, Catalogs CATALOGS, schema_name schema_name, char* dataset_folder_path);

#endif