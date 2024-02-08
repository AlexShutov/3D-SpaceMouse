#include "MagneticSensorReader.h"

using namespace MagneticSensor;

MagneticSensorReader::MagneticSensorReader() {
}

MagneticSensorReader::~MagneticSensorReader() {
}

SensorReading* MagneticSensorReader::getSensorReading() {
	getSensorReading(&currentReading);
	
	return &currentReading;
}