#include "str.h"
#include <stddef.h>
#include <assert.h>

size_t Str_getLength(const char pcSrc[]) {
    size_t strLength = 0;
    assert(pcSrc != NULL);
    while (pcSrc[strLength] != '\0') {
        strLength++;
    }
    return strLength;
}

char *Str_copy(char dest[], const char source[]) {
    int strLength = 0;
    while (source[strLength] != '\0') {
        dest[strLength] = source[strLength];
        strLength++;
    }
    dest[strLength] = '\0';
    return dest;
}

char *Str_concat(char dest[], const char source[]) {
    int destLength = Str_getLength(dest);
    int length = 0;
    while (source[length] != '\0') {
        dest[destLength + length] = source[length];
        length++;
    }
    dest[destLength + length] = '\0';
    return dest;
}

int Str_compare(const char str1[], const char str2[]) {
    int i;
    int length = Str_getLength(str1) + 1; /*added 1 to cover edge case that str1 = '\0'*/
    for (i = 0; i < length; i++) {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
    }
    return 0;
}

char *Str_search(const char str[], const char subStr[]) {
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
                j++;
            }
            if (j == subLength) {
                return start;
            } else {
                j = 0;
            }
        }
    }
    return NULL;
}