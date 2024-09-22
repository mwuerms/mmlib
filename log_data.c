/**
 * Martin Egli
 * 2024-09-18
 * mmlib https://github.com/mwuerms/mmlib
 * organize data for log, define how data is stored, encode and decode data
 * *little endian*
 */

#include "log.h"
#include "log_data.h"
#include "times.h"
#include "mem.h"

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

#define LOG_ID_END_TOKEN (0xFF)

#define LOG_BLOCK_SIZE (64)
static uint8_t log_block_buffer[LOG_BLOCK_SIZE];
static uint8_t log_block_pos;

void log_data_init(void) {
    return;
}

void log_data_start(uint32_t start_time) {
    mem_start(start_time);
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
    log_block_buffer[log_block_pos++] = ((uint8_t *)&secs)[0];
    log_block_buffer[log_block_pos++] = ((uint8_t *)&secs)[1];
    log_block_buffer[log_block_pos++] = ((uint8_t *)&secs)[2];
    log_block_buffer[log_block_pos++] = ((uint8_t *)&secs)[3];
    mem_add_data_to_page_wr_buffer(log_block_buffer, log_block_pos);
}

void log_data_add_u16_value(int16_t tdiff, uint16_t value, uint8_t name_code) {
    log_block_pos = 0;
    log_block_buffer[log_block_pos++] = LOG_ID_U16_VALUE_NAME_CODE; // ID
    log_block_buffer[log_block_pos++] = ((uint8_t *)&tdiff)[0];
    log_block_buffer[log_block_pos++] = ((uint8_t *)&tdiff)[1];
    log_block_buffer[log_block_pos++] = ((uint8_t *)&value)[0]; // actual value
    log_block_buffer[log_block_pos++] = ((uint8_t *)&value)[1];
    log_block_buffer[log_block_pos++] = name_code;
    mem_add_data_to_page_wr_buffer(log_block_buffer, log_block_pos);
}

void log_data_add_u32_value(int16_t tdiff, uint32_t value, uint8_t name_code) {
    log_block_pos = 0;
    log_block_buffer[log_block_pos++] = LOG_ID_U32_VALUE_NAME_CODE; // ID
    log_block_buffer[log_block_pos++] = ((uint8_t *)&tdiff)[0];
    log_block_buffer[log_block_pos++] = ((uint8_t *)&tdiff)[1];
    log_block_buffer[log_block_pos++] = ((uint8_t *)&value)[0]; // actual value
    log_block_buffer[log_block_pos++] = ((uint8_t *)&value)[1];
    log_block_buffer[log_block_pos++] = ((uint8_t *)&value)[2];
    log_block_buffer[log_block_pos++] = ((uint8_t *)&value)[3];
    log_block_buffer[log_block_pos++] = name_code;
    mem_add_data_to_page_wr_buffer(log_block_buffer, log_block_pos);
}

void log_data_add_float_value(int16_t tdiff, float value, uint8_t name_code) {
    log_block_pos = 0;
    log_block_buffer[log_block_pos++] = LOG_ID_FLOAT_VALUE_NAME_CODE; // ID
    log_block_buffer[log_block_pos++] = ((uint8_t *)&tdiff)[0];
    log_block_buffer[log_block_pos++] = ((uint8_t *)&tdiff)[1];
    log_block_buffer[log_block_pos++] = ((uint8_t *)&value)[0]; // actual value
    log_block_buffer[log_block_pos++] = ((uint8_t *)&value)[1];
    log_block_buffer[log_block_pos++] = ((uint8_t *)&value)[2];
    log_block_buffer[log_block_pos++] = ((uint8_t *)&value)[3];
    log_block_buffer[log_block_pos++] = name_code;
    mem_add_data_to_page_wr_buffer(log_block_buffer, log_block_pos);
}

