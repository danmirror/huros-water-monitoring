#include <HurosWaterMonitoring.h>

// Initial Pin
#define dallas_pin 23
#define ph_pin 35
#define tds_pin 34

OneWire oneWire(dallas_pin);
DallasTemperature dallas(&oneWire);
HurosWaterMonitoring hwm(dallas);

// Calibration PH
#define ph4 3.226
#define ph7 2.691

// Calibration TDS
#define CALIBRATION_COEF  28.5


void setup() {
  Serial.begin(9600);
  hwm.DallasInit();
  hwm.TDSInit(tds_pin, CALIBRATION_COEF);
  hwm.PHInit(ph_pin, ph4, ph7);

}

void loop() {
  float temp = hwm.DallasGetTemperatureC();
  float ph = hwm.PHGetData();
  float tds = hwm.TDSGetData(temp);

  Serial.print("Temperature C : ");
  Serial.print(temp);
  Serial.print("\tPH(ppm) : ");
  Serial.print(ph);
  Serial.print("\tTDS(ppm) : ");
  Serial.print(tds);

  Serial.println();
}
