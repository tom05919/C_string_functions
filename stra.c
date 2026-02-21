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
    int length = Str_getLength(str1) + 1;
    for (i = 0; i < length; i++) {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
    }
    return 0;
}

char *Str_search(const char str[], const char subStr[]) {
    const char *start;
    int subStringCount = 0;
    int length = Str_getLength(str);
    int subLength = Str_getLength(subStr);
    int i;
    if (length >= subLength) return NULL;

    for (i = 0; i < length; i++) {
        if (str[i] == subStr[subStringCount]) {
            start = &str[i];
            i++;
            subStringCount++;
            while ((str[i] == subStr[subStringCount]) &&
            i < length && subStringCount < subLength) {
                i++;
                subStringCount++;
            }
            if (subStringCount == subLength && subStr[subStringCount] == '\0') {
                return start;
            } else {
                subStringCount = 0;
            }
        }
    }
    return NULL;
}