/**
 * Martin Egli
 * 2024-09-18
 * mmlib https://github.com/mwuerms/mmlib
 * log functions
 */

#ifndef _MM_LOG_H_
#define _MM_LOG_H_

#include <stdint.h>

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
#define LOG_LEVEL_ANY (0)
#define LOG_LEVEL_DEBUG (1) 
#define LOG_LEVEL_INFO (2)
#define LOG_LEVEL_WARNING (3)
#define LOG_LEVEL_ERROR (4)
void log_set_level(uint8_t level);

/**
 * add a uint16_t value to the log
 * @param   name    of the value
 * @param   value   to log
 */
void log_value_uint16(char *name, uint16_t value);

/**
 * add a uint32_t value to the log
 * @param   name    of the value
 * @param   value   to log
 */
void log_value_uint32(char *name, uint32_t value);

/**
 * add a float value to the log
 * @param   name    of the value
 * @param   value   to log
 */
void log_value_float(char *name, float value);

/**
 * clear the whole log
 */
void log_clear_all(void);

/**
 * read all log as csv to destination, line
 * "timestamp(YYYY-MM-DD HH:MM:SS.000);ID;Name;value"
 * @param   dest    where to send the data, eg. uart
 * @param   sep     seperator to use, standard is ';'
 */
void log_read_all_as_csv(uint8_t dest, char sep);

#endif // _MM_LOG_H_
