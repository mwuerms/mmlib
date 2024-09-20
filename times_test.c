/**
 * Martin Egli
 * 2024-09-18
 * mmlib https://github.com/mwuerms/mmlib
 * testing log functions
 * + compile: gcc times.c times_test.c test.c -o times_test.exe
 * + run: ./times_test.exe
 */

#include <stdio.h>
#include "test.h"

// code under test
#include "times.h"

int8_t test01(void) {
    printf(" + test01: times_yyyy_to_days()\n");
    uint32_t days_result, days_should, diff;
    uint16_t year, test_nr;
    
    test_nr = 1;
    year = 2000;
    printf("   + %02d: times_yyyy_to_days(%d)\n", test_nr, year);
    days_should = 0;
    days_result = times_yyyy_to_days(year);
    diff = days_should - days_result;
    printf("     should: %d\n", days_should);
    printf("     result: %d\n", days_result);
    printf("     diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    test_nr++;
    year = 2001;
    printf("   + %02d: times_yyyy_to_days(%d)\n", test_nr, year);
    days_should = 365+1;
    days_result = times_yyyy_to_days(year);
    diff = days_should - days_result;
    printf("     should: %d\n", days_should);
    printf("     result: %d\n", days_result);
    printf("     diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    test_nr++;
    year = 2002;
    printf("   + %02d: times_yyyy_to_days(%d)\n", test_nr, year);
    days_should = 365+1+365;
    days_result = times_yyyy_to_days(year);
    diff = days_should - days_result;
    printf("     should: %d\n", days_should);
    printf("     result: %d\n", days_result);
    printf("     diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    test_nr++;
    year = 2003;
    printf("   + %02d: times_yyyy_to_days(%d)\n", test_nr, year);
    days_should = 365+1+365+365;
    days_result = times_yyyy_to_days(year);
    diff = days_should - days_result;
    printf("     should: %d\n", days_should);
    printf("     result: %d\n", days_result);
    printf("     diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    test_nr++;
    year = 2004;
    printf("   + %02d: times_yyyy_to_days(%d)\n", test_nr, year);
    days_should = (4*365+1);
    days_result = times_yyyy_to_days(year);
    diff = days_should - days_result;
    printf("     should: %d\n", days_should);
    printf("     result: %d\n", days_result);
    printf("     diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    test_nr++;
    year = 2005;
    printf("   + %02d: times_yyyy_to_days(%d)\n", test_nr, year);
    days_should = 1*(4*365+1)+(1*365+1);
    days_result = times_yyyy_to_days(year);
    diff = days_should - days_result;
    printf("     should: %d\n", days_should);
    printf("     result: %d\n", days_result);
    printf("     diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    test_nr++;
    year = 2006;
    printf("   + %02d: times_yyyy_to_days(%d)\n", test_nr, year);
    days_should = 1*(4*365+1)+(2*365+1);
    days_result = times_yyyy_to_days(year);
    diff = days_should - days_result;
    printf("     should: %d\n", days_should);
    printf("     result: %d\n", days_result);
    printf("     diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    test_nr++;
    year = 2007;
    printf("   + %02d: times_yyyy_to_days(%d)\n", test_nr, year);
    days_should = 1*(4*365+1)+(3*365+1);
    days_result = times_yyyy_to_days(year);
    diff = days_should - days_result;
    printf("     should: %d\n", days_should);
    printf("     result: %d\n", days_result);
    printf("     diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    test_nr++;
    year = 2008;
    printf("   + %02d: times_yyyy_to_days(%d)\n", test_nr, year);
    days_should = 2*(4*365+1)+0*(1*365+1);
    days_result = times_yyyy_to_days(year);
    diff = days_should - days_result;
    printf("     should: %d\n", days_should);
    printf("     result: %d\n", days_result);
    printf("     diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    test_nr++;
    year = 2015;
    printf("   + %02d: times_yyyy_to_days(%d)\n", test_nr, year);
    days_should = 3*(4*365+1)+(3*365+1);
    days_result = times_yyyy_to_days(year);
    diff = days_should - days_result;
    printf("     should: %d\n", days_should);
    printf("     result: %d\n", days_result);
    printf("     diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    test_nr++;
    year = 2019;
    printf("   + %02d: times_yyyy_to_days(%d)\n", test_nr, year);
    days_should = 4*(4*365+1)+(3*365+1);
    days_result = times_yyyy_to_days(year);
    diff = days_should - days_result;
    printf("     should: %d\n", days_should);
    printf("     result: %d\n", days_result);
    printf("     diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    test_nr++;
    year = 2024;
    printf("   + %02d: times_yyyy_to_days(%d)\n", test_nr, year);
    days_should = 6*(4*365+1)+0*(3*365+1);
    days_result = times_yyyy_to_days(year);
    diff = days_should - days_result;
    printf("     should: %d\n", days_should);
    printf("     result: %d\n", days_result);
    printf("     diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    test_nr++;
    year = 2027;
    printf("   + %02d: times_yyyy_to_days(%d)\n", test_nr, year);
    days_should = 6*(4*365+1)+1*(3*365+1);
    days_result = times_yyyy_to_days(year);
    diff = days_should - days_result;
    printf("     should: %d\n", days_should);
    printf("     result: %d\n", days_result);
    printf("     diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    test_nr++;
    year = 2037;
    printf("   + %02d: times_yyyy_to_days(%d)\n", test_nr, year);
    days_should = 9*(4*365+1)+1*(1*365+1);
    days_result = times_yyyy_to_days(year);
    diff = days_should - days_result;
    printf("     should: %d\n", days_should);
    printf("     result: %d\n", days_result);
    printf("     diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    return TEST_SUCCESSFUL;
}

int8_t test02(void) {
    printf(" + test02: times_days_to_yyyy()\n");
    uint32_t days, days_left_result, days_left_should;
    uint16_t year_result, year_should, test_nr;
    int16_t diff;
    
    test_nr = 1;
    days = 17;
    printf("   + %02d: times_days_to_yyyy(%d)\n", test_nr, days);
    year_should = 2000;
    days_left_result = times_days_to_yyyy(days, &year_result);
    diff = year_should - year_result;
    printf("     year\n");
    printf("       should: %d\n", year_should);
    printf("       result: %d\n", year_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    days_left_should = 17;
    diff = days_left_should - days_left_result;
    printf("     days_left\n");
    printf("       should: %d\n", days_left_result);
    printf("       result: %d\n", days_left_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    test_nr++;
    days = 366;
    printf("   + %02d: times_days_to_yyyy(%d)\n", test_nr, days);
    year_should = 2001;
    days_left_result = times_days_to_yyyy(days, &year_result);
    diff = year_should - year_result;
    printf("     year\n");
    printf("       should: %d\n", year_should);
    printf("       result: %d\n", year_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    days_left_should = 0;
    diff = days_left_should - days_left_result;
    printf("     days_left\n");
    printf("       should: %d\n", days_left_result);
    printf("       result: %d\n", days_left_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    test_nr++;
    days = 366+17;
    printf("   + %02d: times_days_to_yyyy(%d)\n", test_nr, days);
    year_should = 2001;
    days_left_result = times_days_to_yyyy(days, &year_result);
    diff = year_should - year_result;
    printf("     year\n");
    printf("       should: %d\n", year_should);
    printf("       result: %d\n", year_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    days_left_should = 17;
    diff = days_left_should - days_left_result;
    printf("     days_left\n");
    printf("       should: %d\n", days_left_result);
    printf("       result: %d\n", days_left_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    test_nr++;
    days = 1*(4*365+1)+107;
    printf("   + %02d: times_days_to_yyyy(%d)\n", test_nr, days);
    year_should = 2004;
    days_left_result = times_days_to_yyyy(days, &year_result);
    diff = year_should - year_result;
    printf("     year\n");
    printf("       should: %d\n", year_should);
    printf("       result: %d\n", year_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    days_left_should = 107;
    diff = days_left_should - days_left_result;
    printf("     days_left\n");
    printf("       should: %d\n", days_left_result);
    printf("       result: %d\n", days_left_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    test_nr++;
    days = 2*(4*365+1)+(2*365+1)+121;
    printf("   + %02d: times_days_to_yyyy(%d)\n", test_nr, days);
    year_should = 2010;
    days_left_result = times_days_to_yyyy(days, &year_result);
    diff = year_should - year_result;
    printf("     year\n");
    printf("       should: %d\n", year_should);
    printf("       result: %d\n", year_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    days_left_should = 121;
    diff = days_left_should - days_left_result;
    printf("     days_left\n");
    printf("       should: %d\n", days_left_result);
    printf("       result: %d\n", days_left_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    test_nr++;
    days = 8*(4*365+1)+(3*365+1)+360;
    printf("   + %02d: times_days_to_yyyy(%d)\n", test_nr, days);
    year_should = 2035;
    days_left_result = times_days_to_yyyy(days, &year_result);
    diff = year_should - year_result;
    printf("     year\n");
    printf("       should: %d\n", year_should);
    printf("       result: %d\n", year_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    days_left_should = 360;
    diff = days_left_should - days_left_result;
    printf("     days_left\n");
    printf("       should: %d\n", days_left_result);
    printf("       result: %d\n", days_left_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    return TEST_SUCCESSFUL;
}

int main(void) {
    printf("testing times functions\n");
    test_eval_result(test01());
    test_eval_result(test02());
    
    return 0;
}
