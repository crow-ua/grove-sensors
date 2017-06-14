/* ADPS9002 - Grove Luminance Sensor.

*/

#include <Arduino.h>
#include <ADPS9002_LUM.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("ADPS9002 Sensor Output= ");
  Serial.print(readAPDS9002Vout(A0));
  Serial.print(" Volts, Luminance= ");
  Serial.print(readLuminance(A0));
  Serial.println(" Lux");
  delay(500);
}
