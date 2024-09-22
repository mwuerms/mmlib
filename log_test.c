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
#include "log_data.h"
#include "mem.h"

int8_t test01(void) {
    uint8_t test_nr;
    printf(" + test01: setup logging\n");
    test_nr = 1;
    printf("   + %02d: log_init()\n", test_nr);
    log_init();
    test_nr++;
    printf("   + %02d: log_start()\n", test_nr);
    log_start();
    test_nr++;
    printf("   + %02d: log_set_level(LOG_LEVEL_ANY)\n", test_nr);
    log_set_level(LOG_LEVEL_INFO);
    test_nr++;
    printf("   + %02d: check started logging\n", test_nr);
    return TEST_SUCCESSFUL;
}
int8_t test02(void) {
    printf(" + test02: log_value_uint16()\n");
    return TEST_SUCCESSFUL;
}

int main(void) {
    printf("testing log functions\n");
    test_eval_result(test01());
    test_eval_result(test02());

    mem_wr_page_buffer_print_hex();
    return 0;
}
