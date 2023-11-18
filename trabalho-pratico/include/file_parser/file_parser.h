//! @file
#ifndef PARSER_H
#define PARSER_H

#include <datatypes/datatypes.h>

/**
 * @brief Parses a line by splitting it based on a delimiter and returns an array of elements
 *
 * Parses the input line by splitting it into elements using ';' as a delimiter and stores
 * the elements in an array of strings.
 *
 * @param line The input line to be parsed
 * @param dataset_columns_amount The number of columns expected in the dataset
 * @return char** Returns an array of strings containing the parsed elements
 */
char** parse_line(char* line, int dataset_columns_amount);

/**
 * @brief Parses a file according to a specified schema and updates the catalogs
 *
 * Parses the given file according to the specified schema (e.g., USERS, FLIGHTS, etc.),
 * calling the respective value parsers and handling any parsing errors encountered.
 *
 * @param file The file pointer to be parsed
 * @param CATALOGS The catalogs struct containing hash tables
 * @param schema_name_ The schema name indicating the type of data being parsed
 * @param dataset_folder_path The path for the dataset
 */
void file_parser(FILE* file, Catalogs CATALOGS, schema_name schema_name, char* dataset_folder_path);

#endif