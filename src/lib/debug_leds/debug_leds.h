/** 
 ***************************************************************
 * Author: Wilfred MK
 * StudentID: S4428042
 * Organization: UQ
 * 
 * Brief: Contains Debug LED threads required definitions and
 *          function declarations. 
 ***************************************************************
 **/
#ifndef DEBUG_LEDS_H
#define DEBUG_LEDS_H

#define STACK_SIZE_LED_THREAD 256
#define THREAD_PRIORITY_LED_THREAD 10 /* Lower Numerics has higher priority, -Ve Priorities are cooperitive threads, +Ve Priorities  are Preemtible  */

/* Threads - Compile Time Defined */
void thread_blink_ext_led(void *unused1, void *unused2, void *unused3);

void thread_blink_brd_led0(void *unused1, void *unused2, void *unused3);
void thread_blink_brd_led1(void *unused1, void *unused2, void *unused3);
void thread_blink_brd_led2(void *unused1, void *unused2, void *unused3);


/* Function */
int init_gpio(void);

int init_led_pin(void);


#endif