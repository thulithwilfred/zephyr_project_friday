/** 
 ***************************************************************
 * Author: Wilfred MK
 * StudentID: S4428042
 * Organization: UQ
 * 
 * Brief: the file contains all pre-processed device tree configuration items required for the 
 *          initialization of device components. Using the Zephyr Device Tree Macros.
 * 
 * Accessed by:  main 
 *               debug_leds
 *               uart0_serial
 *               ssd1306 / ssd1306_thread          
 ***************************************************************
 **/

#ifndef DEVICE_CONFIG_H
#define DEVICE_CONFIG_H

#include <drivers/gpio.h>
#include <drivers/i2c.h>
#include <drivers/uart.h>

/* 1000 msec = 1 sec */
#define SLEEP_TIME_MS_2 1000
#define SLEEP_TIME_MS_1 100

/* ==================================================================== */
/* ==========================Onboard LED- Blue==========================*/
/* ==================================================================== */
/* The devicetree node identifier for the "led0" alias. */
#define LED0_NODE DT_ALIAS(led0)
#define LED0 DT_GPIO_LABEL(LED0_NODE, gpios)
#define BRD_LED_PIN DT_GPIO_PIN(LED0_NODE, gpios)
#define FLAGS DT_GPIO_FLAGS(LED0_NODE, gpios)

/* The devicetree node identifier for the "led1" alias. */
#define LED1_NODE DT_ALIAS(led1)
#define LED1 DT_GPIO_LABEL(LED1_NODE, gpios)
#define BRD_LED1_PIN DT_GPIO_PIN(LED1_NODE, gpios)
#define FLAGS1 DT_GPIO_FLAGS(LED1_NODE, gpios)

/* The devicetree node identifier for the "led2" alias. */
#define LED2_NODE DT_ALIAS(led2)
#define LED2 DT_GPIO_LABEL(LED2_NODE, gpios)
#define BRD_LED2_PIN DT_GPIO_PIN(LED2_NODE, gpios)
#define FLAGS2 DT_GPIO_FLAGS(LED2_NODE, gpios)

/* ==================================================================== */
/* ===========================GPIO-PORT0=============================== */
/* ==================================================================== */
/* Device tree node identifier for GPIO0 */
#define GP DT_NODELABEL(gpio0)
#define EXT_BUTTON_PIN 31

/* ==================================================================== */
/* ==============================UART-PORT0============================ */
/* ==================================================================== */
/* Device tree node identifier for UART0 */
#define UART0 DT_NODELABEL(uart0)

/* ==================================================================== */
/* ============================I2C-PORT0=============================== */
/* ==================================================================== */
/* Device tree node identifier for I2C0 */
#define I2CX DT_NODELABEL(i2c0)
/* This needs to be globally defined, due to the usage in SSD1306 library */

#endif