/**
 * Martin Egli
 * 2023-09-02
 * mmlib https://github.com/mwuerms/mmlib
 * testing fifo functions
 * + compile: gcc ../filter.c filter_test.c test.c -o filter_test
 * + run: ./filter_test
 */

#include "../filter.h"
#include <stdio.h>
#include "test.h"

// code under test
ffir_t f1;
float f1_coeffs[6] = {1.0f/6, 1.0f/6, 1.0f/6, 1.0f/6, 1.0f/6, 1.0f/6};

int8_t test01(void) {
    uint8_t res = false;
    printf(" + test01: init and clear ffir\n");
    printf("   -01: ffir_init(NULL): false\n");
    res = ffir_init(NULL, NULL, 9); // has to fail ff == NULL
    if(res == true) {
        return TEST_FAILED;
    }
    printf("   -02: ffir_init(9): false\n");
    res = ffir_init(&f1, NULL, 9); // has to fail size > FFIR_SIZE
    if(res == true) {
        return TEST_FAILED;
    }
    printf("   -03: ffir_init(): true\n");
    res = ffir_init(&f1, f1_coeffs, 6); // has to pass
    if(res != true) {
        return TEST_FAILED;
    }
    printf("test01 result: ");
    return TEST_SUCCESSFUL;
}

int8_t test02(void) {
    uint8_t res = false;
    uint16_t n;
    printf(" + test02: check coeffs and values\n");
    printf("   -01: size must == 6\n");
    if(f1.size != 6) {
        printf("   error size (%d) != %d\n", f1.size, 6);
        return TEST_FAILED;
    }
    printf("   -02: filtered_value must == 0 (after clear)\n");
    if(f1.filtered_value != 0.0f) {
        printf("   error filtered_value (%f) != %f\n", f1.filtered_value, 0.0f);
        return TEST_FAILED;
    }
    printf("   -03: all coeffs must == f1_coeffs\n");
    for(n = 0; n < 6; n++) {
        if(f1_coeffs[n] != f1.coeffs[n]) {
            printf("   error [%d] coeffs not equal %f != %f\n", n, f1_coeffs[n], f1.coeffs[n]);
            return TEST_FAILED;
        }
    }
    printf("   -04: all values must == 0.0f\n");
    for(n = 0; n < 6; n++) {
        if(f1.values[n] != 0.0f) {
            printf("   error f1.values[%d] (%f) != %f\n", n, f1.values[n], 0.0f);
            return TEST_FAILED;
        }
    }
    printf("test02 result: ");
    return TEST_SUCCESSFUL;
}

int8_t test03(void) {
    uint8_t res = false;
    uint16_t n;
    printf(" + test03: filter\n");

    for(n = 0; n < 10; n++) {
        res = ffir_filter(&f1, 1.0f);
        printf("   -[%d] f1.filtered_value: %f\n", n, f1.filtered_value);
    }
    printf("test03 result: ");
    return TEST_SUCCESSFUL;
}

int main(void) {
    printf("testing filter functions\n\n");
    test_eval_result(test01());
    test_eval_result(test02());
    test_eval_result(test03());

    printf("\nall tests successfully done\n");
    return 0;
}
