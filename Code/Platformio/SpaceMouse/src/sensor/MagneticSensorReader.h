/* 
* TimedPulseGenerator.h
*
* Created: 2/7/2024 12:39:13 PM
* Author: Alex
*/


#ifndef __MAGNETIC_SENSOR_READER_H__
#define __MAGNETIC_SENSOR_READER_H__
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
	 * Perform sensor calibration (TODO)
	*/
	virtual void calibrateSensor() = 0;
	

	virtual void getSensorReading(SensorReading* readingReceiver) = 0;
	virtual SensorReading* getSensorReading() = 0;
	
	MagneticSensorReader();
	// free some resources
	virtual ~MagneticSensorReader();

protected:
private:
};

}
#endif //__MAGNETIC_SENSOR_READER_H__
