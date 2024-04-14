/* 
* SensorReaderFilteringDecorator.h
*
* Created: 2/13/2024 2:54 PM
* Author: Alex
*/

#ifndef __SENSOR_READER_FILTERING_DECORATOR_H__
#define __SENSOR_READER_FILTERING_DECORATOR_H__

#include <SimpleKalmanFilter.h>
#include "sensor/MMC56/MMC56SensorReader.h"
#include "sensor/MagneticSensorReader.h"
#include "AxisFilterSettings.h"
#include "FilterSettings.h"

extern "C" {
};

namespace MagneticSensor {

class SensorReaderFilteringDecorator: public MagneticSensorReader {

private: 	
public:
	
	virtual bool initSensor(int sensorId, TwoWire* wire = 0);
	virtual void shutdownSensor();
	virtual long getMeasurementDurationMillis();

	/**
	 * Perform sensor calibration (TODO)
	*/
	virtual void calibrateSensor();
	virtual SensorReading* getCalibrationOffset();
	virtual void setCalibrationOffset(SensorReading& offset);

	SensorReaderFilteringDecorator(
		FilterSettings settings,
		MagneticSensorReader* pDecoree
	);
	// free some resources
	virtual ~SensorReaderFilteringDecorator();

protected:

	virtual void getSensorReading(SensorReading* readingReceiver);

private:
	
	void cleanup();
	void initFilters();
	SimpleKalmanFilter* initFilter(AxisFilterSettings settings);


	MagneticSensorReader* pDecoree;
		
	SimpleKalmanFilter* pXFilter;
	SimpleKalmanFilter* pYFilter;
	SimpleKalmanFilter* pZFilter;
};

}
#endif //__SENSOR_READER_FILTERING_DECORATOR_H__

