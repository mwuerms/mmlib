/**
 * Martin Egli
 * 2024-09-18
 * mmlib https://github.com/mwuerms/mmlib
 * organize data for log, define how data is stored
 */

#ifndef _MM_LOG_DATA_H_
#define _MM_LOG_DATA_H_

#include <stdint.h>

/**
 * initialize log_data
 */
void log_data_init(void);
void log_data_start(void);
void log_data_stop(void);
void log_add_info(uint16_t who_am_i, uint16_t version);
void log_data_add_time(uint32_t secs);

void log_data_add_u16_value_name(int16_t tdiff, char level_char, uint16_t value, char *name4);
void log_data_add_u32_value_name(int16_t tdiff, char level_char, uint32_t value, char *name4);
void log_data_add_float_value_name(int16_t tdiff, char level_char, float value, char *name4);
void log_data_add_string(int16_t tdiff, char level_char, char *str);

#endif // _MM_LOG_DATA_H_
