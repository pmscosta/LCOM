#ifndef __KBC_FUNCTIONS_H
#define __KBC_FUNCTIONS_H


extern int g_sys_cnt;
extern int g_scancode;



/**
 * @brief Subscribes and enables keyboard interrupts
 *
 * @return Returns bit order in interrupt mask; negative value on failure
 */
int kbc_subscribe(void);



/**
 * @brief Unsubscribes keyboard 0 interrupts
 *
 * @return Return 0 upon success and non-zero otherwise
 */
int kbc_unsubscribe();

/**
 * @brief Gets the scancode of a key by polling
 *
 * Sets the Global Variable g_scancode to the value stored in the output buffer
 * If the value is corrupted, i.e., parity or timeout errors, set the
 * global variable to 0; If the output buffer never gets full (after a given number of operations),
 * it sets the global variable to -1;
 *
 */
void kbc_read_code_poll();

/**
 * @brief Keyboard interrupt handler
 *
 * Sets the Global Variable g_scancode to the value stored in the output buffer
 * If the value is corrupted, i.e., parity or timeout errors, set the
 * global variable to 0;
 *
 */
void kbc_int_handler();

/**
 * @brief Prints the global variable scancode in the given format
 *
 * @param scan_flag - used to alternate between two-byte scancodes and one-byte scan codes
 */

void print_scancode (int  * scan_flag);




#endif
