#ifndef PUSH_BUTTON_H
#define PUSH_BUTTON_H

int init_gpio(void);

void button_pressed(const struct device *dev, struct gpio_callback *cb, uint32_t pins);

#endif