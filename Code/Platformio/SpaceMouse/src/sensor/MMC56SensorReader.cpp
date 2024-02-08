/* 
* TimedPulseGenerator.h
*
* Created: 2/7/2024 12:39:13 PM
* Author: Alex
*/


#include <Adafruit_MMC56x3.h>
#include "MMC56SensorReader.h"

extern "C" {
};

using namespace MagneticSensor;

MMC56SensorReader::MMC56SensorReader() {
}

MMC56SensorReader::~MMC56SensorReader() {
}

bool MMC56SensorReader::initSensor(int sensorId, TwoWire* wire) {
	driver = Adafruit_MMC5603(sensorId);
	if (!wire) {
		wire = &Wire;
	}
	return driver.begin(MMC56X3_DEFAULT_ADDRESS, wire);
}

void MMC56SensorReader::shutdownSensor() {
	driver.reset();
}

void MMC56SensorReader::calibrateSensor() {
	// TODO thought to use initial calibration logic from space mouse sketch
}

void MMC56SensorReader::getSensorReading(SensorReading* readingReceiver) {
	driver.getEvent(&sensorReading);
	readingReceiver->x_value = sensorReading.magnetic.x;
	readingReceiver->y_value = sensorReading.magnetic.y;
	readingReceiver->z_value = sensorReading.magnetic.z;
}

SensorReading* MMC56SensorReader::getSensorReading() {
	getSensorReading(&currentReading);
	
	return &currentReading;
}