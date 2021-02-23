/** 
 ***************************************************************
 * Author: Wilfred MK
 * StudentID: S4428042
 * Organization: UQ
 * 
 * Brief: Contains UART0 - Serial Comms Thread Functionality
 * Accessed by:  main.c. 
 ***************************************************************
 **/


#ifndef UART0_SERIAL_H
#define UART0_SERIAL_H

#define STACK_SIZE_UART0 256
#define THREAD_PRIORITY_UART0 6 /* Lower Numerics has higher priority, -Ve Priorities are cooperitive threads, +Ve Priorities  are Preemtible  */

/* Functions */
int init_uart0(void);


/** NOTE static means it can't be referenced from another compilation unit (source file)."Referenced" means called,
 *  or otherwise referred to by name, e.g. assigned to a function pointer.
 * 
 * inline is a hint to the compiler that the function's code should be generated inline at the place it is called,
 * rather than generated as a separate function to be branched to. This is normally done for performance reasons. 
 * 
 **/
static inline void write_uart_string(const char *str, const struct device *dev_uart);

void spawn_uart0_serial_thread(void);

/* Threads */
void thread_uart_tx(void *unused1, void *unused2, void *unused3);

#endif