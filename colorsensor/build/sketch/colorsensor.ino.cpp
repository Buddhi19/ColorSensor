#include <Arduino.h>
#line 1 "C:\\Users\\msi\\Desktop\\ColorSensor\\colorsensor\\colorsensor.ino"
#include <Wire.h>
#include "Adafruit_TCS34725.h"
#include "colorStruct.h"

Adafruit_TCS34725 tcs = Adafruit_TCS34725();
#line 6 "C:\\Users\\msi\\Desktop\\ColorSensor\\colorsensor\\colorsensor.ino"
void setup(void);
#line 16 "C:\\Users\\msi\\Desktop\\ColorSensor\\colorsensor\\colorsensor.ino"
void loop(void);
#line 6 "C:\\Users\\msi\\Desktop\\ColorSensor\\colorsensor\\colorsensor.ino"
void setup(void) {
  Serial.begin(9600);
  if (tcs.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1);
  }
}
Color e1 = Color(&tcs);
void loop(void) {

    int color = e1.colorSegment();

    Serial.println(color);
 
    delay(100);
}
