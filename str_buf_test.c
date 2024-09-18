/**
 * Martin Egli
 * 2023-05-03
 * mmlib https://github.com/mwuerms/mmlib
 * testing sting functions
 * + compile: gcc str_buf.c str_buf_test.c test.c -o str_buf_test.exe
 * + run: ./str_buf_test.exe
 */

#include <stdio.h>
#include "test.h"

// code under test
#include "str_buf.h"

#define TEST_STRING_SIZE  128
char test_string[TEST_STRING_SIZE];

// testing str_append
int8_t test01(void) {
    uint16_t pos;
    printf(" + test01: str_buf_append_string()\n");
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 01: pos == %d, (pos: %d)\n", 0, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 0) {
        return TEST_FAILED;
    }

    str_buf_append_string(test_string, TEST_STRING_SIZE, "blub");
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 02: pos == %d, (pos: %d)\n", 4, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 4) {
        return TEST_FAILED;
    }

    str_buf_append_string(test_string, TEST_STRING_SIZE, "testing with c");
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 03: pos == %d, (pos: %d)\n", 4+14, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 4+14) {
        return TEST_FAILED;
    }
    str_buf_append_string(test_string, TEST_STRING_SIZE, "+!?@");
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 04: pos == %d, (pos: %d)\n", 4+14+4, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 4+14+4) {
        return TEST_FAILED;
    }
    
    return TEST_SUCCESSFUL;
}


// testing str_buf_copy_pos_size
int8_t test02(void) {
    uint16_t pos;
    printf(" + test02: str_buf_copy_pos_size()\n");
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 01: pos == %d, (pos: %d)\n", 4+14+4, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 4+14+4) {
        return TEST_FAILED;
    }

    char cpy_str[] = "[oh, I want to copy this]";
    uint16_t cpy_str_len = sizeof(cpy_str);
    str_buf_copy_pos_size(test_string, TEST_STRING_SIZE, cpy_str, 6, cpy_str_len);
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 02: pos == %d, (pos: %d)\n", 31, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 31) {
        return TEST_FAILED;
    }
    char cpy_str2[] = "";
    uint16_t cpy_str_len2 = sizeof(cpy_str2);
    str_buf_copy_pos_size(test_string, TEST_STRING_SIZE, cpy_str2, 16, cpy_str_len2);
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 03: pos == %d, (pos: %d)\n", 16, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 16) {
        return TEST_FAILED;
    }
    char cpy_str3[] = "asdf";
    uint16_t cpy_str_len3 = sizeof(cpy_str2);
    str_buf_copy_pos_size(test_string, TEST_STRING_SIZE, cpy_str3, 20, cpy_str_len3);
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 04: pos == %d, (pos: %d)\n", 16, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 16) {
        return TEST_FAILED;
    }
    char cpy_str4[] = "(TEST1_TEST2_TEST3_TEST4_TEST5_TEST6_TEST7_TEST8_TEST9_TESTA_TESTB_TESTC_TESTD_TESTE_TESTF_TESTG_TESTH_TESTI)";
    uint16_t cpy_str_len4 = sizeof(cpy_str4);
    str_buf_copy_pos_size(test_string, TEST_STRING_SIZE, cpy_str4, 10, cpy_str_len4);
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 05: pos == %d, (pos: %d)\n", 119, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 119) {
        return TEST_FAILED;
    }

    return TEST_SUCCESSFUL;
}

// testing str_buf_delete_from_position
int8_t test03(void) {
    uint16_t pos;
    printf(" + test03: str_buf_delete_from_position()\n");
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 01: pos == %d, (pos: %d)\n", 4+14+4, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 119) {
        return TEST_FAILED;
    }

    str_buf_delete_from_position(test_string, TEST_STRING_SIZE, 4, 6);
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 02: pos == %d, (pos: %d)\n", 113, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 113) {
        return TEST_FAILED;
    }

    str_buf_delete_from_position(test_string, TEST_STRING_SIZE, 40, 60);
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 03: pos == %d, (pos: %d)\n", 53, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 53) {
        return TEST_FAILED;
    }
    return TEST_SUCCESSFUL;
}

