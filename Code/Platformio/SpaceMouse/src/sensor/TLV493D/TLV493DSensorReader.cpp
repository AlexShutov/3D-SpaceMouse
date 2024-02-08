/* 
* TimedPulseGenerator.h
*
* Created: 2/7/2024 12:39:13 PM
* Author: Alex
*/

#include "config/hardware_config.h"

#ifdef USE_TLV493D_SENSOR
#include "TLV493DSensorReader.h"

#define MEASUREMENT_DURATION_MILLIS 100

extern "C" {
};

using namespace MagneticSensor;

TLV493DSensorReader::TLV493DSensorReader() {
}

TLV493DSensorReader::~TLV493DSensorReader() {
}

bool TLV493DSensorReader::initSensor(int sensorId, TwoWire* wire) {
	driver = Tlv493d();
	driver.begin();
	bool result = driver.setAccessMode(Tlv493d::FASTMODE);
	if (result) {
		driver.disableTemp();
	}
	return result;
}

long TLV493DSensorReader::getMeasurementDurationMillis() {
	return driver.getMeasurementDelay();
}

void TLV493DSensorReader::shutdownSensor() {
	driver.end();
}

void TLV493DSensorReader::calibrateSensor() {
	// TODO thought to use initial calibration logic from space mouse sketch
}

void TLV493DSensorReader::getSensorReading(SensorReading* readingReceiver) {
	driver.updateData();
	readingReceiver->x_value = driver.getX();
	readingReceiver->y_value = driver.getY();
	readingReceiver->z_value = driver.getZ();
}

SensorReading* TLV493DSensorReader::getSensorReading() {
	getSensorReading(&currentReading);
	return &currentReading;
}

#endif // USE_TLV493D_SENSOR