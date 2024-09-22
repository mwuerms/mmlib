/**
 * Martin Egli
 * 2024-09-18
 * mmlib https://github.com/mwuerms/mmlib
 * log functions
 */

#include "log.h"
#include "log_data.h"

static uint32_t log_last_time;
static uint32_t log_current_time;
static uint8_t  log_level = LOG_LEVEL_INFO;

// dummy function to get a valid time for testing, replace later by something propper
static uint32_t _current_time = 0;
static uint32_t __get_current_time(void) {
    _current_time++;
    return _current_time;
}

void log_init(void) {
    log_level = LOG_LEVEL_INFO;
    log_data_init();
}

void log_start(void) {
    log_data_start();
    log_last_time = __get_current_time();
    log_data_add_time(log_last_time);
    return;
}

void log_stop(void) {
    log_data_stop();
    return;
}

void log_set_level(uint8_t level) {
    if(level > LOG_LEVEL_MAX) {
        level = LOG_LEVEL_MAX;
    }
    log_level = level;
}

// call periodically, approx every 10000s (difft in uint16_t)
void log_time(void) {
    // log time always if(level < log_level)
    log_last_time = __get_current_time();
    log_data_add_time(log_last_time);
    return;
}

void log_uint16_value(uint16_t value, uint8_t name_code) {
    uint16_t tdiff;
    // log values always if(level < log_level)
    // calc tdiff
    log_current_time = __get_current_time();
    tdiff = (uint16_t)(log_current_time - log_last_time);
    log_data_add_u16_value(tdiff, value, name_code);
    return;
}

void log_uint32_value(uint32_t value, uint8_t name_code) {
    uint16_t tdiff;
    // log values always if(level < log_level)
    // calc tdiff
    log_current_time = __get_current_time();
    tdiff = (uint16_t)(log_current_time - log_last_time);
    log_data_add_u16_value(tdiff, value, name_code);
    return;
}

void log_float_value(float value, uint8_t name_code) {
    uint16_t tdiff;
    // log values always if(level < log_level)
    // calc tdiff
    log_current_time = __get_current_time();
    tdiff = (uint16_t)(log_current_time - log_last_time);
    log_data_add_u16_value(tdiff, value, name_code);
    return;
}

void log_msg_code(uint8_t level, uint8_t msg_code) {
    uint16_t tdiff;
    char level_char;
    if(level < log_level) {
        // skip
        return;
    }
    // CHECK LEVEL level
    // calc tdiff
    log_current_time = __get_current_time();
    tdiff = (uint16_t)(log_current_time - log_last_time);
    log_data_add_level_code(tdiff, level, msg_code);
}

void log_read_all_as_csv(uint8_t dest) {
    log_read_as_csv(0, LOG_READ_LEVEL_MASK_ALL, LOG_READ_TIME_FORMAT_YYYMMDD_HHMMSS, ';');
}

#include <stdio.h>
void log_read_as_csv(uint8_t dest, uint8_t level_mask, uint8_t time_format, char sep) {
    // header
    printf("time;level;data\n");
}
