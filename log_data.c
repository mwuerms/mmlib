/**
 * Martin Egli
 * 2024-09-18
 * mmlib https://github.com/mwuerms/mmlib
 * organize data for log, define how data is stored, encode and decode data
 */

#include "log_data.h"
#include "times.h"
#include "mem.h"

#define LOG_BLOCK_SIZE (64)
static uint8_t log_block_buffer[LOG_BLOCK_SIZE];
static uint8_t log_block_pos;

// - define block ids ----------------------------------------------------------
// - common stuff
#define LOG_ID_INFO (1)
#define LOG_ID_TIME (2)
// - values
#define LOG_ID_VALUE_U16_NAME (10)
#define LOG_ID_VALUE_U32_NAME (11)
#define LOG_ID_VALUE_FLOAT_NAME (12)
// - strings
#define LOG_ID_STRING (20)

void log_data_init(void) {
    return;
}

void log_data_start(void) {
    
}

void log_data_stop(void) {
    
}

/**
 * add info
 */
void log_add_info(uint16_t who_am_i, uint16_t version) {
    log_block_pos = 0;
    log_block_buffer[log_block_pos++] = LOG_ID_INFO; // ID
    log_block_buffer[log_block_pos++] = 0x00; // block data length
    log_block_buffer[log_block_pos++] = 0x12; // who am I
    log_block_buffer[log_block_pos++] = 0x34;
    log_block_buffer[log_block_pos++] = 0x01; // Version, H
    log_block_buffer[log_block_pos++] = 0x00; // L
    mem_add_data_to_page_wr_buffer(log_block_buffer, log_block_pos);
}

/**
 * add time
 */
void log_data_add_time(uint32_t secs) {
    //secs = times_yyyymmdd_hhmmss_to_secs(2024, 9, 21, 11, 46, 17);
    log_block_pos = 0;
    log_block_buffer[log_block_pos++] = LOG_ID_TIME; // ID
    log_block_buffer[log_block_pos++] = 4; // block data length
    log_block_buffer[log_block_pos++] = ((uint8_t *)&secs)[3];
    log_block_buffer[log_block_pos++] = ((uint8_t *)&secs)[2];
    log_block_buffer[log_block_pos++] = ((uint8_t *)&secs)[1];
    log_block_buffer[log_block_pos++] = ((uint8_t *)&secs)[0];
    mem_add_data_to_page_wr_buffer(log_block_buffer, log_block_pos);
}

void log_data_add_u16_value_name(int16_t tdiff, char level_char, uint16_t value, char *name4) {
    log_block_pos = 0;
    log_block_buffer[log_block_pos++] = LOG_ID_VALUE_U16_NAME; // ID
    log_block_buffer[log_block_pos++] = 2+1+2+4; // block data length
    log_block_buffer[log_block_pos++] = ((uint8_t *)&tdiff)[1];
    log_block_buffer[log_block_pos++] = ((uint8_t *)&tdiff)[0];
    log_block_buffer[log_block_pos++] = level_char;
    log_block_buffer[log_block_pos++] = ((uint8_t *)&value)[1]; // actual value
    log_block_buffer[log_block_pos++] = ((uint8_t *)&value)[0];
    log_block_buffer[log_block_pos++] = name4[3]; // name, only 4 bytes, no '\0'
    log_block_buffer[log_block_pos++] = name4[2];
    log_block_buffer[log_block_pos++] = name4[1];
    log_block_buffer[log_block_pos++] = name4[0];
    mem_add_data_to_page_wr_buffer(log_block_buffer, log_block_pos);
}

void log_data_add_u32_value_name(int16_t tdiff, char level_char, uint32_t value, char *name4) {
    log_block_pos = 0;
    log_block_buffer[log_block_pos++] = LOG_ID_VALUE_U32_NAME; // ID
    log_block_buffer[log_block_pos++] = 2+1+4+4; // block data length
    log_block_buffer[log_block_pos++] = ((uint8_t *)&tdiff)[1];
    log_block_buffer[log_block_pos++] = ((uint8_t *)&tdiff)[0];
    log_block_buffer[log_block_pos++] = level_char;
    log_block_buffer[log_block_pos++] = ((uint8_t *)&value)[3]; // actual value
    log_block_buffer[log_block_pos++] = ((uint8_t *)&value)[2];
    log_block_buffer[log_block_pos++] = ((uint8_t *)&value)[1];
    log_block_buffer[log_block_pos++] = ((uint8_t *)&value)[0];
    log_block_buffer[log_block_pos++] = name4[3]; // name, only 4 bytes, no '\0'
    log_block_buffer[log_block_pos++] = name4[2];
    log_block_buffer[log_block_pos++] = name4[1];
    log_block_buffer[log_block_pos++] = name4[0];
    mem_add_data_to_page_wr_buffer(log_block_buffer, log_block_pos);
}

void log_data_add_float_value_name(int16_t tdiff, char level_char, float value, char *name4) {
    log_block_pos = 0;
    log_block_buffer[log_block_pos++] = LOG_ID_VALUE_FLOAT_NAME; // ID
    log_block_buffer[log_block_pos++] = 2+1+4+4; // block data length
    log_block_buffer[log_block_pos++] = ((uint8_t *)&tdiff)[1];
    log_block_buffer[log_block_pos++] = ((uint8_t *)&tdiff)[0];
    log_block_buffer[log_block_pos++] = level_char;
    log_block_buffer[log_block_pos++] = ((uint8_t *)&value)[3]; // actual value
    log_block_buffer[log_block_pos++] = ((uint8_t *)&value)[2];
    log_block_buffer[log_block_pos++] = ((uint8_t *)&value)[1];
    log_block_buffer[log_block_pos++] = ((uint8_t *)&value)[0];
    log_block_buffer[log_block_pos++] = name4[3]; // name, only 4 bytes, no '\0'
    log_block_buffer[log_block_pos++] = name4[2];
    log_block_buffer[log_block_pos++] = name4[1];
    log_block_buffer[log_block_pos++] = name4[0];
    mem_add_data_to_page_wr_buffer(log_block_buffer, log_block_pos);
}

void log_data_add_string(int16_t tdiff, char level_char, char *str) {

}