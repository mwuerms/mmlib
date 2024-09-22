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

// - define block ids ----------------------------------------------------------
// - common stuff
#define LOG_ID_TIME (1)
#define LOG_LEN_TIME (4) // length without ID
#define LOG_ID_INFO_CODE (2)
#define LOG_LEN_INFO_CODE (2+1) // length without ID
#define LOG_ID_WARNING_CODE (3)
#define LOG_LEN_WARNING_CODE (2+1) // length without ID
#define LOG_ID_ERROR_CODE (4)
#define LOG_LEN_ERROR_CODE (2+1) // length without ID
// - values
#define LOG_ID_U16_VALUE_NAME_CODE (10)
#define LOG_LEN_U16_VALUE_NAME_CODE (2+2+1) // length without ID
#define LOG_ID_U32_VALUE_NAME_CODE (11)
#define LOG_LEN_U32_VALUE_NAME_CODE (2+4+1) // length without ID
#define LOG_ID_FLOAT_VALUE_NAME_CODE (12)
#define LOG_LEN_FLOAT_VALUE_NAME_CODE (2+4+1) // length without ID

// - public functions ----------------------------------------------------------
/**
 * initialize log_data
 */
void log_data_init(void);
void log_data_start(void);
void log_data_stop(void);

void log_data_add_time(uint32_t secs);
void log_data_add_u16_value(int16_t tdiff, uint16_t value, uint8_t name_code);
void log_data_add_u32_value(int16_t tdiff, uint32_t value, uint8_t name_code);
void log_data_add_float_value(int16_t tdiff, float value, uint8_t name_code);
void log_data_add_level_code(int16_t tdiff, uint8_t level, uint8_t code);


#endif // _MM_LOG_DATA_H_
