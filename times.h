/**
 * Martin Egli
 * 2024-09-20
 * mmlib https://github.com/mwuerms/mmlib
 * times functions, time in seconds from a specific date: 2000-01-01 00:00:00
 */

#ifndef _MM_TIMES_H_
#define _MM_TIMES_H_

#include <stdint.h>
#include <stdbool.h>

/**
 * convert a date in yyyy-mm-dd format to days
 * @param   year    eg. 2024
 * @param   month   1: jan, 2: feb, ... 12: dec
 * @param   day     1 ... 31
 * @return  days of date from start date 2000-01-01 00:00:00
 */
uint32_t times_yyyymmdd_to_days(uint16_t year, uint8_t month, uint8_t day);

/**
 * convert days back to a date in yyyy-mm-dd format
 * @param   days    of date from start date 2000-01-01 00:00:00
 * @param   year    eg. 2024
 * @param   month   1: jan, 2: feb, ... 12: dec
 * @param   day     1 ... 31
 * @return
 */
uint32_t times_days_to_yyyymmdd(uint32_t days, uint16_t *year, uint8_t *month, uint8_t *day);

/**
 * convert a year to days
 * @param   year    eg. 2024
 * @return  days of date from start date 2000-01-01 00:00:00
 */
uint32_t times_yyyy_to_days(uint16_t year);

/**
 * convert days back to a year
 * @param   days    to calc year from
 * @return  year    eg. 2024
 */
uint16_t times_days_to_yyyy(uint32_t days);

/**
 * convert a month to days
 * @param   month   1: jan, 2: feb, ... 12: dec
 * @param   is_leap this is a leap year
 * @return  days of the elapsed month before, 1 (jan)=0, 2(feb)=31, 3(mar)=31+28(+1, leap)
 */
uint32_t times_mm_to_days(uint8_t month, uint8_t is_leap);

/**
 * convert days back to a month
 * @param   days    to calc month from
 * @param   is_leap this is a leap year
 * @return  month   eg. 2024
 */
uint8_t times_days_to_mm(uint32_t days, uint8_t is_leap);

/**
 * convert seconds to days
 * @param   secs
 * @return  days
 */
uint32_t times_secs_to_days(uint32_t secs);

/**
 * convert days to seconds
 * @param   days
 * @return  seconds
 */
uint32_t times_days_to_secs(uint32_t days);

/**
 * convert a time in hh:mm:ss format to secs
 * @param   hour    0 ... 23
 * @param   min     0 ... 59
 * @param   sec     0 ... 59
 * @return  secs of the time
 */
uint32_t times_hhmmss_to_secs(uint8_t hour, uint8_t min, uint8_t sec);

/**
 * convert secs back to a time in hh:mm:ss format
 * @param   secs of the time
 * @param   hour    0 ... 23
 * @param   min     0 ... 59
 * @param   sec     0 ... 59
 * @return  
 */
uint32_t times_secs_to_hhmmss(uint32_t secs, uint8_t *hour, uint8_t *min, uint8_t *sec);

/**
 * convert date and time in yyyy-mm-dd hh:mm:ss format to secs
 * @param   year    eg. 2024
 * @param   month   1: jan, 2: feb, ... 12: dec
 * @param   day     1 ... 31
 * @param   hour    0 ... 23
 * @param   min     0 ... 59
 * @param   sec     0 ... 59
 * @return  secs of date and time from start date 2000-01-01 00:00:00
 */
uint32_t times_yyyymmdd_hhmmss_to_secs(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t min, uint8_t sec);

/**
 * convert secs back date and time in yyyy-mm-dd hh:mm:ss format
 * @param   secs of date and time
 * @param   year    eg. 2024
 * @param   month   1: jan, 2: feb, ... 12: dec
 * @param   day     1 ... 31
 * @param   hour    0 ... 23
 * @param   min     0 ... 59
 * @param   sec     0 ... 59
 * @return  
 */
uint32_t times_secs_to_yyyymmdd_hhmmss(uint32_t secs, uint16_t *year, uint8_t *month, uint8_t *day, uint8_t *hour, uint8_t *min, uint8_t *sec);

#endif // _MM_TIMES_H_



