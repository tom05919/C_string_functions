/*This header file defines 5 functions
that is identital in usage with the
standard C string functions*/

#ifndef STR_H
#define STR_H

#include <stddef.h> 

/*Takes in a char array pcSrc and returns 
the length (int)*/
size_t Str_getLength(const char pcSrc[]);

/*Takes in two char arrays dest and source.
Copies source to dest and returns dest*/
char *Str_copy(char dest[], const char source[]);

/*akes in two char arrays dest and source.
Concacts source to the end of dest and returns dest*/
char *Str_concat(char dest[], const char source[]);

/*Takes in two char arrays str1 and str2.
Compares the two strings and returns 0 (int) only
when they are identitcal, otherwise it can be 
either > 0 or < 0*/
int Str_compare(const char str1[], const char str2[]);

/*This fucntion takes in two strings str and subStr.
It looks for the first occurance of subStr in str and return
a pointer to that first occurance. Returns NULL otherwise*/
char *Str_search(const char str[], const char subStr[]);

#endif