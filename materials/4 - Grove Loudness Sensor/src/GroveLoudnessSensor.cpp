#include "GroveLoudnessSensor.h"

GroveLoudnessSensor::GroveLoudnessSensor() {}

void GroveLoudnessSensor::initialize(GrovePin pins, unsigned int maxMesurement) {
	this->_pinSensor = pins.pin1;
	this->setMaxMesurement(maxMesurement);
}

unsigned int GroveLoudnessSensor::_performMesurement() {
	return analogRead(this->_pinSensor);
}

float GroveLoudnessSensor::getNoiseAmount() {
	unsigned int value = this->_performMesurement();
	float position = (float)value / this->_maxMesurement;
	if(position > 1) { position = 1; } else if(position < 0) { position = 0; }
	return position;
}

void GroveLoudnessSensor::setMaxMesurement(unsigned int maxMesurement) {	
	this->_maxMesurement = maxMesurement;
}
