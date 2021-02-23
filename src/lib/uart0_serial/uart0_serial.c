/** 
 ***************************************************************
 * Author: Wilfred MK
 * StudentID: S4428042
 * Organization: UQ
 * 
 * Brief: Contains UART0 - Serial Comms Thread Functionality
 ***************************************************************
 **/

#include <zephyr.h>
#include "device_config/device_config.h"
#include "uart0_serial/uart0_serial.h"

/* Stack Area/Size Define for runtime threads - Must be globally Defined (Zephyr Threads/Implementations) */
K_THREAD_STACK_DEFINE(thread_uart_tx_stack_area , STACK_SIZE_UART0);
struct k_thread uart0_serial_data;


void thread_uart_tx(void *unused1, void *unused2, void *unused3) {

	const struct device *dev_uart0 = device_get_binding(DT_LABEL(UART0));

	while(1) {
		write_uart_string("Test:\n\r", dev_uart0);
		k_msleep(SLEEP_TIME_MS_2);
	}
}


static inline void write_uart_string(const char *str, const struct device *dev_uart)
{
	/* Send characters until, but not including, null */
	for (size_t i = 0; str[i]; i++)
	{
		uart_poll_out(dev_uart, str[i]);
	}
}

void spawn_uart0_serial_thread(void) {
	/*Stack area - _K_THREAD_STACK, allows the define a stack that will host user threads 
	* If CONFIG_USERSPACE is not enabled, the set of K_THREAD_STACK
	* macros have an identical effect to the K_KERNEL_STACK macros. */
	
	/*-----------------------------------------------------------------------------------------------------------*/	
	/*Spawns SSD1306 THREAD */	
	k_tid_t tid_uart0_serial = k_thread_create(&uart0_serial_data, thread_uart_tx_stack_area, K_THREAD_STACK_SIZEOF(thread_uart_tx_stack_area),
												thread_uart_tx, NULL, NULL, NULL, THREAD_PRIORITY_UART0, 0, K_NO_WAIT);

}


/* Initialize UART0, will return 0 on complettion */
int init_uart0(void)
{

	const struct uart_config uart_cfg = {
    .baudrate = 9600,
    .parity = UART_CFG_PARITY_NONE,
    .stop_bits = UART_CFG_STOP_BITS_1,
    .data_bits = UART_CFG_DATA_BITS_8,
    .flow_ctrl = UART_CFG_FLOW_CTRL_NONE};

	/* Obtain pre-initialised device binding - see device_config.h */
	const struct device *dev_uart0 = device_get_binding(DT_LABEL(UART0));
	if (!dev_uart0)
	{
		/*Unable to retrieve device structure */
		return -ENODEV;
	}
	else
	{
		return uart_configure(dev_uart0, &uart_cfg);
	}
}