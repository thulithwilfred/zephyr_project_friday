/** 
 ***************************************************************
 * Author: Wilfred MK
 * StudentID: S4428042
 * Organization: UQ
 * 
 * Brief: Contains SSD1306 Display write thread, the thread will
 * 			update the display when required.
 ***************************************************************
 **/


#include <zephyr.h>
#include "ssd1306/ssd1306_thread.h"
/* To be include last, due to dependacies */
#include "device_config/device_config.h"
#include "ssd1306/fonts.h"
#include "ssd1306/ssd1306.h"



/** These macros creates (starts with no delay) threads at compile time : DISABLED  - An alternative way to start threads - 
 * 			not ideal as hardware should be configured first (these start at 'tick 0')
 * 			K_THREAD_DEFINE(tid_thread_ssd1306_ctrl, STACK_SIZE_SSD1306, thread_ssd1306_ctrl, NULL, NULL, NULL, THREAD_PRIORITY_SSD1306, 0, 0);
 **/

/* Stack Area/Size Define for runtime threads - Must be globally Defined (Zephyr Threads/Implementations) */
K_THREAD_STACK_DEFINE(thread_ssd1306_ctrl_stack_area, STACK_SIZE_SSD1306);
struct k_thread ssd1306_thread_data;

/* This thread will blink the EXT_LED */
void thread_ssd1306_ctrl(void *unused1, void *unused2, void *unused3)
{
    int mode = 1;
	/* Initialise SSD1306_Driver */
    SSD1306_Init();
    /* Send message to display */
    SSD1306_Hello();

	k_msleep(100);

    while(1) {


        SSD1306_Clear();

		if (mode) {
			SSD1306_Hello();
			mode = !mode;
		} else {
			SSD1306_AUX();
			mode = !mode;
		}
		k_msleep(2000);

	}
}

void SSD1306_Hello(void)
{
	SSD1306_GotoXY(10, 10);
	SSD1306_Puts("XDD", &Font_11x18, 1);
	SSD1306_GotoXY(10, 30);
	SSD1306_Puts(">debug", &Font_7x10, 1);
	SSD1306_GotoXY(10, 40);
	SSD1306_Puts("0x69A", &Font_7x10, 1);

	SSD1306_UpdateScreen();
}

void SSD1306_AUX(void) {
	SSD1306_GotoXY(10, 10);
	SSD1306_Puts("YO", &Font_11x18, 1);
	SSD1306_GotoXY(10, 30);
	SSD1306_Puts(">debug", &Font_7x10, 1);
	SSD1306_GotoXY(10, 40);
	SSD1306_Puts("0x69A", &Font_7x10, 1);

	SSD1306_UpdateScreen();	
}

void spawn_ssd1306_thread(void) {
	/*Stack area - _K_THREAD_STACK, allows the define a stack that will host user threads 
	* If CONFIG_USERSPACE is not enabled, the set of K_THREAD_STACK
	* macros have an identical effect to the K_KERNEL_STACK macros. */
	
	/*-----------------------------------------------------------------------------------------------------------*/	
	/*Spawns SSD1306 THREAD */	
	k_tid_t tid_ssd1306_ctrl = k_thread_create(&ssd1306_thread_data, thread_ssd1306_ctrl_stack_area, STACK_SIZE_SSD1306,
												thread_ssd1306_ctrl, NULL, NULL, NULL,5, 0, K_NO_WAIT);

}

/* Init I2C, will return 0 on completeion */
int init_i2c(void)
{
	/* Obtain pre-initialised device binding - see device_config.h */
	dev_i2c0 = device_get_binding(DT_LABEL(I2CX));

	if (!dev_i2c0)
	{
		/* Unable to retrive device structure */
		return -ENODEV;
	}
	else
	{
		/*Configure I2C using attained device struct, using the following parameters */
		return i2c_configure(dev_i2c0, I2C_SPEED_FAST | I2C_MODE_MASTER);
	}
}