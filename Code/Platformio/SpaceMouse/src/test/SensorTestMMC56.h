#include <Adafruit_MMC56x3.h>
#include "sensor/MagneticSensorReader.h"
#include "sensor/MMC56/MMC56SensorReader.h"
#include "sensor/filtering/SensorReaderFilteringDecorator.h"
#include "sensor/filtering/FilterSettings.h"

#include "config/hardware_config.h"

#ifdef USE_MMC56_SENSOR

#ifndef __SENSOR_TEST_MMC56_H__
#define __SENSOR_TEST_MMC56_H__

#define SENSOR_ID 12345

using namespace MagneticSensor;
namespace SensorTests {

class SensorTestMMC56 {
public:

    SensorTestMMC56();
    ~SensorTestMMC56();

    void setup();

    void performTest();

    long getMeasurementDurationMillis();

private:

    MagneticSensorReader* sensorReader;
    MMC56SensorReader* pMmc56SensorReader;
    SensorReaderFilteringDecorator* pFilteringDecorator;
    long measurementDurationMillis;

    void initSerial();
    FilterSettings getFilterSettings();
};

}

#endif //__SENSOR_TEST_MMC56_H__

#endif // USE_MMC56_SENSOR