// testing str_buf_delete_from_head
int8_t test04(void) {
    uint16_t pos;
    printf(" + test04: str_buf_delete_from_head()\n");
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 01: pos == %d, (pos: %d)\n", 53, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 53) {
        return TEST_FAILED;
    }

    str_buf_delete_from_head(test_string, TEST_STRING_SIZE, 10);
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 02: pos == %d, (pos: %d)\n", 43, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 43) {
        return TEST_FAILED;
    }

    str_buf_delete_from_head(test_string, TEST_STRING_SIZE, 13);
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 03: pos == %d, (pos: %d)\n", 30, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 30) {
        return TEST_FAILED;
    }
    return TEST_SUCCESSFUL;
}

// testing str_buf_delete_from_head
int8_t test05(void) {
    uint16_t pos;
    printf(" + test05: str_buf_delete_from_tail()\n");
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 01: pos == %d, (pos: %d)\n", 30, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 30) {
        return TEST_FAILED;
    }

    str_buf_delete_from_tail(test_string, TEST_STRING_SIZE, 10);
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 02: pos == %d, (pos: %d)\n", 10, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 20) {
        return TEST_FAILED;
    }

    str_buf_delete_from_tail(test_string, TEST_STRING_SIZE, 10);
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 03: pos == %d, (pos: %d)\n", 10, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 10) {
        return TEST_FAILED;
    }
    return TEST_SUCCESSFUL;
}

// testing str_buf_clear
int8_t test06(void) {
    uint16_t pos;
    printf(" + test06: str_buf_clear()\n");
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 01: pos == %d, (pos: %d)\n", 10, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 10) {
        return TEST_FAILED;
    }

    str_buf_clear(test_string, TEST_STRING_SIZE);
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 02: pos == %d, (pos: %d)\n", 0, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 0) {
        return TEST_FAILED;
    }
    return TEST_SUCCESSFUL;
}

// testing str_buf_append_uint8
int8_t test07(void) {
    uint16_t pos;
    printf(" + test07: str_buf_append_uint8()\n");
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 01: pos == %d, (pos: %d)\n", 0, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 0) {
        return TEST_FAILED;
    }

    str_buf_append_string(test_string, TEST_STRING_SIZE, "uint8: ");
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 02: pos == %d, (pos: %d)\n", 7, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 7) {
        return TEST_FAILED;
    }

    str_buf_append_uint8(test_string, TEST_STRING_SIZE, 8);
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 03: pos == %d, (pos: %d)\n", 7+1, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 7+1) {
        return TEST_FAILED;
    }
    
    str_buf_append_string(test_string, TEST_STRING_SIZE, ", ");
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 04: pos == %d, (pos: %d)\n", 7+1+2, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 7+1+2) {
        return TEST_FAILED;
    }
    str_buf_append_uint8(test_string, TEST_STRING_SIZE, 17);
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 05: pos == %d, (pos: %d)\n", 12, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 12) {
        return TEST_FAILED;
    }
    str_buf_append_string(test_string, TEST_STRING_SIZE, ", ");
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 06: pos == %d, (pos: %d)\n", 14, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 14) {
        return TEST_FAILED;
    }
    str_buf_append_uint8(test_string, TEST_STRING_SIZE, 217);
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 07: pos == %d, (pos: %d)\n", 17, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 17) {
        return TEST_FAILED;
    }
    str_buf_append_string(test_string, TEST_STRING_SIZE, ", ");
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 08: pos == %d, (pos: %d)\n", 19, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 19) {
        return TEST_FAILED;
    }
    printf("   + 09: str_buf_append_uint8(test_string, TEST_STRING_SIZE, 256); results in an compiler error, because 256 outside 0 ... 255, uint8_t\n");
    str_buf_append_uint8(test_string, TEST_STRING_SIZE, -12);
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 10: pos == %d, (pos: %d)\n", 22, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 22) {
        return TEST_FAILED;
    }
    printf("     (uint8_t)-12 = 244, so append 244 instead of -12 \n");

    return TEST_SUCCESSFUL;
}

