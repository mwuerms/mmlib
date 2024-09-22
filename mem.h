/**
 * Martin Egli
 * 2024-09-18
 * mmlib https://github.com/mwuerms/mmlib
 * mem functions
 */

#ifndef _MM_MEM_H_
#define _MM_MEM_H_

#include <stdint.h>

void mem_init(void);
void mem_find_last_position(void);



uint16_t mem_add_data_to_page_wr_buffer(uint8_t *data, uint16_t data_len);

void mem_wr_page_buffer_print_hex(void);

#endif // _MM_MEM_H_



