#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>

char **parse_line(char *line, int max_size);
void file_parser(FILE *file, int max_size) ;

#endif