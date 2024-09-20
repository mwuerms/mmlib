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

int8_t test03(void) {
    printf(" + test03: times_mm_to_days()\n");
    uint32_t days_result, days_should, diff;
    uint8_t month, is_leap, test_nr;
    
    test_nr = 1;
    month = 1;
    is_leap = true;
    printf("   + %02d: times_mm_to_days(%d, %d)\n", test_nr, month, is_leap);
    days_should = 0;
    days_result = times_mm_to_days(month, is_leap);
    diff = days_should - days_result;
    printf("     should: %d\n", days_should);
    printf("     result: %d\n", days_result);
    printf("     diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    test_nr++;
    month = 2;
    is_leap = true;
    printf("   + %02d: times_mm_to_days(%d, %d)\n", test_nr, month, is_leap);
    days_should = 31;
    days_result = times_mm_to_days(month, is_leap);
    diff = days_should - days_result;
    printf("     should: %d\n", days_should);
    printf("     result: %d\n", days_result);
    printf("     diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    test_nr++;
    month = 3;
    is_leap = true;
    printf("   + %02d: times_mm_to_days(%d, %d)\n", test_nr, month, is_leap);
    days_should = 31+29;
    days_result = times_mm_to_days(month, is_leap);
    diff = days_should - days_result;
    printf("     should: %d\n", days_should);
    printf("     result: %d\n", days_result);
    printf("     diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    test_nr++;
    month = 4;
    is_leap = true;
    printf("   + %02d: times_mm_to_days(%d, %d)\n", test_nr, month, is_leap);
    days_should = 31+29+31;
    days_result = times_mm_to_days(month, is_leap);
    diff = days_should - days_result;
    printf("     should: %d\n", days_should);
    printf("     result: %d\n", days_result);
    printf("     diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    test_nr++;
    month = 6;
    is_leap = false;
    printf("   + %02d: times_mm_to_days(%d, %d)\n", test_nr, month, is_leap);
    days_should = 31+28+31+30+31;
    days_result = times_mm_to_days(month, is_leap);
    diff = days_should - days_result;
    printf("     should: %d\n", days_should);
    printf("     result: %d\n", days_result);
    printf("     diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    test_nr++;
    month = 8;
    is_leap = true;
    printf("   + %02d: times_mm_to_days(%d, %d)\n", test_nr, month, is_leap);
    days_should = 31+29+31+30+31+30+31;
    days_result = times_mm_to_days(month, is_leap);
    diff = days_should - days_result;
    printf("     should: %d\n", days_should);
    printf("     result: %d\n", days_result);
    printf("     diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    test_nr++;
    month = 11;
    is_leap = false;
    printf("   + %02d: times_mm_to_days(%d, %d)\n", test_nr, month, is_leap);
    days_should = 31+28+31+30+31+30+31+31+30+31;
    days_result = times_mm_to_days(month, is_leap);
    diff = days_should - days_result;
    printf("     should: %d\n", days_should);
    printf("     result: %d\n", days_result);
    printf("     diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    test_nr++;
    month = 12;
    is_leap = false;
    printf("   + %02d: times_mm_to_days(%d, %d)\n", test_nr, month, is_leap);
    days_should = 31+28+31+30+31+30+31+31+30+31+30;
    days_result = times_mm_to_days(month, is_leap);
    diff = days_should - days_result;
    printf("     should: %d\n", days_should);
    printf("     result: %d\n", days_result);
    printf("     diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    
    return TEST_SUCCESSFUL;
}

int8_t test04(void) {
    printf(" + test04: times_days_to_mm()\n");
    uint32_t days, days_left_result, days_left_should;
    uint8_t month_result, month_should, test_nr, is_leap;
    int8_t diff;
    
    test_nr = 1;
    days = 17;
    is_leap = true;
    printf("   + %02d: times_days_to_mm(%d, %d)\n", test_nr, days, is_leap);
    month_should = 1;
    days_left_result = times_days_to_mm(days, &month_result, is_leap);
    diff = month_should - month_result;
    printf("     month\n");
    printf("       should: %d\n", month_should);
    printf("       result: %d\n", month_result);
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
    days = 37;
    is_leap = true;
    printf("   + %02d: times_days_to_mm(%d, %d)\n", test_nr, days, is_leap);
    month_should = 2;
    days_left_result = times_days_to_mm(days, &month_result, is_leap);
    diff = month_should - month_result;
    printf("     month\n");
    printf("       should: %d\n", month_should);
    printf("       result: %d\n", month_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    days_left_should = 37-31;
    diff = days_left_should - days_left_result;
    printf("     days_left\n");
    printf("       should: %d\n", days_left_result);
    printf("       result: %d\n", days_left_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    test_nr++;
    days = 121;
    is_leap = true;
    printf("   + %02d: times_days_to_mm(%d, %d)\n", test_nr, days, is_leap);
    month_should = 5;
    days_left_result = times_days_to_mm(days, &month_result, is_leap);
    diff = month_should - month_result;
    printf("     month\n");
    printf("       should: %d\n", month_should);
    printf("       result: %d\n", month_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    days_left_should = 0;
    diff = days_left_should - days_left_result;
    printf("     days_left\n");
    printf("       should: %d\n", days_left_should);
    printf("       result: %d\n", days_left_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    test_nr++;
    days = 125;
    is_leap = true;
    printf("   + %02d: times_days_to_mm(%d, %d)\n", test_nr, days, is_leap);
    month_should = 5;
    days_left_result = times_days_to_mm(days, &month_result, is_leap);
    diff = month_should - month_result;
    printf("     month\n");
    printf("       should: %d\n", month_should);
    printf("       result: %d\n", month_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    days_left_should = 4;
    diff = days_left_should - days_left_result;
    printf("     days_left\n");
    printf("       should: %d\n", days_left_should);
    printf("       result: %d\n", days_left_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    test_nr++;
    days = 325;
    is_leap = true;
    printf("   + %02d: times_days_to_mm(%d, %d)\n", test_nr, days, is_leap);
    month_should = 11;
    days_left_result = times_days_to_mm(days, &month_result, is_leap);
    diff = month_should - month_result;
    printf("     month\n");
    printf("       should: %d\n", month_should);
    printf("       result: %d\n", month_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    days_left_should = 20;
    diff = days_left_should - days_left_result;
    printf("     days_left\n");
    printf("       should: %d\n", days_left_should);
    printf("       result: %d\n", days_left_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    test_nr++;
    days = 354;
    is_leap = true;
    printf("   + %02d: times_days_to_mm(%d, %d)\n", test_nr, days, is_leap);
    month_should = 12;
    days_left_result = times_days_to_mm(days, &month_result, is_leap);
    diff = month_should - month_result;
    printf("     month\n");
    printf("       should: %d\n", month_should);
    printf("       result: %d\n", month_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    days_left_should = 19;
    diff = days_left_should - days_left_result;
    printf("     days_left\n");
    printf("       should: %d\n", days_left_should);
    printf("       result: %d\n", days_left_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    return TEST_SUCCESSFUL;
}

int8_t test05(void) {
    printf(" + test05 times_yyyymmdd_to_days() and  times_days_to_yyyymmdd()\n");
    uint32_t days_result, days_should, days_left, diff;
    uint16_t year_result, year_should;
    uint8_t  month_result, month_should, day_result, day_should, test_nr;
    
    test_nr = 1;
    year_should = 2004;
    month_should = 5;
    day_should = 10;
    printf("   + %02d: times_yyyymmdd_to_days(%d, %d, %d)\n", test_nr, year_should, month_should, day_should);
    days_should = 1591;
    days_result = times_yyyymmdd_to_days(year_should, month_should, day_should);
    diff = days_should - days_result;
    printf("     days\n");
    printf("       should: %d\n", days_should);
    printf("       result: %d\n", days_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    printf("   + %02d: times_days_to_yyyymmdd(%d)\n", test_nr, days_result);
    test_nr++;
    days_left = times_days_to_yyyymmdd(days_result, &year_result, &month_result, &day_result);
    diff = year_should - year_result;
    printf("     year\n");
    printf("       should: %d\n", year_should);
    printf("       result: %d\n", year_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    diff = month_should - month_result;
    printf("     month\n");
    printf("       should: %d\n", month_should);
    printf("       result: %d\n", month_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    diff = day_should - day_result;
    printf("     day\n");
    printf("       should: %d\n", day_should);
    printf("       result: %d\n", day_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    printf("     days_left: %d\n", days_left);
    if(days_left != 0) {
        return TEST_FAILED;
    }
    test_nr++;
    year_should = 2012;
    month_should = 8;
    day_should = 20;
    printf("   + %02d: times_yyyymmdd_to_days(%d, %d, %d)\n", test_nr, year_should, month_should, day_should);
    days_should = 4615;
    days_result = times_yyyymmdd_to_days(year_should, month_should, day_should);
    diff = days_should - days_result;
    printf("     days\n");
    printf("       should: %d\n", days_should);
    printf("       result: %d\n", days_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    printf("   + %02d: times_days_to_yyyymmdd(%d)\n", test_nr, days_result);
    test_nr++;
    days_left = times_days_to_yyyymmdd(days_result, &year_result, &month_result, &day_result);
    diff = year_should - year_result;
    printf("     year\n");
    printf("       should: %d\n", year_should);
    printf("       result: %d\n", year_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    diff = month_should - month_result;
    printf("     month\n");
    printf("       should: %d\n", month_should);
    printf("       result: %d\n", month_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    diff = day_should - day_result;
    printf("     day\n");
    printf("       should: %d\n", day_should);
    printf("       result: %d\n", day_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    printf("     days_left: %d\n", days_left);
    if(days_left != 0) {
        return TEST_FAILED;
    }
    test_nr++;
    year_should = 2015;
    month_should = 1;
    day_should = 19;
    printf("   + %02d: times_yyyymmdd_to_days(%d, %d, %d)\n", test_nr, year_should, month_should, day_should);
    days_should = 5497;
    days_result = times_yyyymmdd_to_days(year_should, month_should, day_should);
    diff = days_should - days_result;
    printf("     days\n");
    printf("       should: %d\n", days_should);
    printf("       result: %d\n", days_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    printf("   + %02d: times_days_to_yyyymmdd(%d)\n", test_nr, days_result);
    test_nr++;
    days_left = times_days_to_yyyymmdd(days_result, &year_result, &month_result, &day_result);
    diff = year_should - year_result;
    printf("     year\n");
    printf("       should: %d\n", year_should);
    printf("       result: %d\n", year_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    diff = month_should - month_result;
    printf("     month\n");
    printf("       should: %d\n", month_should);
    printf("       result: %d\n", month_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    diff = day_should - day_result;
    printf("     day\n");
    printf("       should: %d\n", day_should);
    printf("       result: %d\n", day_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    printf("     days_left: %d\n", days_left);
    if(days_left != 0) {
        return TEST_FAILED;
    }
    test_nr++;
    year_should = 2024;
    month_should = 9;
    day_should = 20;
    printf("   + %02d: times_yyyymmdd_to_days(%d, %d, %d)\n", test_nr, year_should, month_should, day_should);
    days_should = 9029;
    days_result = times_yyyymmdd_to_days(year_should, month_should, day_should);
    diff = days_should - days_result;
    printf("     days\n");
    printf("       should: %d\n", days_should);
    printf("       result: %d\n", days_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    printf("   + %02d: times_days_to_yyyymmdd(%d)\n", test_nr, days_result);
    test_nr++;
    days_left = times_days_to_yyyymmdd(days_result, &year_result, &month_result, &day_result);
    diff = year_should - year_result;
    printf("     year\n");
    printf("       should: %d\n", year_should);
    printf("       result: %d\n", year_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    diff = month_should - month_result;
    printf("     month\n");
    printf("       should: %d\n", month_should);
    printf("       result: %d\n", month_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    diff = day_should - day_result;
    printf("     day\n");
    printf("       should: %d\n", day_should);
    printf("       result: %d\n", day_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    printf("     days_left: %d\n", days_left);
    if(days_left != 0) {
        return TEST_FAILED;
    }
    return TEST_SUCCESSFUL;
}

int8_t test06(void) {
    printf(" + test06 times_days_to_secs() and times_secs_to_days()\n");
    uint32_t days_result, days_should, secs_result, secs_should, diff;
    uint8_t  test_nr;
    
    test_nr = 1;
    days_should = 10;
    secs_should = 10*86400;
    printf("   + %02d: times_days_to_secs(%d)\n", test_nr, days_should);
    secs_result = times_days_to_secs(days_should);
    diff = secs_should - secs_result;
    printf("     secs\n");
    printf("       should: %d\n", secs_should);
    printf("       result: %d\n", secs_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    printf("   + %02d: times_secs_to_days(%d)\n", test_nr, secs_result);
    days_result = times_secs_to_days(secs_should);
    diff = days_should - days_result;
    printf("     days\n");
    printf("       should: %d\n", days_should);
    printf("       result: %d\n", days_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    test_nr++;
    days_should = 45780;
    secs_should = 45780*86400UL;
    printf("   + %02d: times_days_to_secs(%u)\n", test_nr, days_should);
    secs_result = times_days_to_secs(days_should);
    diff = secs_should - secs_result;
    printf("     secs\n");
    printf("       should: %u\n", secs_should);
    printf("       result: %u\n", secs_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    printf("   + %02d: times_secs_to_days(%u)\n", test_nr, secs_result);
    days_result = times_secs_to_days(secs_should);
    diff = days_should - days_result;
    printf("     days\n");
    printf("       should: %d\n", days_should);
    printf("       result: %d\n", days_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    return TEST_SUCCESSFUL;
}

int8_t test07(void) {
    printf(" + test07 times_hhmmss_to_secs() and times_secs_to_hhmmss()\n");
    uint32_t secs_result, secs_should, secs_left, diff;
    uint8_t  hour_result, hour_should, min_result, min_should, sec_result, sec_should, test_nr;
    
    test_nr = 1;
    hour_should = 10;
    min_should = 59;
    sec_should = 37;
    secs_should = hour_should*3600UL + min_should*60 + sec_should;
    printf("   + %02d: times_hhmmss_to_secs(%02d:%02d:%02d)\n", test_nr, hour_should, min_should, sec_should);
    secs_result = times_hhmmss_to_secs(hour_should, min_should, sec_should);
    diff = secs_should - secs_result;
    printf("     secs\n");
    printf("       should: %d\n", secs_should);
    printf("       result: %d\n", secs_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    printf("   + %02d: times_secs_to_hhmmss(%d)\n", test_nr, secs_result);
    secs_left = times_secs_to_hhmmss(secs_result, &hour_result, &min_result, &sec_result);
    diff = hour_should - hour_result;
    printf("     hour\n");
    printf("       should: %d\n", hour_should);
    printf("       result: %d\n", hour_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    diff = min_should - min_result;
    printf("     min\n");
    printf("       should: %d\n", min_should);
    printf("       result: %d\n", min_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    diff = sec_should - sec_result;
    printf("     sec\n");
    printf("       should: %d\n", sec_should);
    printf("       result: %d\n", sec_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    printf("     secs_left:   %d\n", secs_left);
    if(secs_left != 0) {
        return TEST_FAILED;
    }
    test_nr++;
    hour_should = 123;
    min_should = 59;
    sec_should = 59;
    secs_should = hour_should*3600UL + min_should*60 + sec_should;
    printf("   + %02d: times_hhmmss_to_secs(%02d:%02d:%02d)\n", test_nr, hour_should, min_should, sec_should);
    printf("     this is a valid test, but should not occour\n");
    secs_result = times_hhmmss_to_secs(hour_should, min_should, sec_should);
    diff = secs_should - secs_result;
    printf("     secs\n");
    printf("       should: %d\n", secs_should);
    printf("       result: %d\n", secs_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    printf("   + %02d: times_secs_to_hhmmss(%d)\n", test_nr, secs_result);
    secs_left = times_secs_to_hhmmss(secs_result, &hour_result, &min_result, &sec_result);
    diff = hour_should - hour_result;
    printf("     hour\n");
    printf("       should: %d\n", hour_should);
    printf("       result: %d\n", hour_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    diff = min_should - min_result;
    printf("     min\n");
    printf("       should: %d\n", min_should);
    printf("       result: %d\n", min_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    diff = sec_should - sec_result;
    printf("     sec\n");
    printf("       should: %d\n", sec_should);
    printf("       result: %d\n", sec_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    printf("     secs_left:   %d\n", secs_left);
    if(secs_left != 0) {
        return TEST_FAILED;
    }
    test_nr++;
    return TEST_SUCCESSFUL;
}

int8_t test08(void) {
    printf(" + test08 times_yyyymmdd_hhmmss_to_secs() and  times_secs_to_yyyymmdd_hhmmss()\n");
    uint32_t days_result, days_should, secs_result, secs_should, secs_left, diff;
    uint16_t year_result, year_should;
    uint8_t  month_result, month_should, day_result, day_should;
    uint8_t  hour_result, hour_should, min_result, min_should, sec_result, sec_should, test_nr;
    
    test_nr = 1;
    year_should = 2004;
    month_should = 5;
    day_should = 10;
    hour_should = 17;
    min_should = 34;
    sec_should = 10;
    printf("   + %02d: times_yyyymmdd_hhmmss_to_secs(%d-%02d-%02d %02d:%02d:%02d)\n", test_nr, year_should, month_should, day_should, hour_should, min_should, sec_should);
    days_should  = 1591;
    secs_should  = times_days_to_secs(days_should);
    secs_should += times_hhmmss_to_secs(hour_should, min_should, sec_should);
    secs_result = times_yyyymmdd_hhmmss_to_secs(year_should, month_should, day_should, hour_should, min_should, sec_should);
    diff = secs_should - secs_result;
    printf("     secs\n");
    printf("       should: %u\n", secs_should);
    printf("       result: %u\n", secs_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    printf("   + %02d: times_secs_to_yyyymmdd_hhmmss(%d)\n", test_nr, secs_result);
    test_nr++;
    secs_left = times_secs_to_yyyymmdd_hhmmss(secs_result, &year_result, &month_result, &day_result, &hour_result, &min_result, &sec_result);
    diff = year_should - year_result;
    printf("     year\n");
    printf("       should: %d\n", year_should);
    printf("       result: %d\n", year_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    diff = month_should - month_result;
    printf("     month\n");
    printf("       should: %d\n", month_should);
    printf("       result: %d\n", month_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    diff = day_should - day_result;
    printf("     day\n");
    printf("       should: %d\n", day_should);
    printf("       result: %d\n", day_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    diff = hour_should - hour_result;
    printf("     hour\n");
    printf("       should: %d\n", hour_should);
    printf("       result: %d\n", hour_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    diff = min_should - min_result;
    printf("     min\n");
    printf("       should: %d\n", min_should);
    printf("       result: %d\n", min_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    diff = sec_should - sec_result;
    printf("     sec\n");
    printf("       should: %d\n", sec_should);
    printf("       result: %d\n", sec_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    printf("     secs_left:   %d\n", secs_left);
    if(secs_left != 0) {
        return TEST_FAILED;
    }
    test_nr++;
    year_should = 2024;
    month_should = 9;
    day_should = 20;
    hour_should = 22;
    min_should = 52;
    sec_should = 56;
    printf("   + %02d: times_yyyymmdd_hhmmss_to_secs(%d-%02d-%02d %02d:%02d:%02d)\n", test_nr, year_should, month_should, day_should, hour_should, min_should, sec_should);
    days_should  = 9029;
    secs_should  = times_days_to_secs(days_should);
    secs_should += times_hhmmss_to_secs(hour_should, min_should, sec_should);
    secs_result = times_yyyymmdd_hhmmss_to_secs(year_should, month_should, day_should, hour_should, min_should, sec_should);
    diff = secs_should - secs_result;
    printf("     secs\n");
    printf("       should: %u\n", secs_should);
    printf("       result: %u\n", secs_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    printf("   + %02d: times_secs_to_yyyymmdd_hhmmss(%d)\n", test_nr, secs_result);
    test_nr++;
    secs_left = times_secs_to_yyyymmdd_hhmmss(secs_result, &year_result, &month_result, &day_result, &hour_result, &min_result, &sec_result);
    diff = year_should - year_result;
    printf("     year\n");
    printf("       should: %d\n", year_should);
    printf("       result: %d\n", year_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    diff = month_should - month_result;
    printf("     month\n");
    printf("       should: %d\n", month_should);
    printf("       result: %d\n", month_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    diff = day_should - day_result;
    printf("     day\n");
    printf("       should: %d\n", day_should);
    printf("       result: %d\n", day_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    diff = hour_should - hour_result;
    printf("     hour\n");
    printf("       should: %d\n", hour_should);
    printf("       result: %d\n", hour_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    diff = min_should - min_result;
    printf("     min\n");
    printf("       should: %d\n", min_should);
    printf("       result: %d\n", min_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    diff = sec_should - sec_result;
    printf("     sec\n");
    printf("       should: %d\n", sec_should);
    printf("       result: %d\n", sec_result);
    printf("       diff:   %d\n", diff);
    if(diff != 0) {
        return TEST_FAILED;
    }
    printf("     secs_left:   %d\n", secs_left);
    if(secs_left != 0) {
        return TEST_FAILED;
    }
    return TEST_SUCCESSFUL;
}

int main(void) {
    printf("testing times functions\n");
    test_eval_result(test01());
    test_eval_result(test02());
    test_eval_result(test03());
    test_eval_result(test04());
    test_eval_result(test05());
    test_eval_result(test06());
    test_eval_result(test07());
    test_eval_result(test08());
    return 0;
}
