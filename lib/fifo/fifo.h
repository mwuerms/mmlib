/**
 * Martin Egli
 * 2023-09-02
 * mmlib: fifo functions
 */

#ifndef _MM_FIFO_H_
#define _MM_FIFO_H_

/**
 * @brief: 
 * this module manages all the read and write positions and size of the fifo
 * it does not contain any data of the fifo, this is up to the calling functions
 */
 
// - use c standard libraries -------
#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

/**
 * fifo control
 * holds read and write positions and size of the fifo
 * wr: write position
 * wr_proc: use this write position after `fifo_try_append()`, its value will get stored in `wr` with `fifo_finalize_append()`
 * rd: read position
 * rd_proc: use this read position after `fifo_try_get()`, its value will get stored in `rd` with `fifo_finalize_get()`
 * size: of the fifo
 */
typedef struct {
    uint16_t wr, wr_proc;
    uint16_t rd, rd_proc;
    uint16_t size;
} fifo_ctrl_t;

// - public functions ----------------------------------------------------------
/**
 * initialize a fifo_ctrl to a given size
 * @param   f       pointer to fifo_ctrl
 * @param   size    size of fifo
 * @return  =true: success, =false: error, invalid pointer 
 */
uint16_t fifo_init(fifo_ctrl_t *f, uint16_t size);

/**
 * check if a fifo_ctrl is full
 * @param   f       pointer to fifo_ctrl
 * @return  =true: fifo is indeed full, =false: fifo is NOT full
 */
uint16_t fifo_is_full(fifo_ctrl_t *f);

/**
 * check if a fifo_ctrl is empty
 * @param   f       pointer to fifo_ctrl
 * @return  =true: fifo is indeed empty, =false: fifo is NOT empty
 */
uint16_t fifo_is_empty(fifo_ctrl_t *f);

/**
 * try to append to fifo
 * @param   f       pointer to fifo_ctrl
 * @return  =true: success, can append, =false: error, fifo is full
 */
uint16_t fifo_try_append(fifo_ctrl_t *f);

/**
 * finalize append to fifo
 * @param   f       pointer to fifo_ctrl
 * @return  =true: success, =false: error, invalid pointer
 */
uint16_t fifo_finalize_append(fifo_ctrl_t *f);

/**
 * try to get from fifo
 * @param   f       pointer to fifo_ctrl
 * @return  =true: success, can get, =false: error, fifo is empty
 */
uint16_t fifo_try_get(fifo_ctrl_t *f);

/**
 * finalize get fromfifo
 * @param   f       pointer to fifo_ctrl
 * @return  =true: success, =false: error, invalid pointer
 */
uint16_t fifo_finalize_get(fifo_ctrl_t *f);



#endif // _MM_FIFO_H_
