#ifndef Alt_H
#define Alt_H

class Altmeter
{
    struct sensor_value temp, press, humidity;

    /*
     * Get a device structure from a devicetree node with compatible
     * "bosch,bme280". (If there are multiple, just pick one.)
     */
    public:
        void init(const struct device *dev);
        //static const struct alt_device *get_bme280_device(void);
        void fetch_bmp280_data(const struct device *dev);
        void altitude_calc(const struct device *dev);
};

#endif