#ifndef STR_H
#define STR_H

#include <stddef.h> 

size_t Str_getLength(const char pcSrc[]);

char *Str_copy(char dest[], const char source[]);

char *Str_concat(char dest[], const char source[]);

int Str_compare(const char str1[], const char str2[]);

char *Str_search(char str[], const char subStr[]);

#endif