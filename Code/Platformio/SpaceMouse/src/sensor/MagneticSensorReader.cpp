#include "MagneticSensorReader.h"

using namespace MagneticSensor;

MagneticSensorReader::MagneticSensorReader(bool useCalibration) {
	this->useCalibration = useCalibration;
}

MagneticSensorReader::~MagneticSensorReader() {
}

SensorReading* MagneticSensorReader::getSensorReading() {
	getSensorReading(&currentReading);

	return &currentReading;
}

SensorReading* MagneticSensorReader::getCalibrationOffset() {
	return &calibrationOffset;
}

void MagneticSensorReader::setCalibrationOffset(SensorReading& offset) {
	calibrationOffset = offset;
}

void MagneticSensorReader::calibrateSensor() {
	if (!useCalibration) {
		Serial.print("Calibration is disabled\n");
		return;
	}
	Serial.print("Starting calibration\n");

	calibrationOffset.clear();
	long measurementDelay = getMeasurementDurationMillis();
	for (int i = 0; i < CALIBRATION_READINGS_COUNT; i++) {
		delay(measurementDelay);
		getSensorReading(&currentReading);
		calibrationOffset.x_value += currentReading.x_value;
		calibrationOffset.y_value += currentReading.y_value;
		calibrationOffset.z_value += currentReading.z_value;
		currentReading.clear();
	}
	calibrationOffset.x_value /= CALIBRATION_READINGS_COUNT;
	calibrationOffset.y_value /= CALIBRATION_READINGS_COUNT;
	calibrationOffset.z_value /= CALIBRATION_READINGS_COUNT;	
}