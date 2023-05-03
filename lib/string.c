/**
 * Martin Egli
 * 2023-05-03
 * mmlib: sting functions
 */

#include <stddef.h>
#include "string.h"

uint16_t string_find_end_pos(char *str, uint16_t str_size) {
    uint16_t pos;
    for(pos = 0; pos < str_size; pos++) {
        if(str[pos] == STRING_TERMINATION) {
            // found end
            return pos;
        }
    }
    // error, did not find end
    return str_size;
}

uint16_t string_append(char *str, uint16_t str_size, char *str_append) {
    uint16_t pos = string_find_end_pos(str, str_size);
    char c;
    // check if str is valid
    if(str == NULL) {
        // error, invalid
        return str_size;
    }
    // check if str_size is valid
    if(str_size == 0) {
        // error, invalid
        return str_size;
    }
    // check if str_append is valid
    if(str_append == NULL) {
        // error, invalid
        return str_size;
    }

    if(pos == str_size) {
        // error, already at the end, no more space available
        // did not do anything
        return str_size;
    }

    // copy str_append to str, go from pos
    for(; pos < str_size; pos++) {
        if(pos == (str_size - 1)) {
            // this is the end position in str
            str[pos] = STRING_TERMINATION;
            return str_size;
        }
        c = *str_append++;
        str[pos] = c;
        if(c == STRING_TERMINATION) {
            // found end in str_append
            break;
        }
    }
    return pos;
}