// testing str_buf_append_int8
int8_t test08(void) {
    uint16_t pos;
    printf(" + test08: str_buf_append_int8()\n");
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 01: pos == %d, (pos: %d)\n", 0, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 0) {
        return TEST_FAILED;
    }

    str_buf_append_string(test_string, TEST_STRING_SIZE, "int8: ");
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 02: pos == %d, (pos: %d)\n", 6, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 6) {
        return TEST_FAILED;
    }

    str_buf_append_int8(test_string, TEST_STRING_SIZE, -8);
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 03: pos == %d, (pos: %d)\n", 8, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 8) {
        return TEST_FAILED;
    }
    
    str_buf_append_string(test_string, TEST_STRING_SIZE, ", ");
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 04: pos == %d, (pos: %d)\n", 10, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 10) {
        return TEST_FAILED;
    }
    str_buf_append_int8(test_string, TEST_STRING_SIZE, -17);
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 05: pos == %d, (pos: %d)\n", 13, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 13) {
        return TEST_FAILED;
    }
    str_buf_append_string(test_string, TEST_STRING_SIZE, ", ");
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 06: pos == %d, (pos: %d)\n", 15, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 15) {
        return TEST_FAILED;
    }
    str_buf_append_int8(test_string, TEST_STRING_SIZE, -127);
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 07: pos == %d, (pos: %d)\n", 19, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 19) {
        return TEST_FAILED;
    }
    str_buf_append_string(test_string, TEST_STRING_SIZE, ", ");
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 08: pos == %d, (pos: %d)\n", 21, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 21) {
        return TEST_FAILED;
    }
    str_buf_append_int8(test_string, TEST_STRING_SIZE, 127);
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    printf("   + 09: pos == %d, (pos: %d)\n", 24, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != 24) {
        return TEST_FAILED;
    }

    return TEST_SUCCESSFUL;
}

// testing str_buf_append_uint16
int8_t test09(void) {
    uint16_t pos, check_pos;
    printf(" + test09: str_buf_append_uint16()\n");
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    check_pos = 0;
    printf("   + 01: pos == %d, (pos: %d)\n", check_pos, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != check_pos) {
        return TEST_FAILED;
    }
    str_buf_append_string(test_string, TEST_STRING_SIZE, "uint16: ");
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    check_pos += 8;
    printf("   + 02: pos == %d, (pos: %d)\n", check_pos, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != check_pos) {
        return TEST_FAILED;
    }
    str_buf_append_uint16(test_string, TEST_STRING_SIZE, 128);
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
    str_buf_append_uint16(test_string, TEST_STRING_SIZE, 13407);
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
    str_buf_append_uint16(test_string, TEST_STRING_SIZE, 65535);
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
    printf("   + 09: str_buf_append_uint16(test_string, TEST_STRING_SIZE, 65536); results in an compiler error, because 65536 outside 0 ... 65535, uint16_t\n");
    str_buf_append_uint16(test_string, TEST_STRING_SIZE, -12);
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    check_pos += 5;
    printf("   + 10: pos == %d, (pos: %d)\n", check_pos, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != check_pos) {
        return TEST_FAILED;
    }
    printf("     (uint8_t)-12 = 65524, so append 65524 instead of -12 \n");

    return TEST_SUCCESSFUL;
}

// testing str_buf_append_int16
int8_t test10(void) {
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
}

// testing str_buf_append_uint32
int8_t test11(void) {
    uint16_t pos, check_pos;
    printf(" + test11: str_buf_append_uint32()\n");
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    check_pos = 0;
    printf("   + 01: pos == %d, (pos: %d)\n", check_pos, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != check_pos) {
        return TEST_FAILED;
    }
    str_buf_append_string(test_string, TEST_STRING_SIZE, "uint32: ");
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    check_pos += 8;
    printf("   + 02: pos == %d, (pos: %d)\n", check_pos, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != check_pos) {
        return TEST_FAILED;
    }
    str_buf_append_uint32(test_string, TEST_STRING_SIZE, 128);
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
    str_buf_append_uint32(test_string, TEST_STRING_SIZE, 4000000000);
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    check_pos += 10;
    printf("   + 05: pos == %d, (pos: %d)\n", check_pos, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != check_pos) {
        return TEST_FAILED;
    }

    return TEST_SUCCESSFUL;
}

