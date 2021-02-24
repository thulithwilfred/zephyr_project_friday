/** 
 ***************************************************************
 * Author: Wilfred MK
 * StudentID: S4428042
 * Organization: UQ
 * 
 * Brief: Contains Debug LED threads, to blink ON_BRD_STATUS leds
 * 			as desired.  (No debug functionality as of now, 
 * 				they blink indefinetly)
 ***************************************************************
 **/

#include "device_config/device_config.h"
#include "debug_leds/debug_leds.h"

/* These macros creates (starts with no delay) threads at compile time */
//K_THREAD_DEFINE(tid_thread_blink_brd_led0, STACK_SIZE_LED_THREAD, thread_blink_brd_led0, NULL, NULL, NULL, THREAD_PRIORITY_LED_THREAD, 0, 0);
K_THREAD_DEFINE(tid_thread_blink_brd_led1, STACK_SIZE_LED_THREAD, thread_blink_brd_led1, NULL, NULL, NULL, THREAD_PRIORITY_LED_THREAD, 0, 0);
K_THREAD_DEFINE(tid_thread_blink_brd_led2, STACK_SIZE_LED_THREAD, thread_blink_brd_led2, NULL, NULL, NULL, THREAD_PRIORITY_LED_THREAD, 0, 0);




/* This thread will blink BRD_LED - Blue */
void thread_blink_brd_led0(void *unused1, void *unused2, void *unused3)
{
	bool led_is_on = true;
	/* Obtain pre-initialised device binding - see device_config.h */
	const struct device *dev_gpio0 = device_get_binding(DT_LABEL(GP));

	while (1)
	{
		gpio_pin_set(dev_gpio0, EXT_BUTTON_PIN, (int)led_is_on);
		led_is_on = !led_is_on;
		k_msleep(SLEEP_TIME_MS_2);
	}
}


/* This thread will blink BRD_STATUS_LED - Red */
void thread_blink_brd_led1(void *unused1, void *unused2, void *unused3)
{
	bool led_is_on = true;
	/* Obtain pre-initialised device binding - see device_config.h */
	const struct device *dev_brd_led1 = device_get_binding(LED1);
	while (1)
	{
		gpio_pin_set(dev_brd_led1, BRD_LED1_PIN, (int)led_is_on);
		led_is_on = !led_is_on;
		k_msleep(SLEEP_TIME_MS_1);
	}
}

/* This thread will blink BRD_STATUS_LED - Red */
void thread_blink_brd_led2(void *unused1, void *unused2, void *unused3)
{
	bool led_is_on = true;
	/* Obtain pre-initialised device binding - see device_config.h */
	const struct device *dev_brd_led2 = device_get_binding(LED2);
	while (1)
	{
		gpio_pin_set(dev_brd_led2, BRD_LED2_PIN, (int)led_is_on);
		led_is_on = !led_is_on;
		k_msleep(SLEEP_TIME_MS_1 + 100);
	}
}



/* Initialize ON_BRD_LED Blue and ON_BRD_STATUS_LED - Red */
int init_led_pin(void)
{
	/* Obtain pre-initialised device binding - see device_config.h */
	const struct device *dev_brd_led0 = device_get_binding(LED0);
	const struct device *dev_brd_led1 = device_get_binding(LED1);
	const struct device *dev_brd_led2 = device_get_binding(LED2);

	if (!dev_brd_led0 && !dev_brd_led1 && !dev_brd_led2)
	{
		/* Unable to retrive device structure */
		return -ENODEV;
	}
	else
	{
		/* Configrue BRD_LED using attained deivice struct as GPIO_OUT */
		 int r1 = gpio_pin_configure(dev_brd_led2, BRD_LED2_PIN, GPIO_OUTPUT_ACTIVE | FLAGS2);
		 int r2 = gpio_pin_configure(dev_brd_led1, BRD_LED1_PIN, GPIO_OUTPUT_ACTIVE | FLAGS1);
		 //int r3 = gpio_pin_configure(dev_brd_led0, BRD_LED_PIN, GPIO_OUTPUT_ACTIVE | FLAGS);
		 return r1 && r2;
	}
	
}
