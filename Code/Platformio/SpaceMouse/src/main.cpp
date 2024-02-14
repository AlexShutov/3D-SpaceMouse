#include <Arduino.h>
#include <Adafruit_MMC56x3.h>

#include "sensor/MagneticSensorReader.h"
#include "test/SensorTestMMC56.h"

using SensorTests::SensorTestMMC56;

SensorTestMMC56 test = SensorTestMMC56();

void setup(void) {
  test.setup();
}

void loop(void) {
  test.performTest();
  delay(30);
}