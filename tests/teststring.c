/**
 * Martin Egli
 * 2023-05-03
 * mmlib: testing sting functions
 * + compile: gcc ../lib/string.c teststring.c -o teststring.exe
 * + run: ./teststring.exe
 */

#include <stdio.h>
#include "test.h"

void print_result(int8_t res) {
    if(res == TEST_SUCCESSFUL) {
        printf("SUCESSFUL\n\n");
        // continue
    }
    else {
        printf("FAILED\n");
        exit(1);
    }
}


// code under test
#include "../lib/string.h"

#define TEST_STRING_SIZE  128
char test_string[TEST_STRING_SIZE];

// testing str_append
int8_t test01(void) {
    uint16_t pos;
    printf("+test01: string_append()\n");
    pos = string_find_end_pos(test_string, TEST_STRING_SIZE);
    printf(" +01: pos == %d, (pos: %d)\n", 0, pos);
    if(pos != 0) {
        return TEST_FAILED;
    }

    string_append(test_string, TEST_STRING_SIZE, "blub");
    pos = string_find_end_pos(test_string, TEST_STRING_SIZE);
    printf(" +02: pos == %d, (pos: %d)\n", 4, pos);
    printf("  test_string: %s\n", test_string);
    if(pos != 4) {
        return TEST_FAILED;
    }

    string_append(test_string, TEST_STRING_SIZE, "testing with c");
    pos = string_find_end_pos(test_string, TEST_STRING_SIZE);
    printf(" +03: pos == %d, (pos: %d)\n", 4+14, pos);
    printf("  test_string: %s\n", test_string);
    if(pos != 4+14) {
        return TEST_FAILED;
    }
    string_append(test_string, TEST_STRING_SIZE, "+!?@");
    pos = string_find_end_pos(test_string, TEST_STRING_SIZE);
    printf(" +04: pos == %d, (pos: %d)\n", 4+14+4, pos);
    printf("  test_string: %s\n", test_string);
    if(pos != 4+14+4) {
        return TEST_FAILED;
    }
    
    return TEST_SUCCESSFUL;
}

int main(void) {
    int8_t res;
    printf("testing string functions\n");
    test_string[0] = 0;
    res = test01();
    print_result(res);

    return 0;
}
