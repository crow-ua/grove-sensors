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

#ifndef _ADPS9002_LUM
#define _ADPS9002_LUM

/****************************************************************************/
/***        Including Files                                               ***/
/****************************************************************************/

#include <Arduino.h>


/****************************************************************************/
/***        Class Definition                                              ***/
/****************************************************************************/
class Lux
{
public:
	void begin();
	float readAPDS9002Vout(uint8_t analogpin);
	float readLuminance(uint8_t analogpin);
        float FmultiMap(float val, float * _in, float * _out, uint8_t size)

};
extern Lux LUM; 
#endif//ADPS9002_LUM_H

