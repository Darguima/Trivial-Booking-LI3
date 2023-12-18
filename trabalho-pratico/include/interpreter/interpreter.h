//! @file
#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <catalogs_creator/catalogs_creator.h>

/**
 * @brief Interprets a batch line command and performs associated queries
 *
 * This function interprets a batch line command by tokenizing it and executing
 * the associated query based on the provided command number and catalogs.
 *
 * @param batch_line The input batch line command to be interpreted
 * @param command_number The number associated with the command
 * @param CATALOGS The catalogs struct created by the function `catalogs_creator()`
 * @return int Returns 0 upon successful interpretation and execution of queries
 */

int interpreter(char* batch_line, int command_number, Catalogs CATALOGS);

#endif