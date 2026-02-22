#include "str.h"
#include <stddef.h>
#include <assert.h>

size_t Str_getLength(const char *pcSrc) {
    size_t length = 0;
    while (*pcSrc != '\0') {
        length++;
        pcSrc++;
    }
    return length;
}

char *Str_copy(char *dest, const char *source) {
    while(*source != '\0') {
        *dest = *source;
        dest++;
        source++;
    }
    *dest = '\0';
    return dest;
}

char *Str_concat(char *dest, const char *source) {
    int length = Str_getLength(dest);
    dest += length;
    while (*source != '\0') {
        *dest = *source;
        dest++;
    }
    *dest = '\0';
    return dest;
}

int Str_compare(const char *str1, const char *str2) {
    int length = Str_getLength(str1) + 1;
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

char *Str_search(const char *str, const char *subStr) {
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
            while(*str != '\0' && *subStr != '\0' && *str == *subStr) {
                j++;
                str++;
                subStr++;
            }
            if (j == subLength) {
                return start;
            } else {
                subStr -= j;
                str -= j;
                j = 0;
            }
        }
    }
    return NULL;
}