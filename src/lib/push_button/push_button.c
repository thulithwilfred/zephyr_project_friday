#include "device_config/device_config.h"
#include "push_button/push_button.h"
#include "ssd1306/ssd1306_thread.h"
#include <stdio.h>

/* Init GPIO_PIN_31, will return 0 on completion */
//TODO: SET UP AS RISING EDGE IRQ - Currently Output LED
static struct gpio_callback button_data;
int pastTime;
char debug_buff[16];

static inline void write_uart_string(const char *str, const struct device *dev_uart)
{
	/* Send characters until, but not including, null */
	for (size_t i = 0; str[i]; i++)
	{
		uart_poll_out(dev_uart, str[i]);
	}
}

void button_pressed(const struct device *dev, struct gpio_callback *cb, uint32_t pins) {

    if (k_uptime_get() - pastTime >= 300 && !gpio_pin_get_raw(dev, EXT_BUTTON_PIN)) {
            const struct device *dev_uart0 = device_get_binding(DT_LABEL(UART0));

          
            pastTime = k_uptime_get();

            displayMode++;
            clearDisplay = 1;

            /* Debug Statement 
            snprintf(debug_buff, (sizeof(char) * 16), "PB:%d", displayMode);
            write_uart_string(debug_buff, dev_uart0);
            */

            if (displayMode >= 3) {
                displayMode = 0;
            }
    } 
}

int init_gpio(void)
{
	/* Obtain pre-initialised device binding - see device_config.h */
	const struct device *dev_gpio0_usr = device_get_binding(DT_LABEL(GP));

	if (!dev_gpio0_usr)
	{
		/* Unable to retrive device structure */
		return -ENODEV;
	}
	else
	{
		/* Configure GPIO_PIN_31 as GPIO Out for external LED use */
		//return gpio_pin_configure(dev_gpio0_usr, EXT_LED_PIN, GPIO_INPUT | GPIO_ACTIVE_HIGH);

        int r1 = gpio_pin_configure(dev_gpio0_usr, EXT_BUTTON_PIN, GPIO_INPUT | GPIO_PULL_UP | GPIO_ACTIVE_HIGH | GPIO_INT_DEBOUNCE);
        int r2 = gpio_pin_interrupt_configure(dev_gpio0_usr, EXT_BUTTON_PIN, GPIO_INT_EDGE_FALLING);

        gpio_init_callback(&button_data, button_pressed, BIT(EXT_BUTTON_PIN));
        gpio_add_callback(dev_gpio0_usr, &button_data);

        if ((r1 || r2) != 0) {
            /* Initialization Failed */
            //TODO: Finisht init failed sequence
        }
        return (r1);
	}
}