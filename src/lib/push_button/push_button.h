/** 
 ***************************************************************
 * Author: Wilfred MK
 * StudentID: S4428042
 * Organization: UQ
 * Brief: Header containing function declarations requried by 
 *          push_button.c 
 ***************************************************************
 **/

#ifndef PUSH_BUTTON_H
#define PUSH_BUTTON_H

int init_gpio(void);

void button_pressed(const struct device *dev, struct gpio_callback *cb, uint32_t pins);

#endif