// testing str_buf_append_int32
int8_t test12(void) {
    uint16_t pos, check_pos;
    printf(" + test12: str_buf_append_int32()\n");
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    check_pos = 0;
    printf("   + 01: pos == %d, (pos: %d)\n", check_pos, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != check_pos) {
        return TEST_FAILED;
    }
    str_buf_append_string(test_string, TEST_STRING_SIZE, "int32: ");
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    check_pos += 7;
    printf("   + 02: pos == %d, (pos: %d)\n", check_pos, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != check_pos) {
        return TEST_FAILED;
    }
    str_buf_append_int32(test_string, TEST_STRING_SIZE, 128);
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
    str_buf_append_int32(test_string, TEST_STRING_SIZE, 2000000000);
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    check_pos += 10;
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
    str_buf_append_int32(test_string, TEST_STRING_SIZE, -1000000000);
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    check_pos += 11;
    printf("   + 03: pos == %d, (pos: %d)\n", check_pos, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != check_pos) {
        return TEST_FAILED;
    }

    return TEST_SUCCESSFUL;
}

// testing str_buf_append_float
int8_t test13(void) {
    uint16_t pos, check_pos;
    printf(" + test13: str_buf_append_float()\n");
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    check_pos = 0;
    printf("   + 01: pos == %d, (pos: %d)\n", check_pos, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != check_pos) {
        return TEST_FAILED;
    }
    str_buf_append_string(test_string, TEST_STRING_SIZE, "float: ");
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    check_pos += 7;
    printf("   + 02: pos == %d, (pos: %d)\n", check_pos, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != check_pos) {
        return TEST_FAILED;
    }
    str_buf_append_float(test_string, TEST_STRING_SIZE, 123.45678f, 3);
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    check_pos += 7;
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
    str_buf_append_float(test_string, TEST_STRING_SIZE, -72.004567f, 6);
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    check_pos += 10;
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
    str_buf_append_float(test_string, TEST_STRING_SIZE, -0.004567f, 6);
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    check_pos += 9;
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
    str_buf_append_float(test_string, TEST_STRING_SIZE, -0.00000000123f, 10);
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    check_pos += 12;
    printf("   + 07: pos == %d, (pos: %d)\n", check_pos, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != check_pos) {
        return TEST_FAILED;
    }
    return TEST_SUCCESSFUL;
}

// testing str_buf_append_float
int8_t test14(void) {
    uint16_t pos, check_pos;
    printf(" + test13: str_buf_append_0x_hex_upper_case_nb_digits()\n");
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    check_pos = 0;
    printf("   + 01: pos == %d, (pos: %d)\n", check_pos, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != check_pos) {
        return TEST_FAILED;
    }
    str_buf_append_string(test_string, TEST_STRING_SIZE, "hex: ");
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    check_pos += 5;
    printf("   + 02: pos == %d, (pos: %d)\n", check_pos, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != check_pos) {
        return TEST_FAILED;
    }
    str_buf_append_0x_hex_upper_case_nb_digits(test_string, TEST_STRING_SIZE, 0, 4);
    pos = str_buf_find_end_pos(test_string, TEST_STRING_SIZE);
    check_pos += 3;
    printf("   + 03: pos == %d, (pos: %d)\n", check_pos, pos);
    printf("     test_string: %s\n", test_string);
    if(pos != check_pos) {
        return TEST_FAILED;
    }

    // add more tests here
    
    return TEST_SUCCESSFUL;
}

int main(void) {
    printf("testing string functions\n");
    str_buf_clear(test_string, TEST_STRING_SIZE);

    test_eval_result(test01());
    test_eval_result(test02());
    test_eval_result(test03());
    test_eval_result(test04());
    test_eval_result(test05());
    test_eval_result(test06());

    str_buf_clear(test_string, TEST_STRING_SIZE);
    test_eval_result(test07());

    str_buf_clear(test_string, TEST_STRING_SIZE);
    test_eval_result(test08());

    str_buf_clear(test_string, TEST_STRING_SIZE);
    test_eval_result(test09());

    str_buf_clear(test_string, TEST_STRING_SIZE);
    test_eval_result(test10());

    str_buf_clear(test_string, TEST_STRING_SIZE);
    test_eval_result(test11());

    str_buf_clear(test_string, TEST_STRING_SIZE);
    test_eval_result(test12());

    str_buf_clear(test_string, TEST_STRING_SIZE);
    test_eval_result(test13());

    str_buf_clear(test_string, TEST_STRING_SIZE);
    test_eval_result(test14());
    
    return 0;
}
