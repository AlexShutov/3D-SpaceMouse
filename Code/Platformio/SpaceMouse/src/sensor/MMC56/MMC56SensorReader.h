/* 
* TimedPulseGenerator.h
*
* Created: 2/7/2024 12:39:13 PM
* Author: Alex
*/

#include "config/hardware_config.h"
#ifdef USE_MMC56_SENSOR

#ifndef __MMC56_SENSOR_READER_H__
#define __MMC56_SENSOR_READER_H__

#include <Adafruit_MMC56x3.h>
#include "sensor/MMC56/MMC56SensorReader.h"
#include "sensor/MagneticSensorReader.h"

extern "C" {
};

namespace MagneticSensor {

class MMC56SensorReader: public MagneticSensorReader {

private: 	
public:
	
	// TODO: implementations will use default I2C bus address for now
	virtual bool initSensor(int sensorId, TwoWire* wire = 0);
	virtual void shutdownSensor();
	virtual long getMeasurementDurationMillis();

	/**
	 * Perform sensor calibration (TODO)
	*/
	virtual void calibrateSensor();
	
	MMC56SensorReader();
	// free some resources
	virtual ~MMC56SensorReader();

protected:

	virtual void getSensorReading(SensorReading* readingReceiver);

private:
	Adafruit_MMC5603 driver;
	SensorReading currentReading;
	// library reading buffer
	sensors_event_t sensorReading;
};

}
#endif //__MMC56_SENSOR_READER_H__

#endif //USE_MMC56_SENSOR
