//! @file
#ifndef BATCH_H
#define BATCH_H

/**
 * @brief Executes a batch of queries from a specified file path
 *
 * Reads queries line by line from a file and interprets each line as a command,
 * executing the associated query using the interpreter function.
 *
 * @param queries_path The file path containing the queries to be executed
 * @param CATALOGS The catalogs struct created by the function `catalogs_creator()`
 * @return int Returns 0 upon successful execution of all queries, -1 if the file cannot be opened
 */

int batch(char* queries_path, Catalogs CATALOGS);

#endif