#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <drivers/sensor.h>
#include <stdio.h>
#include <sys/util.h>
#include <Alt.h>

const struct device *dev = NULL;

void Altmeter::init(const struct device *dev){
/*
 * Get a device structure from a devicetree node with compatible
 * "bosch,bme280". (If there are multiple, just pick one.)
 */

    dev = DEVICE_DT_GET_ANY(bosch_bme280);

    if (dev == NULL)
    {
        /* No such node, or the node does not have status "okay". */
        printk("\nError: no device found.\n");
    }

    if (!device_is_ready(dev))
    {
        printk("\nError: Device \"%s\" is not ready; "
           "check the driver initialization logs for errors.\n",
           dev->name);
    }

    printk("Found device \"%s\", getting sensor data\n", dev->name);    
    
}

void Altmeter::fetch_bmp280_data(const struct device *dev)
{
    struct sensor_value temp, press, humidity, altitude;

    sensor_sample_fetch(dev);
    sensor_channel_get(dev, SENSOR_CHAN_AMBIENT_TEMP, &temp);
    sensor_channel_get(dev, SENSOR_CHAN_PRESS, &press);
    sensor_channel_get(dev, SENSOR_CHAN_ALTITUDE, &altitude);
    sensor_channel_get(dev, SENSOR_CHAN_HUMIDITY, &humidity);

    printk("temp: %d.%06d; press: %d.%06d; altitude: %d.%06d; humidity: %d.%06d\n",
           temp.val1, temp.val2, press.val1, press.val2, altitude.val1, altitude.val2,
           humidity.val1, humidity.val2);
}