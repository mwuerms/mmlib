/**
 * Martin Egli
 * 2024-09-18
 * mmlib https://github.com/mwuerms/mmlib
 * organize data for log, define how data is stored
 */

#ifndef _MM_LOG_DATA_H_
#define _MM_LOG_DATA_H_

#include <stdint.h>

#define LOG_DATA_VERSION (2)

// - public functions ----------------------------------------------------------
/**
 * initialize log_data
 */
void log_data_init(void);
void log_data_start(uint32_t start_time);
void log_data_stop(void);

void log_data_add_time(uint32_t secs);
void log_data_add_u16_value(int16_t tdiff, uint16_t value, uint8_t name_code);
void log_data_add_u32_value(int16_t tdiff, uint32_t value, uint8_t name_code);
void log_data_add_float_value(int16_t tdiff, float value, uint8_t name_code);
void log_data_add_level_code(int16_t tdiff, uint8_t level, uint8_t code);

void log_data_read_mem_page(void);

#endif // _MM_LOG_DATA_H_
