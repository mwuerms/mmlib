/**
 * Martin Egli
 * 2023-09-02
 * mmlib https://github.com/mwuerms/mmlib
 * testing fifo functions
 * + compile: gcc ../fifo.c fifo_test.c test.c -o fifo_test
 * + run: ./fifo_test
 */

#include "../fifo.h"
#include <stdio.h>
#include "test.h"

char *get_bool_string(uint8_t b) {
    if(b == true)
        return "true";
    return "false";
}

void print_fifo_ctrl(fifo_t *f, char *name) {
    printf("%s: wr: %d, wr_proc: %d, rd: %d, rd_proc: %d, size: %d\n", name, f->wr, f->wr_proc, f->rd, f->rd_proc, f->size);
}

// code under test
#define SEND_SIZE (4)
fifo_t test_fifo;
uint8_t test_fifo_data[SEND_SIZE];

int8_t test01(void) {
    uint8_t res;
    printf(" + test01: basic tests, call fifo_init() ant the other functions with valid and invalid values, do not append or get here\n");
    printf("   + 01: call fifo_init() with correct pointer, this should work (return true)\n");
    res = fifo_init(&test_fifo, (void *)test_fifo_data, SEND_SIZE);
    //res = fifo_init(&test_fifo, send_buffer, SEND_SIZE);
    printf("     result: %s\n", get_bool_string(res));
    if(res != true) {
        return TEST_FAILED;
    }
    printf("   + 02: call fifo_init() with invalid pointer, this should to fail (return false)\n");
    res = fifo_init(NULL, NULL, SEND_SIZE);
    printf("     result: %s\n", get_bool_string(res));
    if(res != false) {
        return TEST_FAILED;
    }
    printf("   + 03: call fifo_is_empty() with invalid pointer, this should to fail (return false)\n");
    res = fifo_is_empty(NULL);
    printf("     result: %s\n", get_bool_string(res));
    if(res != false) {
        return TEST_FAILED;
    }
    printf("   + 04: call fifo_is_full() with invalid pointer, this should to fail (return false)\n");
    res = fifo_is_full(NULL);
    printf("     result: %s\n", get_bool_string(res));
    if(res != false) {
        return TEST_FAILED;
    }
    printf("   + 05: call fifo_try_append() with invalid pointer, this should to fail (return false)\n");
    res = fifo_try_append(NULL);
    printf("     result: %s\n", get_bool_string(res));
    if(res != false) {
        return TEST_FAILED;
    }
    printf("   + 06: call fifo_finalize_append() with invalid pointer, this should to fail (return false)\n");
    res = fifo_finalize_append(NULL);
    printf("     result: %s\n", get_bool_string(res));
    if(res != false) {
        return TEST_FAILED;
    }
    printf("   + 07: call fifo_try_get() with invalid pointer, this should to fail (return false)\n");
    res = fifo_try_get(NULL);
    printf("     result: %s\n", get_bool_string(res));
    if(res != false) {
        return TEST_FAILED;
    }
    printf("   + 08: call fifo_finalize_get() with invalid pointer, this should to fail (return false)\n");
    res = fifo_finalize_get(NULL);
    printf("     result: %s\n", get_bool_string(res));
    if(res != false) {
        return TEST_FAILED;
    }
    printf("   + 09: call fifo_is_empty(), this should be empty (return true)\n");
    res = fifo_is_empty(&test_fifo);
    printf("     result: %s\n", get_bool_string(res));
    if(res != true) {
        return TEST_FAILED;
    }
    printf("   test01 result: ");
    return TEST_SUCCESSFUL;
}

