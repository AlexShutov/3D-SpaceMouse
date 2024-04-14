/* 
* SensorReaderFilteringDecorator.cpp
*
* Created: 2/13/2024 2:54 PM
* Author: Alex
*/

#include <SimpleKalmanFilter.h>
#include "SensorReaderFilteringDecorator.h"
#include "sensor/MagneticSensorReader.h"

extern "C" {
};

using namespace MagneticSensor;

SensorReaderFilteringDecorator::SensorReaderFilteringDecorator(
	FilterSettings settings,
	MagneticSensorReader* pDecoree
) {
	this->pDecoree = pDecoree;	
	pXFilter = initFilter(settings.xSettings);
	pYFilter = initFilter(settings.ySettings);
	pZFilter = initFilter(settings.zSettings);
}

SensorReaderFilteringDecorator::~SensorReaderFilteringDecorator() {
	delete pXFilter;
	delete pYFilter;
	delete pZFilter;
}

SimpleKalmanFilter* SensorReaderFilteringDecorator::initFilter(AxisFilterSettings settings) {
	return new SimpleKalmanFilter(
		settings.mea_e,
		settings.est_e,
		settings.q
	);
}

void SensorReaderFilteringDecorator::calibrateSensor() {
	pDecoree->calibrateSensor();
}

SensorReading* SensorReaderFilteringDecorator::getCalibrationOffset() {
	return pDecoree->getCalibrationOffset();
}

void SensorReaderFilteringDecorator::setCalibrationOffset(SensorReading& offset) {
	pDecoree->setCalibrationOffset(offset);
}

bool SensorReaderFilteringDecorator::initSensor(int sensorId, TwoWire* wire) {
	return pDecoree->initSensor(sensorId, wire);
}

void SensorReaderFilteringDecorator::shutdownSensor() {
	pDecoree-> shutdownSensor();
}

long SensorReaderFilteringDecorator::getMeasurementDurationMillis() {
	return pDecoree->getMeasurementDurationMillis();
}

void SensorReaderFilteringDecorator::getSensorReading(SensorReading* readingReceiver) {
	SensorReading* unfiltered = pDecoree->getSensorReading();

	readingReceiver->x_value = pXFilter->updateEstimate(unfiltered->x_value);
	readingReceiver->y_value = pYFilter->updateEstimate(unfiltered->y_value);
	readingReceiver->z_value = pZFilter->updateEstimate(unfiltered->z_value);
}

