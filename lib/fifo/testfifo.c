/**
 * Martin Egli
 * 2023-09-02
 * mmlib: testing fifo functions
 * + compile: gcc fifo.c testfifo.c ../test/test.c -o testfifo.exe
 * + run: ./testfifo.exe
 */

#include "fifo.h"
#include <stdio.h>
#include "../test/test.h"

char *get_bool_string(uint8_t b) {
    if(b == true)
        return "true";
    return "false";
}

void print_fifo_ctrl(fifo_ctrl_t *f, char *name) {
    printf("%s: wr: %d, wr_proc: %d, rd: %d, rd_proc: %d, size: %d\n", name, f->wr, f->wr_proc, f->rd, f->rd_proc, f->size);
}

// code under test
#define SEND_SIZE (4)
fifo_ctrl_t send_ctrl;
uint8_t sens_buffer[SEND_SIZE];

int8_t test01(void) {
    uint8_t res;
    printf(" + test01: basic tests, call fifo_init() ant the other functions with valid and invalid values, do not append or get here\n");
    printf("   + 01: call fifo_init() with correct pointer, this should work (return true)\n");
    res = fifo_init(&send_ctrl, SEND_SIZE);
    printf("     result: %s\n", get_bool_string(res));
    if(res != true) {
        return TEST_FAILED;
    }
    printf("   + 02: call fifo_init() with invalid pointer, this should to fail (return false)\n");
    res = fifo_init(NULL, SEND_SIZE);
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
    res = fifo_is_empty(&send_ctrl);
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
    
    printf("   + 01: call fifo_try_append(), this should work (return true)\n");
    res = fifo_try_append(&send_ctrl);
    printf("     result: %s\n", get_bool_string(res));
    if(res != true) {
        return TEST_FAILED;
    }
    printf("     print ");
    print_fifo_ctrl(&send_ctrl, "send_ctrl");

    printf("   + 02: call fifo_finalize_append(), this should work (return true)\n");
    res = fifo_finalize_append(&send_ctrl);
    printf("     result: %s\n", get_bool_string(res));
    if(res != true) {
        return TEST_FAILED;
    }
    printf("     print ");
    print_fifo_ctrl(&send_ctrl, "send_ctrl");

    printf("   + 03: call fifo_is_empty(), this should NOT be empty (return false)\n");
    res = fifo_is_empty(&send_ctrl);
    printf("     result: %s\n", get_bool_string(res));
    if(res != false) {
        return TEST_FAILED;
    }
    test02_cnt = 1;

    printf("   + 04: call fifo_try_append() and fifo_finalize_append() until send_ctrl is full, until fifo_try_append() == false it istfull\n");
    for(test02_cnt++;;test02_cnt++) {
        printf("\n     + test02_cnt: %d\n", test02_cnt);
        printf("       call fifo_try_append()\n");
        res = fifo_try_append(&send_ctrl);
        printf("       result: %s\n", get_bool_string(res));
        printf("       print ");
        print_fifo_ctrl(&send_ctrl, "send_ctrl");
        if(res == false) {
            printf("       + done, cannot append anymore\n");
            printf("         call fifo_is_full(), just print the result\n");
            res = fifo_is_full(&send_ctrl);
            printf("         result: %s\n", get_bool_string(res));
            break;
        }

        printf("       call fifo_finalize_append(), should always == true\n");
        res = fifo_finalize_append(&send_ctrl);
        printf("       result: %s\n", get_bool_string(res));
        if(res != true) {
            return TEST_FAILED;
        }
        printf("       print ");
        print_fifo_ctrl(&send_ctrl, "send_ctrl");

        printf("       call fifo_is_empty(), just print the result\n");
        res = fifo_is_empty(&send_ctrl);
        printf("       result: %s\n", get_bool_string(res));
        printf("       call fifo_is_full(), just print the result\n");
        res = fifo_is_full(&send_ctrl);
        printf("       result: %s\n", get_bool_string(res));

        if(test02_cnt > send_ctrl.size) {
            printf("       error: test02_cnt (%d) > send_ctrl.size (%d): stop here\n", test02_cnt, send_ctrl.size);
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
    res = fifo_is_full(&send_ctrl);
    printf("     result: %s\n", get_bool_string(res));
    if(res != true) {
        return TEST_FAILED;
    }
    printf("     print ");
    print_fifo_ctrl(&send_ctrl, "send_ctrl");

    printf("   + 02: call fifo_try_get(), this should work (return true)\n");
    res = fifo_try_get(&send_ctrl);
    printf("     result: %s\n", get_bool_string(res));
    if(res != true) {
        return TEST_FAILED;
    }
    printf("     print ");
    print_fifo_ctrl(&send_ctrl, "send_ctrl");

    printf("   + 03: call fifo_finalize_get(), this should work (return true)\n");
    res = fifo_finalize_get(&send_ctrl);
    printf("     result: %s\n", get_bool_string(res));
    if(res != true) {
        return TEST_FAILED;
    }
    printf("     print ");
    print_fifo_ctrl(&send_ctrl, "send_ctrl");

    printf("   + 04: call fifo_is_empty(), this should NOT be empty (return false)\n");
    res = fifo_is_empty(&send_ctrl);
    printf("     result: %s\n", get_bool_string(res));
    if(res != false) {
        return TEST_FAILED;
    }
    test03_cnt = 1;

    printf("   + 05: call fifo_try_get() and fifo_finalize_get() until send_ctrl is empty, until fifo_try_get() == false it istfull\n");
    for(test03_cnt++;;test03_cnt++) {
        printf("\n     + test03_cnt: %d\n", test03_cnt);
        printf("       call fifo_try_get()\n");
        res = fifo_try_get(&send_ctrl);
        printf("       result: %s\n", get_bool_string(res));
        printf("       print ");
        print_fifo_ctrl(&send_ctrl, "send_ctrl");
        if(res == false) {
            printf("       + done, cannot get anymore\n");
            printf("         call fifo_is_empty(), just print the result\n");
            res = fifo_is_empty(&send_ctrl);
            printf("         result: %s\n", get_bool_string(res));
            break;
        }

        printf("       call fifo_finalize_get(), should always == true\n");
        res = fifo_finalize_get(&send_ctrl);
        printf("       result: %s\n", get_bool_string(res));
        if(res != true) {
            return TEST_FAILED;
        }
        printf("       print ");
        print_fifo_ctrl(&send_ctrl, "send_ctrl");

        printf("       call fifo_is_empty(), just print the result\n");
        res = fifo_is_empty(&send_ctrl);
        printf("       result: %s\n", get_bool_string(res));
        printf("       call fifo_is_full(), just print the result\n");
        res = fifo_is_full(&send_ctrl);
        printf("       result: %s\n", get_bool_string(res));

        if(test03_cnt > send_ctrl.size) {
            printf("       error: test03_cnt (%d) > send_ctrl.size (%d): stop here\n", test03_cnt, send_ctrl.size);
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
