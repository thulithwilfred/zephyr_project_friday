/** 
 ***************************************************************
 * Author: Wilfred MK
 * StudentID: S4428042
 * Organization: UQ
 * Brief: 
 ***************************************************************
 **/
#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <stdlib.h>
#include "main.h"
#include "device_config/device_config.h"
#include "ssd1306/ssd1306_thread.h"
#include "debug_leds/debug_leds.h"
#include "uart0_serial/uart0_serial.h"

/* To be include last, due to dependacies */

/*    ---------------------------------   */

void main(void)
{
	/* Initialize Pheripherals */
	setup();
	/* Spawn pheripheral threads */
	spawn_pheripheral_threads();

}

void spawn_pheripheral_threads(void) {

	/* Spawn SSD1306 Display Control Thread */
	spawn_ssd1306_thread();
	spawn_uart0_serial_thread();

}

/* Initialise pins and various sub-systems */
void setup(void)
{
	/* Capture Return Values - Makes it Readable */
	
	/* Internal Initialization, init_* functions will return 0 if successful */
	init_led_pin(); //Location: debug_leds
	init_gpio();	//Location: debug_leds 
	init_i2c();		//Location: ssd1306
	init_uart0();   //Location: uart0_serial

}





