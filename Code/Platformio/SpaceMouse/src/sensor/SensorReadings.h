
#ifndef SENSOR_READINGS_H_
#define SENSOR_READINGS_H_

namespace MagneticSensor {

struct SensorReading {
	
    float x_value;
    float y_value;
    float z_value;

	bool operator==(SensorReading &other) {
		return x_value == other.x_value &&
            y_value == other.y_value &&
            z_value == other.z_value;
	}
    
	bool operator!=(SensorReading &op2) {
		return !this->operator ==(op2);
	}
};

}

#endif /* SENSOR_READINGS_H_ */