static const uint8_t level_id_code[] = {LOG_ID_INFO_CODE, LOG_ID_WARNING_CODE, LOG_ID_ERROR_CODE};
void log_data_add_level_code(int16_t tdiff, uint8_t level, uint8_t code) {
    log_block_pos = 0;
    // level: check in calling function for valid value
    log_block_buffer[log_block_pos++] = level_id_code[level]; // ID
    log_block_buffer[log_block_pos++] = ((uint8_t *)&tdiff)[0];
    log_block_buffer[log_block_pos++] = ((uint8_t *)&tdiff)[1];
    log_block_buffer[log_block_pos++] = code;
    mem_add_data_to_page_wr_buffer(log_block_buffer, log_block_pos);
}


// - read memory, interpret pages ----------------------------------------------
// *little endian*
static uint32_t parse_time;
#include <stdio.h>
uint16_t log_data_parse_time(uint8_t *page_data, uint16_t page_length, uint16_t pos) {
    uint32_t time;
    printf(" log_data_parse_time()\n");
    printf(" + id: %d\n", page_data[pos]);
    pos++;
    ((uint8_t *)&time)[0] = page_data[pos++];
    ((uint8_t *)&time)[1] = page_data[pos++];
    ((uint8_t *)&time)[2] = page_data[pos++];
    ((uint8_t *)&time)[3] = page_data[pos++];
    printf(" + time: %d, %08X\n", time, time);
    parse_time = time;
    return pos;
}

uint16_t log_data_parse_info_code(uint8_t *page_data, uint16_t page_length, uint16_t pos) {
    uint16_t tdiff;
    uint8_t code;
    printf(" log_data_parse_info_code()\n");
    printf(" + id: %d\n", page_data[pos]);
    pos++;
    ((uint8_t *)&tdiff)[0] = page_data[pos++];
    ((uint8_t *)&tdiff)[1] = page_data[pos++];
    printf(" + tdiff: %d\n", tdiff);
    printf(" + old parse time: %d\n", parse_time);
    parse_time += tdiff;
    printf(" + new parse time: %d\n", parse_time);
    code = page_data[pos++];
    printf(" + code: %d (0x%02X)\n", code, code);
    return pos;
}

uint16_t log_data_parse_warning_code(uint8_t *page_data, uint16_t page_length, uint16_t pos) {
    uint16_t tdiff;
    uint8_t code;
    printf(" log_data_parse_warning_code()\n");
    printf(" + id: %d\n", page_data[pos]);
    pos++;
    ((uint8_t *)&tdiff)[0] = page_data[pos++];
    ((uint8_t *)&tdiff)[1] = page_data[pos++];
    printf(" + tdiff: %d\n", tdiff);
    printf(" + old parse time: %d\n", parse_time);
    parse_time += tdiff;
    printf(" + new parse time: %d\n", parse_time);
    code = page_data[pos++];
    printf(" + code: %d (0x%02X)\n", code, code);
    return pos;
}

uint16_t log_data_parse_error_code(uint8_t *page_data, uint16_t page_length, uint16_t pos) {
    uint16_t tdiff;
    uint8_t code;
    printf(" log_data_parse_error_code()\n");
    printf(" + id: %d\n", page_data[pos]);
    pos++;
    ((uint8_t *)&tdiff)[0] = page_data[pos++];
    ((uint8_t *)&tdiff)[1] = page_data[pos++];
    printf(" + tdiff: %d\n", tdiff);
    printf(" + old parse time: %d\n", parse_time);
    parse_time += tdiff;
    printf(" + new parse time: %d\n", parse_time);
    code = page_data[pos++];
    printf(" + code: %d (0x%02X)\n", code, code);
    return pos;
}

uint16_t log_data_parse_u16_value(uint8_t *page_data, uint16_t page_length, uint16_t pos) {
    uint16_t tdiff, value;
    printf(" log_data_parse_u16_value()\n");
    printf(" + id: %d\n", page_data[pos]);
    pos++;
    ((uint8_t *)&tdiff)[0] = page_data[pos++];
    ((uint8_t *)&tdiff)[1] = page_data[pos++];
    printf(" + tdiff: %d\n", tdiff);
    printf(" + old parse time: %d\n", parse_time);
    parse_time += tdiff;
    printf(" + new parse time: %d\n", parse_time);
    ((uint8_t *)&value)[0] = page_data[pos++];
    ((uint8_t *)&value)[1] = page_data[pos++];
    printf(" + value: %d\n", value);
    return pos;
}

