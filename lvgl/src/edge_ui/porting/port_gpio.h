/*
 * gpio.h
 *
 *  Created on: Dec 6, 2017
 *      Author: sitara
 */

#ifndef GPIO_H_
#define GPIO_H_

#ifdef __cplusplus
extern "C" {
#endif

#define SYSFS_GPIO_DIR "/sys/class/gpio"

typedef enum {
	MODE_INPUT = 0,
	MODE_OUTPUT = 1
} enum_pin_mode_t;

typedef struct {
	int pin;
} gpio_t;

int gpio_open(gpio_t* gpio);
int gpio_close(gpio_t* gpio);
int gpio_set_direction(gpio_t* gpio, enum_pin_mode_t mode);
int gpio_set_value(gpio_t* gpio, int value);
int gpio_get_value(gpio_t* gpio);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* GPIO_H_ */
