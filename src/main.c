/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/sys/printk.h>

#define GPIO0_NODE DT_NODELABEL(gpio0)

#define nRF70_VBAT_EN	18
#define WIFI_VDDIO_EN	27
#define WIFI_EN			28

#define LED_RED			29
#define LED_BLUE		30
#define LED_GREEN		31

#define BUZZER			26



int main(void)
{
	const struct device *gpio0_dev = DEVICE_DT_GET(GPIO0_NODE);
	if (!device_is_ready(gpio0_dev)) {
		printk("device gpio0_dev error!\n");
    }

	gpio_pin_configure(gpio0_dev, nRF70_VBAT_EN, GPIO_OUTPUT_LOW);
	gpio_pin_configure(gpio0_dev, WIFI_VDDIO_EN, GPIO_OUTPUT_LOW);
	gpio_pin_configure(gpio0_dev, WIFI_EN, GPIO_OUTPUT_LOW);

	gpio_pin_configure(gpio0_dev, LED_RED, GPIO_OUTPUT_LOW);
	gpio_pin_configure(gpio0_dev, LED_BLUE, GPIO_OUTPUT_LOW);
	gpio_pin_configure(gpio0_dev, LED_GREEN, GPIO_OUTPUT_LOW);

	gpio_pin_configure(gpio0_dev, BUZZER, GPIO_OUTPUT_LOW);

	for(;;){
//		printf("Hello World! %s\n", CONFIG_BOARD_TARGET);
		k_msleep(1000);
		
	}
	return 0;
}
