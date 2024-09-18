/**
 * Martin Egli
 * 2024-09-18
 * mmlib https://github.com/mwuerms/mmlib
 * testing log functions
 * + compile: gcc log.c log_data.c mem.c log_test.c test.c -o log_test.exe
 * + run: ./log_test.exe
 */

#include <stdio.h>
#include "test.h"

// code under test
#include "log.h"

// testing str_append
int8_t test01(void) {
#if 0
    uint16_t pos, check_pos;
    printf(" + test10: str_buf_append_int16()\n");
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    check_pos = 0;
    printf("   + 01: pos == %d, (pos: %d)\n", check_pos, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != check_pos) {
        return TEST_FAILED;
    }
    str_buf_append_string(test_string, TEST_STRING_SIZE, "int16: ");
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    check_pos += 7;
    printf("   + 02: pos == %d, (pos: %d)\n", check_pos, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != check_pos) {
        return TEST_FAILED;
    }
    str_buf_append_int16(test_string, TEST_STRING_SIZE, 128);
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    check_pos += 3;
    printf("   + 03: pos == %d, (pos: %d)\n", check_pos, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != check_pos) {
        return TEST_FAILED;
    }
    str_buf_append_string(test_string, TEST_STRING_SIZE, ", ");
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    check_pos += 2;
    printf("   + 04: pos == %d, (pos: %d)\n", check_pos, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != check_pos) {
        return TEST_FAILED;
    }
    str_buf_append_int16(test_string, TEST_STRING_SIZE, 13407);
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    check_pos += 5;
    printf("   + 05: pos == %d, (pos: %d)\n", check_pos, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != check_pos) {
        return TEST_FAILED;
    }
    str_buf_append_string(test_string, TEST_STRING_SIZE, ", ");
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    check_pos += 2;
    printf("   + 06: pos == %d, (pos: %d)\n", check_pos, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != check_pos) {
        return TEST_FAILED;
    }
    str_buf_append_int16(test_string, TEST_STRING_SIZE, 32767);
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    check_pos += 5;
    printf("   + 07: pos == %d, (pos: %d)\n", check_pos, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != check_pos) {
        return TEST_FAILED;
    }
    str_buf_append_string(test_string, TEST_STRING_SIZE, ", ");
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    check_pos += 2;
    printf("   + 08: pos == %d, (pos: %d)\n", check_pos, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != check_pos) {
        return TEST_FAILED;
    }
    str_buf_append_int16(test_string, TEST_STRING_SIZE, -32767);
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    check_pos += 6;
    printf("   + 09: pos == %d, (pos: %d)\n", check_pos, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != check_pos) {
        return TEST_FAILED;
    }

    return TEST_SUCCESSFUL;
#endif
    return TEST_FAILED;
}


int main(void) {
    printf("testing log functions\n");
    test_eval_result(test01());
    
    return 0;
}
