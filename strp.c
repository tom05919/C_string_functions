/*This is the function inplementation fo the header file 
str.h*/

#include "str.h"
#include <stddef.h>
#include <assert.h>

/*This function takes in a char array and returns the 
length of that char array*/
size_t Str_getLength(const char *pcSrc) {
    assert(pcSrc != NULL);
    
    size_t length = 0;
    while (*pcSrc != '\0') {
        length++;
        pcSrc++;
    }
    return length;
}

/*This funciton takes in two strings and copies source to dest*/
char *Str_copy(char *dest, const char *source) {
    assert(dest != NULL);
    assert(source != NULL);

    int i = 0;
    while(*source != '\0') {
        *dest = *source;
        dest++;
        source++;
        i++;
    }
    *dest = '\0';
    return dest - i;
}

/*This funciton takes in two strings and returns 
either int > 0 or int < 0 if the two strigns are not
exactly the same, and returns 0 if they are the same*/
char *Str_concat(char *dest, const char *source) {
    assert(dest != NULL);
    assert(source != NULL);

    int i = 0;
    int length = Str_getLength(dest);
    dest += length;
    while (*source != '\0') {
        *dest = *source;
        dest++;
        source++;
        i++;
    }
    *dest = '\0';
    return dest - i - length;
}

/*This funciton takes in two strings and returns 
either int > 0 or int < 0 if the two strigns are not
exactly the same, and returns 0 if they are the same*/
int Str_compare(const char *str1, const char *str2) {
    assert(str1 != NULL);
    assert(str2 != NULL);

    int length = Str_getLength(str1) + 1; /*added 1 to cover edge case that str1 = '\0'*/
    int i;

    for (i = 0; i < length; i++) {
        if (*str1 != *str2) {
            return *str1 - *str2;
        }
        str1++;
        str2++;
    }
    return 0;
}

/*This function searches for the first occurance of a 
substring in str and returns the location of the start of 
the substring*/
char *Str_search(const char *str, const char *subStr) {
    assert(str != NULL);
    assert(subStr != NULL);

    char *start;
    int length = Str_getLength(str);
    int subLength = Str_getLength(subStr);
    int i;
    int j = 0;
    if (length < subLength){
        return NULL;
    } else if (subLength == 0) {
        return str;
    }

    for (i = 0; i < length; i++) {
        start = str;
        if (*str == *subStr) {
            while(*str != '\0' && *subStr != '\0' 
            && *str == *subStr) {
                /*increments all pointers until they 
                reach the end or they dont equal*/
                j++;
                str++;
                subStr++;
            }
            if (j == subLength) {
                /*returns only if we managed to get 
                through the entire substring*/
                return start;
            } else {
                subStr -= j;
                str -= j;
                j = 0;
            }
        }
        str++;
    }
    return NULL;
}