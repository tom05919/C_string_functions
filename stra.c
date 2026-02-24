/*This is the function inplementation fo the header file 
str.h*/

#include "str.h"
#include <stddef.h>
#include <assert.h>

/*This function takes in a char array and returns the 
length of that char array*/
size_t Str_getLength(const char pcSrc[]) {
    assert(pcSrc != NULL);
    
    size_t strLength = 0;
    while (pcSrc[strLength] != '\0') {
        strLength++;
    }
    return strLength;
}

/*This funciton takes in two strings and copies source to dest*/
char *Str_copy(char dest[], const char source[]) {
    assert(dest != NULL);
    assert(source != NULL);

    int strLength = 0;
    while (source[strLength] != '\0') {
        dest[strLength] = source[strLength];
        strLength++;
    }
    dest[strLength] = '\0';
    return dest;
}

/*This function takes in two strings and concats 
source to the end of dest*/
char *Str_concat(char dest[], const char source[]) {
    assert(dest != NULL);
    assert(source != NULL);

    int destLength = Str_getLength(dest);
    int length = 0;

    while (source[length] != '\0') {
        dest[destLength + length] = source[length];
        length++;
    }
    dest[destLength + length] = '\0';
    return dest;
}

/*This funciton takes in two strings and returns 
either int > 0 or int < 0 if the two strigns are not
exactly the same, and returns 0 if they are the same*/
int Str_compare(const char str1[], const char str2[]) {
    assert(str1 != NULL);
    assert(str2 != NULL);

    int i;
    int length = Str_getLength(str1) + 1; /*added 1 to cover edge case that str1 = '\0'*/
    for (i = 0; i < length; i++) {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
    }
    return 0;
}

/*This function searches for the first occurance of a 
substring in str and returns the location of the start of 
the substring*/
char *Str_search(const char str[], const char subStr[]) {
    assert(str != NULL);
    assert(subStr != NULL);

    const char *start;
    int length = Str_getLength(str);
    int subLength = Str_getLength(subStr);
    int i;
    int j = 0;
    if (length < subLength){
        return NULL;
    } else if (subLength == 0) {
        return &str[0];
    }
    
    for (i = 0; i < length; i++) {
        start = &str[i];
        if (str[i + j] == subStr[j]) {
            while ((i + j) < length && j < subLength && 
            (str[i + j] == subStr[j])) {
                /*increments all pointers until they 
                reach the end or they dont equal*/
                j++;
            }
            if (j == subLength) {
                /*returns only if we managed to get 
                through the entire substring*/
                return start;
            } else {
                j = 0;
            }
        }
    }
    return NULL;
}