#include <EEPROM.h>
#include "GravityTDS.h"

#define TdsSensorPin 34
GravityTDS gravityTds;

float temperature = 30,tdsValue = 0;

void setup()
{
    Serial.begin(9600);
    gravityTds.setPin(TdsSensorPin);
    gravityTds.setKvalueAddress(1);
    gravityTds.setAref(3.3);  //reference voltage on ADC, default 5.0V on Arduino UNO
    gravityTds.setAdcRange(4096);  //1024 for 10bit ADC;4096 for 12bit ADC
    gravityTds.begin();  //initialization
}

void loop()
{
    //temperature = readTemperature();  //add your temperature sensor and read it
    gravityTds.setTemperature(temperature);  // set the temperature and execute temperature compensation
    gravityTds.update();  //sample and calculate
    tdsValue = gravityTds.getTdsValue();  // then get the value
    Serial.print(tdsValue,0);
    Serial.println("ppm");
    delay(1000);
}