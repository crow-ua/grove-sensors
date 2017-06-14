/*
 * ADPS9002 - Grove Luminance Sensor Library 
 * 
 * Copyright (c) 2015 Seeed Technology Limited
 * Website    : www.seeed.cc / www.seeedstudio.com
 * Authors    : Kavi
 * Create Time: June 2015
 * Change Log :
 *
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include "ADPS9002_LUM.h"

#include <Arduino.h>
/****************************************************************************/
/***       Global Variable                                                 ***/
/****************************************************************************/


Lux LUMfloat VoutArray[] =  { 0.0011498,0.0033908,0.011498,0.041803,0.15199,0.53367,1.3689, 1.9068,2.3};
float  LuxArray[] 	 =  { 1.0108,3.1201, 9.8051,27.43,69.545,232.67,645.11, 973.52,	1000};

/****************************************************************************/
/***       Local Variable                                                 ***/
/****************************************************************************/

/****************************************************************************/
/***       Class member Functions                                         ***/
/****************************************************************************/
float Lux::readAPDS9002Vout(uint8_t analogpin)
{
    // MeasuredVout = ADC Value * (Vcc / 1023) * (3 / Vcc)
    // Vout samples are with reference to 3V Vcc
    // The above expression is simplified by cancelling out Vcc 
    float MeasuredVout = analogRead(A0) * (3.0 / 1023.0);
    //Above 2.3V , the sensor value is saturated
   
    return MeasuredVout;
  
}

float Lux::readLuminance(uint8_t analogpin)
{
    
    // MeasuredVout = ADC Value * (Vcc / 1023) * (3 / Vcc)
    // Vout samples are with reference to 3V Vcc
    // The above expression is simplified by cancelling out Vcc 
    float MeasuredVout = analogRead(A0) * (3.0 / 1023.0);   
    float Luminance = FmultiMap(MeasuredVout, VoutArray, LuxArray, 9);
    
    /**************************************************************************
    
    The Luminance in Lux is calculated based on APDS9002 datasheet -- > Graph 1 
    ( Output voltage vs. luminance at different load resistor)
    The load resistor is 1k in this board. Vout is referenced to 3V Vcc.
    
    The data from the graph is extracted using WebPlotDigitizer 
    http://arohatgi.info/WebPlotDigitizer/app/
    
    VoutArray[] and LuxArray[] are these extracted data. Using MultiMap, the data
    is interpolated to get the Luminance in Lux.
    
    This implementation uses floating point arithmetic and hence will consume 
    more flash, RAM and time.
    
    The Luminance in Lux is an approximation and depends on the accuracy of
    Graph 1 used.
    
    ***************************************************************************/
    
    return Luminance;
}


/****************************************************************************/
/***       Local Functions                                                ***/
/****************************************************************************/
//This code uses MultiMap implementation from http://playground.arduino.cc/Main/MultiMap
//Copyright and License by its original author

float Lux::FmultiMap(float val, float * _in, float * _out, uint8_t size)
{
  // take care the value is within range
  // val = constrain(val, _in[0], _in[size-1]);
  if (val <= _in[0]) return _out[0];
  if (val >= _in[size-1]) return _out[size-1];

  // search right interval
  uint8_t pos = 1;  // _in[0] allready tested
  while(val > _in[pos]) pos++;

  // this will handle all exact "points" in the _in array
  if (val == _in[pos]) return _out[pos];

  // interpolate in the right segment for the rest
  return (val - _in[pos-1]) * (_out[pos] - _out[pos-1]) / (_in[pos] - _in[pos-1]) + _out[pos-1];
}

