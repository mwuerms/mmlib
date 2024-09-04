/**
 * Martin Egli
 * 2023-05-03
 * mmlib: testing sting functions
 * + compile: gcc string.c teststring.c ../test/test.c -o teststring.exe
 * + run: ./teststring.exe
 */

#include <stdio.h>
#include "../test/test.h"

// code under test
#include "string.h"

#define TEST_STRING_SIZE  128
char test_string[TEST_STRING_SIZE];

// testing str_append
int8_t test01(void) {
    uint16_t pos;
    printf(" + test01: string_append()\n");
    pos = string_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 01: pos == %d, (pos: %d)\n", 0, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 0) {
        return TEST_FAILED;
    }

    string_append(test_string, TEST_STRING_SIZE, "blub");
    pos = string_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 02: pos == %d, (pos: %d)\n", 4, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 4) {
        return TEST_FAILED;
    }

    string_append(test_string, TEST_STRING_SIZE, "testing with c");
    pos = string_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 03: pos == %d, (pos: %d)\n", 4+14, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 4+14) {
        return TEST_FAILED;
    }
    string_append(test_string, TEST_STRING_SIZE, "+!?@");
    pos = string_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 04: pos == %d, (pos: %d)\n", 4+14+4, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 4+14+4) {
        return TEST_FAILED;
    }
    
    return TEST_SUCCESSFUL;
}


// testing string_copy_pos_size
int8_t test02(void) {
    uint16_t pos;
    printf(" + test02: string_copy_pos_size()\n");
    pos = string_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 01: pos == %d, (pos: %d)\n", 4+14+4, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 4+14+4) {
        return TEST_FAILED;
    }

    char cpy_str[] = "[oh, I want to copy this]";
    uint16_t cpy_str_len = sizeof(cpy_str);
    string_copy_pos_size(test_string, TEST_STRING_SIZE, cpy_str, 6, cpy_str_len);
    pos = string_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 02: pos == %d, (pos: %d)\n", 31, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 31) {
        return TEST_FAILED;
    }
    char cpy_str2[] = "";
    uint16_t cpy_str_len2 = sizeof(cpy_str2);
    string_copy_pos_size(test_string, TEST_STRING_SIZE, cpy_str2, 16, cpy_str_len2);
    pos = string_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 03: pos == %d, (pos: %d)\n", 16, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 16) {
        return TEST_FAILED;
    }
    char cpy_str3[] = "asdf";
    uint16_t cpy_str_len3 = sizeof(cpy_str2);
    string_copy_pos_size(test_string, TEST_STRING_SIZE, cpy_str3, 20, cpy_str_len3);
    pos = string_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 04: pos == %d, (pos: %d)\n", 16, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 16) {
        return TEST_FAILED;
    }
    char cpy_str4[] = "(TEST1_TEST2_TEST3_TEST4_TEST5_TEST6_TEST7_TEST8_TEST9_TESTA_TESTB_TESTC_TESTD_TESTE_TESTF_TESTG_TESTH_TESTI)";
    uint16_t cpy_str_len4 = sizeof(cpy_str4);
    string_copy_pos_size(test_string, TEST_STRING_SIZE, cpy_str4, 10, cpy_str_len4);
    pos = string_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 05: pos == %d, (pos: %d)\n", 119, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 119) {
        return TEST_FAILED;
    }

    return TEST_SUCCESSFUL;
}

// testing string_delete_from_position
int8_t test03(void) {
    uint16_t pos;
    printf(" + test03: string_delete_from_position()\n");
    pos = string_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 01: pos == %d, (pos: %d)\n", 4+14+4, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 119) {
        return TEST_FAILED;
    }

    string_delete_from_position(test_string, TEST_STRING_SIZE, 4, 6);
    pos = string_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 02: pos == %d, (pos: %d)\n", 113, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 113) {
        return TEST_FAILED;
    }

    string_delete_from_position(test_string, TEST_STRING_SIZE, 40, 60);
    pos = string_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 03: pos == %d, (pos: %d)\n", 53, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 53) {
        return TEST_FAILED;
    }
    return TEST_SUCCESSFUL;
}

// testing string_delete_from_head
int8_t test04(void) {
    uint16_t pos;
    printf(" + test04: string_delete_from_head()\n");
    pos = string_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 01: pos == %d, (pos: %d)\n", 53, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 53) {
        return TEST_FAILED;
    }

    string_delete_from_head(test_string, TEST_STRING_SIZE, 10);
    pos = string_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 02: pos == %d, (pos: %d)\n", 43, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 43) {
        return TEST_FAILED;
    }

    string_delete_from_head(test_string, TEST_STRING_SIZE, 13);
    pos = string_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 03: pos == %d, (pos: %d)\n", 30, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 30) {
        return TEST_FAILED;
    }
    return TEST_SUCCESSFUL;
}

// testing string_delete_from_head
int8_t test05(void) {
    uint16_t pos;
    printf(" + test05: string_delete_from_tail()\n");
    pos = string_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 01: pos == %d, (pos: %d)\n", 30, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 30) {
        return TEST_FAILED;
    }

    string_delete_from_tail(test_string, TEST_STRING_SIZE, 10);
    pos = string_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 02: pos == %d, (pos: %d)\n", 10, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 20) {
        return TEST_FAILED;
    }

    string_delete_from_tail(test_string, TEST_STRING_SIZE, 10);
    pos = string_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 03: pos == %d, (pos: %d)\n", 10, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 10) {
        return TEST_FAILED;
    }
    return TEST_SUCCESSFUL;
}

// testing string_clear
int8_t test06(void) {
    uint16_t pos;
    printf(" + test06: string_clear()\n");
    pos = string_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 01: pos == %d, (pos: %d)\n", 10, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 10) {
        return TEST_FAILED;
    }

    string_clear(test_string, TEST_STRING_SIZE);
    pos = string_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 02: pos == %d, (pos: %d)\n", 0, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 0) {
        return TEST_FAILED;
    }
    return TEST_SUCCESSFUL;
}

// testing string_append_uint8
int8_t test07(void) {
    uint16_t pos;
    printf(" + test07: string_append_uint8()\n");
    pos = string_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 01: pos == %d, (pos: %d)\n", 0, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 0) {
        return TEST_FAILED;
    }

    string_append(test_string, TEST_STRING_SIZE, "uint8: ");
    pos = string_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 02: pos == %d, (pos: %d)\n", 7, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 7) {
        return TEST_FAILED;
    }

    string_append_uint8(test_string, TEST_STRING_SIZE, 8);
    pos = string_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 03: pos == %d, (pos: %d)\n", 7+1, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 7+1) {
        return TEST_FAILED;
    }
    
    string_append(test_string, TEST_STRING_SIZE, ", ");
    pos = string_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 04: pos == %d, (pos: %d)\n", 7+1+2, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 7+1+2) {
        return TEST_FAILED;
    }

    return TEST_SUCCESSFUL;
}

int main(void) {
    printf("testing string functions\n");
    test_string[0] = 0;
    test_eval_result(test01());
    test_eval_result(test02());
    test_eval_result(test03());
    test_eval_result(test04());
    test_eval_result(test05());
    test_eval_result(test06());
    test_eval_result(test07());

    return 0;
}
