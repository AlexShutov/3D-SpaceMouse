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

#define CALIBRATION_READINGS_COUNT 300

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
	 * sensor calibration
	*/
	virtual void calibrateSensor();
	virtual SensorReading* getCalibrationOffset();
	virtual void setCalibrationOffset(SensorReading& offset);

	SensorReading* getSensorReading();
	
	MagneticSensorReader(bool useCalibration = true);
	// free some resources
	virtual ~MagneticSensorReader() = 0;
	
protected:

	virtual void getSensorReading(SensorReading* readingReceiver) = 0;
	bool useCalibration;

private:

	SensorReading currentReading;
	SensorReading calibrationOffset;
};

}
#endif //__MAGNETIC_SENSOR_READER_H__
