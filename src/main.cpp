/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 * Copyright (c) 2021 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <drivers/sensor.h>
#include <stdio.h>
#include <sys/util.h>
#include <Alt.h>
#include <IMU.h>

int main(void)
{
	const struct device *devbmp = NULL;
	const struct device *devimu = NULL;
	Altmeter altmeter;
	IMU imu;
	altmeter.init(devbmp);
	imu.init(devimu);

	while (1) {
		altmeter.fetch_bmp280_data(devbmp);
		imu.fetch_imu_data(devimu);
		k_sleep(K_MSEC(25));
	}

    return 0;
}