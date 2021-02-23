/** 
 ***************************************************************
 * Author: Wilfred MK
 * StudentID: S4428042
 * Organization: UQ
 * 
 * Brief: Containing Function definitions and defines required by main.c
 ***************************************************************
 **/
#ifndef _MAIN_H
#define _MAIN_H

#define STACK_SIZE 512
#define THREAD_PRIORITY 5 /* Lower Numerics has higher priority, -Ve Priorities are cooperitive threads, +Ve Priorities  are Preemtible  */


/* ==================================================================== */
/* =============================Functions============================== */
/* ==================================================================== */
/* Function Declarations for use in main */
void setup(void);

void spawn_pheripheral_threads(void);

/* Threads - Defined at compile time, using K_THREAD_DEFINE  */
void thread_blink_ext_led(void *unused1, void *unused2, void *unused3);

void thread_blink_brd_led(void *unused1, void *unused2, void *unused3);


#endif
