/** 
 * Author: Wilfred MK
 * StudentID: S4428042
 * Organization: UQ
 * 
 * Brief: Containing Function definitions and defines required by main.c
 * 
 **/
#ifndef _MAIN_H
#define _MAIN_H


/* ==================================================================== */
/* =============================Functions============================== */
/* ==================================================================== */
/* Function Declarations for use in main */
int init_led_pin(void);

int init_i2c(void);

int init_gpio(void);

void setup(void);

void SSD1306_Hello(void);

int init_uart(void);

static inline void write_uart_string(const char *str, const struct device *dev_uart);

/* Threads - Defined at compile time, using K_THREAD_DEFINE  */
void thread_blink_ext_led(void *unused1, void *unused2, void *unused3);

void thread_blink_brd_led(void *unused1, void *unused2, void *unused3);

#endif
