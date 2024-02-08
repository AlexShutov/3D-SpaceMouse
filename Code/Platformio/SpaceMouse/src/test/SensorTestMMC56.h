#include <Adafruit_MMC56x3.h>

#ifndef __SENSOR_TEST_MMC56_H__
#define __SENSOR_TEST_MMC56_H__

namespace SensorTests {

class SensorTestMMC56 {
public:

    SensorTestMMC56();
    ~SensorTestMMC56();

    void setup();

    void performTest();

private:

    Adafruit_MMC5603 mmc;

    void initSerial();
};

}

#endif //__SENSOR_TEST_MMC56_H__