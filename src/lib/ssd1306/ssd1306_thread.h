/** 
 ***************************************************************
 * Author: Wilfred MK
 * StudentID: S4428042
 * Organization: UQ
 * 
 * Brief: Contains SSD1306 Display write thread header, includes 
 *         thread defines and required function declarations. 
 ***************************************************************
 **/
#ifndef SSD1306_THREAD_H
#define SSD1306_THREAD_H

#define STACK_SIZE_SSD1306 1024
#define THREAD_PRIORITY_SSD1306 5 /* Lower Numerics has higher priority, -Ve Priorities are cooperitive threads, +Ve Priorities  are Preemtible  */

/* Declared in device_config.h, is used across multiple files */
extern const struct device *dev_i2c0;
/* displayMode is incremented by the external pushbutton to toggle screen data */
extern short int displayMode;
extern short int clearDisplay;

void thread_ssd1306_ctrl(void *unused1, void *unused2, void *unused3);

void spawn_ssd1306_thread(void);

void SSD1306_Hello(void);

void SSD1306_AUX(void);

void SSD1306_Zephyr(void);

int init_i2c(void);

#endif