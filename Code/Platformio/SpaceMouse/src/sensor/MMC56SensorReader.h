/* 
* TimedPulseGenerator.h
*
* Created: 2/7/2024 12:39:13 PM
* Author: Alex
*/


#ifndef __MMC56_SENSOR_READER_H__
#define __MMC56_SENSOR_READER_H__
#include <Adafruit_MMC56x3.h>
#include "SensorReadings.h"
#include "MagneticSensorReader.h"

extern "C" {
};

namespace MagneticSensor {

class MMC56SensorReader: MagneticSensorReader {

private: 	
public:
	
	// TODO: implementations will use default I2C bus address for now
	virtual bool initSensor(int sensorId, TwoWire* wire = 0);
	virtual void shutdownSensor();

	/**
	 * Perform sensor calibration (TODO)
	*/
	virtual void calibrateSensor();
	

	virtual void getSensorReading(SensorReading* readingReceiver);
	virtual SensorReading* getSensorReading();
	
	MMC56SensorReader();
	// free some resources
	virtual ~MMC56SensorReader();

protected:
private:
	Adafruit_MMC5603 driver;
	SensorReading currentReading;
	// library reading buffer
	sensors_event_t sensorReading;
};

}
#endif //__MMC56_SENSOR_READER_H__
