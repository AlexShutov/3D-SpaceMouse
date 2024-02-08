/* 
* TimedPulseGenerator.h
*
* Created: 2/7/2024 12:39:13 PM
* Author: Alex
*/


#ifndef __MAGNETIC_SENSOR_READER_H__
#define __MAGNETIC_SENSOR_READER_H__
#include <Wire.h>
#include "SensorReadings.h"

extern "C" {
};

namespace MagneticSensor {
	

class MagneticSensorReader {

private: 	
public:
	
	// TODO: implementations will use default I2C bus address for now
	virtual bool initSensor(int sensorId, TwoWire* wire = 0) = 0;
	virtual void shutdownSensor() = 0;

	/**
	 * Get time required for taking reading from a sensor. TLVD sensor support that, 
	 * MMC56 uses hardcode empiric value
	*/
	virtual long getMeasurementDurationMillis() = 0;

	/**
	 * Perform sensor calibration (TODO)
	*/
	virtual void calibrateSensor() = 0;

	SensorReading* getSensorReading();
	
	MagneticSensorReader();
	// free some resources
	virtual ~MagneticSensorReader() = 0;

protected:

	virtual void getSensorReading(SensorReading* readingReceiver) = 0;

private:

	SensorReading currentReading;
};

}
#endif //__MAGNETIC_SENSOR_READER_H__
