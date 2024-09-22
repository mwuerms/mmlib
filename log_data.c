/**
 * Martin Egli
 * 2024-09-18
 * mmlib https://github.com/mwuerms/mmlib
 * organize data for log, define how data is stored, encode and decode data
 */

#include "log.h"
#include "log_data.h"
#include "times.h"
#include "mem.h"

#define LOG_BLOCK_SIZE (64)
static uint8_t log_block_buffer[LOG_BLOCK_SIZE];
static uint8_t log_block_pos;

void log_data_init(void) {
    return;
}

void log_data_start(void) {
    mem_start(0xDEADF00D);
}

void log_data_stop(void) {
    mem_stop();
}

/**
 * add time
 */
void log_data_add_time(uint32_t secs) {
    //secs = times_yyyymmdd_hhmmss_to_secs(2024, 9, 21, 11, 46, 17);
    log_block_pos = 0;
    log_block_buffer[log_block_pos++] = LOG_ID_TIME; // ID
    log_block_buffer[log_block_pos++] = ((uint8_t *)&secs)[3];
    log_block_buffer[log_block_pos++] = ((uint8_t *)&secs)[2];
    log_block_buffer[log_block_pos++] = ((uint8_t *)&secs)[1];
    log_block_buffer[log_block_pos++] = ((uint8_t *)&secs)[0];
    mem_add_data_to_page_wr_buffer(log_block_buffer, log_block_pos);
}

void log_data_add_u16_value(int16_t tdiff, uint16_t value, uint8_t name_code) {
    log_block_pos = 0;
    log_block_buffer[log_block_pos++] = LOG_ID_U16_VALUE_NAME_CODE; // ID
    log_block_buffer[log_block_pos++] = ((uint8_t *)&tdiff)[1];
    log_block_buffer[log_block_pos++] = ((uint8_t *)&tdiff)[0];
    log_block_buffer[log_block_pos++] = ((uint8_t *)&value)[1]; // actual value
    log_block_buffer[log_block_pos++] = ((uint8_t *)&value)[0];
    log_block_buffer[log_block_pos++] = name_code;
    mem_add_data_to_page_wr_buffer(log_block_buffer, log_block_pos);
}

void log_data_add_u32_value(int16_t tdiff, uint32_t value, uint8_t name_code) {
    log_block_pos = 0;
    log_block_buffer[log_block_pos++] = LOG_ID_U32_VALUE_NAME_CODE; // ID
    log_block_buffer[log_block_pos++] = ((uint8_t *)&tdiff)[1];
    log_block_buffer[log_block_pos++] = ((uint8_t *)&tdiff)[0];
    log_block_buffer[log_block_pos++] = ((uint8_t *)&value)[3]; // actual value
    log_block_buffer[log_block_pos++] = ((uint8_t *)&value)[2];
    log_block_buffer[log_block_pos++] = ((uint8_t *)&value)[1];
    log_block_buffer[log_block_pos++] = ((uint8_t *)&value)[0];
    log_block_buffer[log_block_pos++] = name_code;
    mem_add_data_to_page_wr_buffer(log_block_buffer, log_block_pos);
}

void log_data_add_float_value(int16_t tdiff, float value, uint8_t name_code) {
    log_block_pos = 0;
    log_block_buffer[log_block_pos++] = LOG_ID_FLOAT_VALUE_NAME_CODE; // ID
    log_block_buffer[log_block_pos++] = ((uint8_t *)&tdiff)[1];
    log_block_buffer[log_block_pos++] = ((uint8_t *)&tdiff)[0];
    log_block_buffer[log_block_pos++] = ((uint8_t *)&value)[3]; // actual value
    log_block_buffer[log_block_pos++] = ((uint8_t *)&value)[2];
    log_block_buffer[log_block_pos++] = ((uint8_t *)&value)[1];
    log_block_buffer[log_block_pos++] = ((uint8_t *)&value)[0];
    log_block_buffer[log_block_pos++] = name_code;
    mem_add_data_to_page_wr_buffer(log_block_buffer, log_block_pos);
}

static const uint8_t level_id_code[] = {LOG_ID_INFO_CODE, LOG_ID_WARNING_CODE, LOG_ID_ERROR_CODE};
void log_data_add_level_code(int16_t tdiff, uint8_t level, uint8_t code) {
    log_block_pos = 0;
    // level: check in calling function for valid value
    log_block_buffer[log_block_pos++] = level_id_code[level]; // ID
    log_block_buffer[log_block_pos++] = ((uint8_t *)&tdiff)[1];
    log_block_buffer[log_block_pos++] = ((uint8_t *)&tdiff)[0];
    log_block_buffer[log_block_pos++] = code;
    mem_add_data_to_page_wr_buffer(log_block_buffer, log_block_pos);
}