uint16_t log_data_parse_u32_value(uint8_t *page_data, uint16_t page_length, uint16_t pos) {
    uint32_t value;
    uint16_t tdiff;
    printf(" log_data_parse_u32_value()\n");
    printf(" + id: %d\n", page_data[pos]);
    pos++;
    ((uint8_t *)&tdiff)[0] = page_data[pos++];
    ((uint8_t *)&tdiff)[1] = page_data[pos++];
    printf(" + tdiff: %d\n", tdiff);
    printf(" + old parse time: %d\n", parse_time);
    parse_time += tdiff;
    printf(" + new parse time: %d\n", parse_time);
    ((uint8_t *)&value)[0] = page_data[pos++];
    ((uint8_t *)&value)[1] = page_data[pos++];
    ((uint8_t *)&value)[2] = page_data[pos++];
    ((uint8_t *)&value)[3] = page_data[pos++];
    printf(" + value: %d\n", value);
    return pos;
}

uint16_t log_data_parse_float_value(uint8_t *page_data, uint16_t page_length, uint16_t pos) {
    float value;
    uint16_t tdiff;
    printf(" log_data_parse_float_value()\n");
    printf(" + id: %d\n", page_data[pos]);
    pos++;
    ((uint8_t *)&tdiff)[0] = page_data[pos++];
    ((uint8_t *)&tdiff)[1] = page_data[pos++];
    printf(" + tdiff: %d\n", tdiff);
    printf(" + old parse time: %d\n", parse_time);
    parse_time += tdiff;
    printf(" + new parse time: %d\n", parse_time);
    ((uint8_t *)&value)[0] = page_data[pos++];
    ((uint8_t *)&value)[1] = page_data[pos++];
    ((uint8_t *)&value)[2] = page_data[pos++];
    ((uint8_t *)&value)[3] = page_data[pos++];
    printf(" + value: %f\n", value);
    return pos;
}

uint16_t log_data_parse_end_token(uint8_t *page_data, uint16_t page_length, uint16_t pos) {
    printf(" log_data_parse_end_token()\n");
    printf(" + id: %d\n", page_data[pos]);
    if(page_data[pos++] != 0xFF) {
        // not end tocken
        return pos;
    }
    // end token found, so do not continue
    printf(" + end token: %d\n", page_data[pos]);
    return page_length;
}

void log_data_read_mem_page(void) {
    uint16_t page_length, pos;
    uint8_t *page_data, id;
    page_data = mem_read_page(0, &page_length);

    printf("log_data_read_mem_page()\n");
    //printf(" + page_data: %p\n", page_data);
    pos = 3; // 1st position to interpret
    while(pos < page_length) {
        //printf(" + pos: %d, id: %d (0x%02X)\n", pos, page_data[pos], page_data[pos]);
        switch(page_data[pos]) { // id
            case LOG_ID_TIME:
                pos = log_data_parse_time(page_data, page_length, pos);
                break;
            case LOG_ID_INFO_CODE:
                pos = log_data_parse_info_code(page_data, page_length, pos);
                break;
            case LOG_ID_WARNING_CODE:
                pos = log_data_parse_warning_code(page_data, page_length, pos);
                break;
            case LOG_ID_ERROR_CODE:
                pos = log_data_parse_error_code(page_data, page_length, pos);
                break;
            case LOG_ID_U16_VALUE_NAME_CODE:
                pos = log_data_parse_u16_value(page_data, page_length, pos);
                break;
            case LOG_ID_U32_VALUE_NAME_CODE:
                pos = log_data_parse_u32_value(page_data, page_length, pos);
                break;
            case LOG_ID_FLOAT_VALUE_NAME_CODE:
                pos = log_data_parse_float_value(page_data, page_length, pos);
                break;
            case LOG_ID_END_TOKEN:
                pos = log_data_parse_end_token(page_data, page_length, pos);
                break;
            default: // unknown block, try next byte
                pos++;
        }

    }

}

