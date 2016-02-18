#include "DHT11.h" //load DHT11 library
#include <TM1637Display.h>//load segmented display library

#define CLK 4
#define DIO 5
#define sensorPin A0

TM1637Display tm1637(CLK, DIO);
dht11 dht11;

void setup() {
  tm1637.setBrightness(0x0F);
}
void loop() {
  dht11.read(sensorPin); //take readings from the DHT sensor
  tm1637.showNumberDec(dht11.temperature, false); //show the temperature for one second
  delay(1000);
  tm1637.showNumberDec(dht11.humidity, false); //show the humidity for one second
  delay(1000);
}
