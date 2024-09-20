/**
 * Martin Egli
 * 2024-09-20
 * mmlib https://github.com/mwuerms/mmlib
 * times functions, time in seconds from a specific date: 2000-01-01 00:00:00
 */

#include "times.h"

// - private variables ---------------------------------------------------------
// 0: unused, 1:jan, 2: feb, 3: mar, 4: apr, 5: may, 6: jun, 7: jul, 8: aug, 9: sep, 10: oct, 11: nov, 12: dec
static const uint16_t days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static const uint32_t secs_in_day = 86400UL; // 24*60*30

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
    uint16_t y;
    uint8_t m, d, is_leap;
    days = times_days_to_yyyy(days, &y);
    is_leap = is_leap_year(y);
    days = times_days_to_mm(days, &m, is_leap);
    d = days +1;
    days -= d - 1;

    *year = y;
    *month = m;
    *day = d;
    return days;
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
    
    days_check = days_in_year(y);
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
    uint32_t days = 0;
    if(month <= 1) {
        // invalid or jan
        return 0;
    }
    if(month > 12) {
        // more than dec
        return 0;
    }
    for(month--;month != 0; month--) {
        days += days_in_month[month];
        if((month == 2) && (is_leap == true)) {
            days++;
        }
    }
    return days;
}

uint32_t times_days_to_mm(uint32_t days, uint8_t *month, uint8_t is_leap) {
    uint32_t days_check;
    uint8_t m = 1;

    for(m = 1; m < 12; m++) {
        days_check = days_in_month[m];
        if((m == 2) && (is_leap == true)) {
            days_check++;
        }
        if(days >= days_check) {
            // more than this month, continue
            days -= days_check;
        }
        else {
            // done here
            break;
        }
    }
    *month = m;
    return days;
}

uint32_t times_secs_to_days(uint32_t secs) {
    return secs / secs_in_day;
}

uint32_t times_days_to_secs(uint32_t days) {
    return days * secs_in_day;
}

uint32_t times_hhmmss_to_secs(uint8_t hour, uint8_t min, uint8_t sec) {
    uint32_t secs;
    secs  = hour * 3600UL;
    secs += min * 60UL;
    secs += sec;
    return secs;
}

uint32_t times_secs_to_hhmmss(uint32_t secs, uint8_t *hour, uint8_t *min, uint8_t *sec) {
    uint8_t h, m;
    h = secs / 3600UL;
    secs -= h * 3600UL;
    m = secs / 60UL;
    secs -= m * 60UL;
    *hour = h;
    *min = m;
    *sec = secs;
    return 0;
}

uint32_t times_yyyymmdd_hhmmss_to_secs(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t min, uint8_t sec) {
    uint32_t days, secs;
    days  = times_yyyymmdd_to_days(year, month, day);
    secs  = times_days_to_secs(days);
    secs += times_hhmmss_to_secs(hour, min, sec);
    return secs;
}
#include <stdio.h>
uint32_t times_secs_to_yyyymmdd_hhmmss(uint32_t secs, uint16_t *year, uint8_t *month, uint8_t *day, uint8_t *hour, uint8_t *min, uint8_t *sec) {
    uint32_t days;
    days  = times_secs_to_days(secs);
    secs -= times_days_to_secs(days);

    days = times_days_to_yyyymmdd(days, year, month, day);
    secs = times_secs_to_hhmmss(secs, hour, min, sec);
    return secs;
}
