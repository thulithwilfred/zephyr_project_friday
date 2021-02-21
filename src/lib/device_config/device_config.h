/** 
 * Author: Wilfred MK
 * StudentID: S4428042
 * Organization: UQ
 * 
 * Brief: the file contains all pre-processed device tree configuration items required for the 
 *          initialization of device components. Using the Zephyr Device Tree Macros.
 * 
 **/

#ifndef DEVICE_CONFIG_H
#define DEVICE_CONFIG_H

/* 1000 msec = 1 sec */
#define SLEEP_TIME_MS_2 1000
#define SLEEP_TIME_MS_1 100


/* ==================================================================== */
/* ==========================Onboard LED- Blue==========================*/
/* ==================================================================== */
/* The devicetree node identifier for the "led0" alias. */
#define LED0_NODE DT_ALIAS(led0)
//const struct device *dev_brd_led2;
#define LED0 DT_GPIO_LABEL(LED0_NODE, gpios)
#define BRD_LED_PIN DT_GPIO_PIN(LED0_NODE, gpios)
#define FLAGS DT_GPIO_FLAGS(LED0_NODE, gpios)


/* ==================================================================== */
/* ===========================GPIO-PORT0=============================== */
/* ==================================================================== */
/* Device tree node identifier for GPIO0 */
#define GP DT_NODELABEL(gpio0)
#define EXT_LED_PIN 31


/* ==================================================================== */
/* ==============================UART-PORT0============================ */
/* ==================================================================== */
/* Device tree node identifier for UART0 */
#define UART0 DT_NODELABEL(uart0)


const struct uart_config uart_cfg = {
    .baudrate = 9600,
    .parity = UART_CFG_PARITY_NONE,
    .stop_bits = UART_CFG_STOP_BITS_1,
    .data_bits = UART_CFG_DATA_BITS_8,
    .flow_ctrl = UART_CFG_FLOW_CTRL_NONE};

/* ==================================================================== */
/* ============================I2C-PORT0=============================== */
/* ==================================================================== */
/* Device tree node identifier for I2C0 */
#define I2CX DT_NODELABEL(i2c0)
/* This needs to be globally defined, due to the usage in SSD1306 library */
const struct device *dev_i2c0;

#endif