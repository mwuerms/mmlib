/**
 * Martin Egli
 * 2024-09-18
 * mmlib https://github.com/mwuerms/mmlib
 * mem functions
 */

#include "mem.h"

// set up for using: IS25LP080D-JNLE-TR
// move all chip specific code later to like mem_is25 or mem_hal

#define MEM_SIZE_MBITS (8)  // 8388608 Bytes
#define MEM_PAGE_SIZE (256) // Bytes
#define MEM_NB_PAGE (4096) // number of pages

// dummy memory, holds all bytes accordint to 8MBit, organized in pages
uint8_t  mem_dummy[MEM_NB_PAGE][MEM_PAGE_SIZE];
uint16_t mem_page_address; // address to store mem_page_buffer in mem_dummy

// memory is organised in pages, buffer to write a page to memory
uint8_t  mem_page_wr_buffer[MEM_PAGE_SIZE];
uint16_t mem_page_wr_pos; // write position in mem_page_wr_buffer


void mem_init(void) {
    mem_find_last_position();
}

void mem_find_last_position(void) {
    return;
}

void mem_new_page(void) {
    return;
}

void mem_store_page(void) {
    return;
}