int8_t test02(void) {
    uint16_t test02_cnt = 0; 
    uint8_t res;
    printf(" + test02: fifo_try_append() and fifo_finalize_append()\n");
    printf("     print ");
    print_fifo_ctrl(&test_fifo, "test_fifo");
    printf("   + 00: call fifo_try_get(), just get result\n");
    res = fifo_try_get(&test_fifo);
    printf("     result: %s\n", get_bool_string(res));
    printf("     print ");
    print_fifo_ctrl(&test_fifo, "test_fifo");

    printf("   + 01: call fifo_try_append(), this should work (return true)\n");
    res = fifo_try_append(&test_fifo);
    printf("     result: %s\n", get_bool_string(res));
    if(res != true) {
        return TEST_FAILED;
    }
    printf("     print ");
    print_fifo_ctrl(&test_fifo, "test_fifo");

    printf("   + 02: call fifo_finalize_append(), this should work (return true)\n");
    res = fifo_finalize_append(&test_fifo);
    printf("     result: %s\n", get_bool_string(res));
    if(res != true) {
        return TEST_FAILED;
    }
    printf("     print ");
    print_fifo_ctrl(&test_fifo, "test_fifo");

    printf("   + 03: call fifo_is_empty(), this should NOT be empty (return false)\n");
    res = fifo_is_empty(&test_fifo);
    printf("     result: %s\n", get_bool_string(res));
    if(res != false) {
        return TEST_FAILED;
    }
    test02_cnt = 1;

    printf("   + 04: call fifo_try_append() and fifo_finalize_append() until test_fifo is full, until fifo_try_append() == false it istfull\n");
    for(test02_cnt++;;test02_cnt++) {
        printf("\n     + test02_cnt: %d\n", test02_cnt);
        printf("       call fifo_try_append()\n");
        res = fifo_try_append(&test_fifo);
        printf("       result: %s\n", get_bool_string(res));
        printf("       print ");
        print_fifo_ctrl(&test_fifo, "test_fifo");
        if(res == false) {
            printf("       + done, cannot append anymore\n");
            printf("         call fifo_is_full(), just print the result\n");
            res = fifo_is_full(&test_fifo);
            printf("         result: %s\n", get_bool_string(res));
            break;
        }

        printf("       call fifo_finalize_append(), should always == true\n");
        res = fifo_finalize_append(&test_fifo);
        printf("       result: %s\n", get_bool_string(res));
        if(res != true) {
            return TEST_FAILED;
        }
        printf("       print ");
        print_fifo_ctrl(&test_fifo, "test_fifo");

        printf("       call fifo_is_empty(), just print the result\n");
        res = fifo_is_empty(&test_fifo);
        printf("       result: %s\n", get_bool_string(res));
        printf("       call fifo_is_full(), just print the result\n");
        res = fifo_is_full(&test_fifo);
        printf("       result: %s\n", get_bool_string(res));

        if(test02_cnt > test_fifo.size) {
            printf("       error: test02_cnt (%d) > test_fifo.size (%d): stop here\n", test02_cnt, test_fifo.size);
            return TEST_FAILED;
        }
    }

    printf("\n   test02 result: ");
    return TEST_SUCCESSFUL;
}

int8_t test03(void) {
    uint16_t test03_cnt = 0; 
    uint8_t res;
    printf(" + test03: fifo_try_get() and fifo_finalize_get()\n");
    
    printf("   + 01: call fifo_is_full(), this should be full from test02 (return true)\n");
    res = fifo_is_full(&test_fifo);
    printf("     result: %s\n", get_bool_string(res));
    if(res != true) {
        return TEST_FAILED;
    }
    printf("     print ");
    print_fifo_ctrl(&test_fifo, "test_fifo");

    printf("   + 02: call fifo_try_get(), this should work (return true)\n");
    res = fifo_try_get(&test_fifo);
    printf("     result: %s\n", get_bool_string(res));
    if(res != true) {
        return TEST_FAILED;
    }
    printf("     print ");
    print_fifo_ctrl(&test_fifo, "test_fifo");

    printf("   + 03: call fifo_finalize_get(), this should work (return true)\n");
    res = fifo_finalize_get(&test_fifo);
    printf("     result: %s\n", get_bool_string(res));
    if(res != true) {
        return TEST_FAILED;
    }
    printf("     print ");
    print_fifo_ctrl(&test_fifo, "test_fifo");

    printf("   + 04: call fifo_is_empty(), this should NOT be empty (return false)\n");
    res = fifo_is_empty(&test_fifo);
    printf("     result: %s\n", get_bool_string(res));
    if(res != false) {
        return TEST_FAILED;
    }
    test03_cnt = 1;

    printf("   + 05: call fifo_try_get() and fifo_finalize_get() until test_fifo is empty, until fifo_try_get() == false it istfull\n");
    for(test03_cnt++;;test03_cnt++) {
        printf("\n     + test03_cnt: %d\n", test03_cnt);
        printf("       call fifo_try_get()\n");
        res = fifo_try_get(&test_fifo);
        printf("       result: %s\n", get_bool_string(res));
        printf("       print ");
        print_fifo_ctrl(&test_fifo, "test_fifo");
        if(res == false) {
            printf("       + done, cannot get anymore\n");
            printf("         call fifo_is_empty(), just print the result\n");
            res = fifo_is_empty(&test_fifo);
            printf("         result: %s\n", get_bool_string(res));
            break;
        }

        printf("       call fifo_finalize_get(), should always == true\n");
        res = fifo_finalize_get(&test_fifo);
        printf("       result: %s\n", get_bool_string(res));
        if(res != true) {
            return TEST_FAILED;
        }
        printf("       print ");
        print_fifo_ctrl(&test_fifo, "test_fifo");

        printf("       call fifo_is_empty(), just print the result\n");
        res = fifo_is_empty(&test_fifo);
        printf("       result: %s\n", get_bool_string(res));
        printf("       call fifo_is_full(), just print the result\n");
        res = fifo_is_full(&test_fifo);
        printf("       result: %s\n", get_bool_string(res));

        if(test03_cnt > test_fifo.size) {
            printf("       error: test03_cnt (%d) > test_fifo.size (%d): stop here\n", test03_cnt, test_fifo.size);
            return TEST_FAILED;
        }
    }
    
    printf("\n   test03 result: ");
    return TEST_SUCCESSFUL;
}

int main(void) {
    printf("testing fifo functions\n\n");
    test_eval_result(test01());
    test_eval_result(test02());
    test_eval_result(test03());

    printf("\nall tests successfully done\n");
    return 0;
}
