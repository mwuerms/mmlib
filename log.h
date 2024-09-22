/**
 * Martin Egli
 * 2024-09-18
 * mmlib https://github.com/mwuerms/mmlib
 * log functions
 */

#ifndef _MM_LOG_H_
#define _MM_LOG_H_

#include <stdint.h>
#include "mmlib.h"

/**
 * initialize the log
 */
void log_init(void);

/**
 * start the log
 */
void log_start(void);

/**
 * stop the log
 */
void log_stop(void);

/**
 * set the log level
 * @param   level   to set
 */
#define LOG_LEVEL_INFO (0)
#define LOG_LEVEL_INFO_CHAR 'I'
#define LOG_LEVEL_WARNING (1)
#define LOG_LEVEL_WARNING_CHAR 'W'
#define LOG_LEVEL_ERROR (2)
#define LOG_LEVEL_ERROR_CHAR 'E'
#define LOG_LEVEL_VALUE (3)
#define LOG_LEVEL_VALUE_CHAR 'V'
#define LOG_LEVEL_MAX LOG_LEVEL_VALUE

void log_set_level(uint8_t level);

/**
 * add a uint16_t value to the log
 * always level value
 * @param   value   to log
 * @param   name4   of the value, max 4 chars
 */
void log_uint16_value(uint16_t value, uint8_t name_code);

/**
 * add a uint32_t value to the log
 * always level value
 * @param   value   to log
 * @param   name4   of the value, max 4 chars
 */
void log_uint32_value(uint32_t value, uint8_t name_code);

/**
 * add a float value to the log
 * always level value
 * @param   value   to log
 * @param   name4   of the value, max 4 chars
 */
void log_float_value(float value, uint8_t name_code);

/**
 * add a message to the log, filter by given level
 * level, log only >= current level
 * @param   level       see. LOG_LEVEL_
 * @param   msg_code    message code to log
 */
void log_msg_code(uint8_t level, uint8_t msg_code);

/**
 * clear the whole log
 */
void log_clear_all(void);

/**
 * read all log as csv to destination, line
 * log_stop() before read
 * "timestamp(YYYY-MM-DD HH:MM:SS.000);Level;Data"
 * @param   dest    where to send the data, eg. uart
 * @param   sep     seperator to use, standard is ';'
 */
void log_read_all_as_csv(uint8_t dest);

/**
 * read all log as csv to destination, line
 * "timestamp(YYYY-MM-DD HH:MM:SS.000);ID;Name;value"
 * @param   dest    where to send the data, eg. uart
 * @param   sep     seperator to use, standard is ';'
 */
#define LOG_READ_LEVEL_MASK_ALL (0xFF)
#define LOG_READ_LEVEL_MASK_DEBUG BITV(1)
#define LOG_READ_LEVEL_MASK_INFO BITV(2)
#define LOG_READ_LEVEL_MASK_WARNING BITV(3)
#define LOG_READ_LEVEL_MASK_ERROR BITV(4)
#define LOG_READ_LEVEL_MASK_VALUE BITV(5)
#define LOG_READ_TIME_FORMAT_SECS (0)
#define LOG_READ_TIME_FORMAT_YYYMMDD_HHMMSS (1)
void log_read_as_csv(uint8_t dest, uint8_t level_mask, uint8_t time_format, char sep);

#endif // _MM_LOG_H_
