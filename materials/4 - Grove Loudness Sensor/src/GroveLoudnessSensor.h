#ifndef GroveSlidePotentiometer_H
#define GroveSlidePotentiometer_H

#include <Arduino.h>
#include <Grove.h>

class GroveLoudnessSensor {
	private:
		unsigned int _pinSensor; 
		unsigned int _maxMesurement;
	
	protected:
		unsigned int _performMesurement(); 

	public:
		GroveLoudnessSensor();
		virtual ~GroveLoudnessSensor() {};
		void initialize(GrovePin pins, unsigned int maxMesurement = 1023);
		float getNoiseAmount();
		void setMaxMesurement(unsigned int maxMesurement);
};

#endif