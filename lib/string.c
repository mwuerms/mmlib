/**
 * Martin Egli
 * 2023-05-03
 * mmlib: sting functions
 */

#include <stddef.h>
#include "string.h"

uint16_t string_clear(char *str, uint16_t str_size) {
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
    str[0] = STRING_TERMINATION;
    return 0;
}

uint16_t string_find_end_pos(char *str, uint16_t str_size) {
    uint16_t pos;
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
    uint16_t pos;
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

    pos = string_find_end_pos(str, str_size);
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

uint16_t string_copy_pos_size(char *str, uint16_t str_size, char *str_copy, uint16_t copy_to_pos, uint16_t copy_size) {
    uint16_t pos;
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
    if(str_copy == NULL) {
        // error, invalid
        return str_size;
    }
    if(copy_to_pos + copy_size >= str_size) {
        // error, invalid
        return str_size;
    }

    pos = string_find_end_pos(str, str_size);
    if(pos == str_size) {
        // error, already at the end, no more space available
        // did not do anything
        return str_size;
    }
    if(copy_to_pos > pos) {
        // it will be outside of pos, but still valid
        // no error, but no effect, so do not copy, do not continue
        return pos;
    }

    // all checks OK, start copy routine
    for(;copy_size; copy_size--) {
        c = *str_copy++;
        str[copy_to_pos++] = c;
    }
    if(c != STRING_TERMINATION) {
        // attention, set new termination
        // check for str_size
        if(copy_to_pos >= str_size) {
            copy_to_pos = str_size -1;
        }
        str[copy_to_pos] = STRING_TERMINATION;
    }
    return copy_to_pos;
}

uint16_t string_delete_from_position(char *str, uint16_t str_size, uint16_t del_pos, uint16_t nb_chars) {
    uint16_t pos, copy_pos;
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
    // check if nb_chars is valid, must be < str_size
    if(nb_chars >= str_size) {
        // error, invalid
        return str_size;
    }

    pos = string_find_end_pos(str, str_size);
    if(pos == str_size) {
        // error, already at the end, no more space available
        // did not do anything
        return str_size;
    }
    if((del_pos + nb_chars) >= pos) {
        // outside pos, so nothing to do
        // skip any copying/deleting
        return pos;
    }
    //string_copy_pos_size(char *str, uint16_t str_size, char *str_copy, uint16_t copy_to_pos, uint16_t copy_size) {
    copy_pos = del_pos + nb_chars;
    return string_copy_pos_size(str, str_size, &str[copy_pos], del_pos, (pos-copy_pos));
}

uint16_t string_delete_from_head(char *str, uint16_t str_size, uint16_t nb_chars) {
    return string_delete_from_position(str, str_size, 0, nb_chars);
}

uint16_t string_delete_from_tail(char *str, uint16_t str_size, uint16_t nb_chars) {
    uint16_t tail_pos;
    tail_pos = string_find_end_pos(str, str_size);
    if(tail_pos == str_size) {
        // error, already at the end, no more space available
        // did not do anything
        return str_size;
    }

    if(nb_chars >= tail_pos) {
        tail_pos = 0;
    }
    else {
        tail_pos -= nb_chars;
    }
    // nothing to copy, just set termination
    str[tail_pos] = STRING_TERMINATION;
}

uint16_t string_append_uint8(char *str, uint16_t str_size, uint8_t num) {
    uint16_t pos, copy_pos;
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

    pos = string_find_end_pos(str, str_size);
    if(pos == str_size) {
        // error, already at the end, no more space available
        // did not do anything
        return str_size;
    }
    
    
    return 4;
}
