/**
 * Martin Egli
 * 2024-09-20
 * mmlib https://github.com/mwuerms/mmlib
 * times functions, time in seconds from a specific date: 2000-01-01 00:00:00
 */

#include "times.h"

// - private variables ---------------------------------------------------------
// 0: jan, 1: feb, 2: mar, 3: apr, 4: may, 5: jun, 6: jul, 7: aug, 8: sep, 9: oct, 10: nov, 11: dec
static const uint16_t days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// - private functions ---------------------------------------------------------
/**
 * check if given year is a leap year after year 2000, rules:
 * 1. year % 4 == 0, every 4th year, like 4, 8, 20, 24, 40, 88
 * simplyfied use only rule 1
 * 2. 100 years ar NO leap years, like 1800, 1900, 2100
 * 2a. BUT 1000 years ARE leap years, like 1000, 2000
 * @param   year    to check
 * @return  true: is leap year, false: no leap year
 */
inline static uint8_t is_leap_year(uint16_t year) {
    //if((year & 0x0003) == 0) && ((year % 100) != 0)) {
    if((year & 0x0003) == 0) {
        return true;
    }
    return false;
}


// - public functions ----------------------------------------------------------
uint32_t times_yyyymmdd_to_days(uint16_t year, uint8_t month, uint8_t day) {
    uint32_t days = 0;
    uint8_t is_leap = false;
    
    days += times_yyyy_to_days(year);
    is_leap = is_leap_year(year);
    days += times_mm_to_days(month, is_leap);
    days += day - 1; // -1 because, this day is not done yet
    return days;
}

uint32_t times_days_to_yyyymmdd(uint32_t days, uint16_t *year, uint8_t *month, uint8_t *day) {
    return 0;
}

static uint32_t days_in_year(uint16_t year) {
    if(is_leap_year(year) == true) {
        return 365+1;
    }
    return 365;
}
uint32_t times_yyyy_to_days(uint16_t year) {
    uint32_t days = 0;
    if(year <= 2000) {
        // year not covered
        return 0;
    }
    days = 0;
    for(year--;year > (2000-1); year--) {
        days += days_in_year(year);
    }
    return days;
}

uint32_t times_days_to_yyyy(uint32_t days, uint16_t *year) {
    uint32_t days_check;
    uint16_t y = 2000;
    
    days_check += days_in_year(y);
    if(days < days_check) {
        // not enough for the 1st year (2000), so stop already
        *year = y;
        return days;
    }
    while(days >= days_check) {
        y++;
        days -= days_check;
        days_check = days_in_year(y);
    }
    *year = y;
    return days;
}

uint32_t times_mm_to_days(uint8_t month, uint8_t is_leap) {
    return 0;
}

uint8_t times_days_to_mm(uint32_t days, uint8_t is_leap) {
    return 0;
}

uint32_t times_secs_to_days(uint32_t secs) {
    return 0;
}

uint32_t times_days_to_secs(uint32_t days) {
    return 0;
}

uint32_t times_hhmmss_to_secs(uint8_t hour, uint8_t min, uint8_t sec) {
    return 0;
}

uint32_t times_secs_to_hhmmss(uint32_t secs, uint8_t *hour, uint8_t *min, uint8_t *sec) {
    return 0;
}

uint32_t times_yyyymmdd_hhmmss_to_secs(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t min, uint8_t sec) {
    return 0;
}

uint32_t times_secs_to_yyyymmdd_hhmmss(uint32_t secs, uint16_t *year, uint8_t *month, uint8_t *day, uint8_t *hour, uint8_t *min, uint8_t *sec) {
    return 0;
}
