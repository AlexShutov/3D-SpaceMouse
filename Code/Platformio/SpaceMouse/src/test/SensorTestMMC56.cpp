
#include "config/hardware_config.h"
#ifdef USE_MMC56_SENSOR

#include <Arduino.h>
#include "SensorTestMMC56.h"


using namespace SensorTests;

SensorTestMMC56::SensorTestMMC56(){}

SensorTestMMC56::~SensorTestMMC56(){
    sensorReader->shutdownSensor();
}

void SensorTestMMC56::setup() {
    initSerial();

    pMmc56SensorReader = new MMC56SensorReader(true);
    
    pFilteringDecorator = new SensorReaderFilteringDecorator(
        getFilterSettings(),
        pMmc56SensorReader
    );
    sensorReader = pFilteringDecorator;

    bool initSuccessful = sensorReader->initSensor(SENSOR_ID);
    if (!initSuccessful) {
        Serial.println("Ooops, no MMC5603 detected ... Check your wiring!");
        while (1) delay(10);
    }
    measurementDurationMillis = sensorReader->getMeasurementDurationMillis();
}

FilterSettings SensorTestMMC56::getFilterSettings() {
    AxisFilterSettings axisSettings = AxisFilterSettings(1.0, 1.0, 0.2);
    
    return FilterSettings(axisSettings, axisSettings, axisSettings);
}

long SensorTestMMC56::getMeasurementDurationMillis() {
    return measurementDurationMillis;
}

void SensorTestMMC56::performTest() {

    SensorReading* flux = sensorReader->getSensorReading();

    // Display the results (magnetic vector values are in micro-Tesla (uT))
    // Serial.print("X: ");
    // Serial.print(flux->x_value);
    // Serial.print("  ");
    // Serial.print("Y: ");
    // Serial.print(flux->y_value);
    // Serial.print("  ");
    // Serial.print("Z: ");
    // Serial.print(flux->z_value);
    // Serial.print("  ");
    // Serial.println("uT");

    sensorReader->calibrateSensor();
    SensorReading* pCalibrationOffset = sensorReader->getCalibrationOffset();
    Serial.print(" x: ");
	Serial.print(pCalibrationOffset->x_value);
	Serial.println();
	Serial.print(" y: ");
	Serial.print(pCalibrationOffset->y_value);
	Serial.println();
	Serial.print(" z: ");
	Serial.print(pCalibrationOffset->z_value);
	Serial.println();
    Serial.print("----------------------------\n");


    delay(1000);
}

void SensorTestMMC56::initSerial() {
    Serial.begin(115200);
    while (!Serial)
    delay(10); // will pause Zero, Leonardo, etc until serial console opens
    Serial.println("Adafruit_MMC5603 Magnetometer Test");
    Serial.println("");
}

#endif // USE_MMC56_SENSOR