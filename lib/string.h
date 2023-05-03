/**
 * Martin Egli
 * 2023-05-03
 * mmlib: sting functions
 */

#ifndef _MM_STRING_H_
#define _MM_STRING_H_

#include <stdint.h>

#define STRING_TERMINATION '\0'

/**
 * find the end position of a given string, '\0'-terminated
 * @param   str         string to find the end in
 * @param   str_size    size of the string
 * @return  pos = 0 ... x: valid position, found the end before str_size, 
 *          pos = str_size: could not find the end, pos invalid
 */
uint16_t string_find_end_pos(char *str, uint16_t str_size);

/** 
 * append the string str_append to the string str
 * @param   str         destination string to append to, this string will be changed
 * @param   str_size    size of the destination string
 * @param   str_append  string to append
 * @return  pos, end position in string
 *          = 0 ... x: valid position
 *          = str_size: appended as much as possible, but reached the end of destination string
 */
uint16_t string_append(char *str, uint16_t str_size, char *str_append);

/**
 * delete a given number of chars at the beginning (head) of the string
 */
uint16_t string_delete_at_head(char *str, uint16_t str_size, uint16_t nb_chars);

/**
 * delete a given number of chars at the end (tail) of the string
 */
uint16_t string_delete_at_tail(char *str, uint16_t str_size, uint16_t nb_chars);

/**
 * append a number in uint8_t as chars to the destination string
 */
uint16_t string_append_uint8(char *str, uint16_t str_size, uint8_t num);

/**
 * append a number in int8_t as chars with sign (-='-', +=' ') to the destination string
 */
uint16_t string_append_int8(char *str, uint16_t str_size, int8_t num);

/**
 * append a number in uint16_t as chars to the destination string
 */
uint16_t string_append_uint16(char *str, uint16_t str_size, uint16_t num);

/**
 * append a number in int16_t as chars with sign (-='-', +=' ') to the destination string
 */
uint16_t string_append_int16(char *str, uint16_t str_size, int16_t num);

/**
 * append a number in uint32_t as chars to the destination string
 */
uint16_t string_append_uint32(char *str, uint16_t str_size, uint32_t num);

/**
 * append a number in int32_t as chars with sign (-='-', +=' ') to the destination string
 */
uint16_t string_append_int32(char *str, uint16_t str_size, int32_t num);

/**
 * append a number in float as chars with sign (-='-', +=' ') to the destination string
 * post point presision = number of chars after '.'
 */
uint16_t string_append_float(char *str, uint16_t str_size, float num, uint16_t post_presision);

/**
 * 
 */

#endif // _MM_STRING_H_
