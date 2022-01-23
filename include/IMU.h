#ifndef IMU_H
#define IMU_H

class IMU
{
    public:
        static inline float out_ev(struct sensor_value *val);
        void init(const struct device *devimu);
        void fetch_imu_data(const struct device *devimu);
};
#endif