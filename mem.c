/**
 * Martin Egli
 * 2024-09-18
 * mmlib https://github.com/mwuerms/mmlib
 * mem functions
 */
#include <stdbool.h>
#include <stddef.h>
#include "mem.h"
#include "mmlib.h"

// set up for using: IS25LP080D-JNLE-TR
// move all chip specific code later to like mem_is25 or mem_hal

#define MEM_SIZE_MBITS (8)  // 8388608 Bytes
#define MEM_PAGE_SIZE (256) // Bytes
#define MEM_NB_PAGE (4096) // number of pages

static uint8_t mem_ctrl;
#define MEM_CTRL_ACTIVE BITV(0)
#define MEM_CTRL_START BITV(1)

// dummy memory, holds all bytes accordint to 8MBit, organized in pages
uint8_t  mem_dummy[MEM_NB_PAGE][MEM_PAGE_SIZE];
uint16_t mem_page_start_address; // start_address of mem_page_wr_buffer mem_dummy
uint16_t mem_page_wr_address; // address to store mem_page_wr_buffer in mem_dummy

// memory is organised in pages, buffer to write a page to memory
uint8_t  mem_page_wr_buffer[MEM_PAGE_SIZE];
uint16_t mem_page_wr_pos; // write position in mem_page_wr_buffer
/*
 * organize page content
 * 
 */

static inline uint8_t is_mem_active(void) {
    if(mem_ctrl & MEM_CTRL_ACTIVE) {
        return true;
    }
    return false;
}

void mem_init(void) {
    mem_ctrl = MEM_CTRL_START;
    mem_find_last_position();
}

void mem_find_last_position(void) {
    mem_page_start_address = 0xBEEF; // TEST value
}

void mem_new_page(void) {
    uint8_t d;
    if(is_mem_active() == false) {
        // error, memory is inactive
        return;
    }
    mem_page_wr_pos = 0;
    d = mem_ovf + mem_version << 3;
    if(mem_ctrl & MEM_CTRL_START) {
        mem_ctrl &= ~MEM_CTRL_START;
        d |= BITV(2);
    }
    mem_page_wr_buffer[mem_page_wr_pos++] = d;
    return;
}

void mem_store_page(void) {
    if(is_mem_active() == false) {
        // error, memory is inactive
        return;
    }
    return;
}

inline static void mem_add_endtoken_to_page_wr_buffer(void) {
    mem_page_wr_buffer[mem_page_wr_pos++] = 0xFF;
    mem_page_wr_buffer[mem_page_wr_pos++] = 0xFF;
}
/**
 * add data to the mem_page_wr_buffer
 * @param   data     pointer to data
 * @param   data_len data length
 * @return
 */
uint16_t mem_add_data_to_page_wr_buffer(uint8_t *data, uint16_t data_len) {
    uint16_t n;
    if(is_mem_active() == false) {
        // error, memory is inactive
        return 0;
    }
    if(data == NULL) {
        // error, invalid data
        return 0;
    }
    if(data_len == 0) {
        // error, invalid data
        return 0;
    }
    // enough space left?
    // 0 ... 255
    if((mem_page_wr_pos + data_len + 2) >= MEM_PAGE_SIZE) {
        // no: mem_store_page
        // no: mem_new_page()
        mem_add_endtoken_to_page_wr_buffer();
    }
    // copy data
    for(n = 0; n < data_len; n++, mem_page_wr_pos++) {
        mem_page_wr_buffer[mem_page_wr_pos] = data[n];
    }
    // add end token
    mem_add_endtoken_to_page_wr_buffer();
    return 0;
}

// debug function
void mem_wr_page_buffer_print_hex(void) {

}
