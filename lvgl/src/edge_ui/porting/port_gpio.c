/*
 * gpio.c
 *
 *  Created on: Dec 6, 2017
 *      Author: sitara
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#include "port_gpio.h"

/*============================================================================*/
/*
 Function:
 Parameters:
 Returns:
 Description:
 */
int gpio_open(gpio_t* gpio)
{
	char path[64];
	snprintf(path, sizeof(path), SYSFS_GPIO_DIR "/gpio%d", gpio->pin);

	if(access(path, F_OK) < 0)
	{
		int ret;
		char cmd[64];
		snprintf(cmd, sizeof(cmd), "echo %d > " SYSFS_GPIO_DIR "/export", gpio->pin);
		ret = system(cmd);
		if(ret < 0)
		{
			return -1;
		}
	}

	return 0;
}

/*============================================================================*/
/*
 Function:
 Parameters:
 Returns:
 Description:
 */
int gpio_close(gpio_t* gpio)
{
	char path[64];
	snprintf(path, sizeof(path), SYSFS_GPIO_DIR "/gpio%d", gpio->pin);

	if(access(path, F_OK) == 0)
	{
		int ret;
		char cmd[64];
		snprintf(cmd, sizeof(cmd),"echo %d > " SYSFS_GPIO_DIR "/unexport", gpio->pin);
		ret = system(cmd);
		if(ret < 0)
		{
			return -1;
		}
	}

	return 0;
}

/*============================================================================*/
/*
 Function:
 Parameters:
 Returns:
 Description:
 */
int gpio_set_direction(gpio_t* gpio, enum_pin_mode_t mode)
{
	int fd;
	char buf[64];
	snprintf(buf, sizeof(buf), SYSFS_GPIO_DIR "/gpio%d/direction", gpio->pin);

	if((fd = open(buf, O_WRONLY | O_NOCTTY /*| O_NDELAY*/)) < 0)
	{
		return -1;
	}

	char val[4] = {'\0'};
	if(mode == MODE_INPUT)
		snprintf(val, sizeof(val), "in");
	else if(mode == MODE_OUTPUT)
		snprintf(val, sizeof(val), "out");

	if(write(fd, val, strlen(val)) < 0)
	{
		close(fd);
		return -1;
	}

	close(fd);
	return 0;
}

/*============================================================================*/
/*
 Function:
 Parameters:
 Returns:
 Description:
 */
int gpio_set_value(gpio_t* gpio, int value)
{
	int fd;
	char buf[64];
	snprintf(buf, sizeof(buf), SYSFS_GPIO_DIR "/gpio%d/value", gpio->pin);

	if((fd = open(buf, O_WRONLY | O_NOCTTY /*| O_NDELAY*/)) < 0)
	{
		return -1;
	}

	char val[4] = {'\0'};
	snprintf(val, sizeof(val), "%d", value);
	if(write(fd, val, strlen(val)) < 0)
	{
		close(fd);
		return -1;
	}

	close(fd);
	return 0;
}

/*============================================================================*/
/*
 Function:
 Parameters:
 Returns:
 Description:
 */
int gpio_get_value(gpio_t* gpio)
{
	int fd;
	char buf[64];
	snprintf(buf, sizeof(buf), SYSFS_GPIO_DIR "/gpio%d/value", gpio->pin);

	if((fd = open(buf, O_RDONLY | O_NOCTTY /*| O_NDELAY*/)) < 0)
	{
		return -1;
	}

	char val[4];
	if(read(fd, val, sizeof(val)) < 0)
	{
		close(fd);
		return -1;
	}

	close(fd);
	return atoi(val);
}
