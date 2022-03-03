/* 
 HTU21D Humidity Sensor Example Code
 
 Uses the HTU21D library to display the current humidity and temperature
 
 Open serial monitor at 9600 baud to see readings. Errors 998 if not sensor is detected. Error 999 if CRC is bad.
  
 Hardware Connections (Breakoutboard to Arduino):
 -VCC = 3.3V
 -GND = GND
 -SDA = A4 (use inline 330 ohm resistor if your board is 5V)
 -SCL = A5 (use inline 330 ohm resistor if your board is 5V)

 */

#include <Arduino.h>
#include <Wire.h>
#include <avr/sleep.h>
#include "HTU21D.h"

//Create an instance of the object
HTU21D myHumidity;

unsigned long Interval = 15000;   // Interval for readouts (in ms)
unsigned long Duration = 180;      // Duration of the test (in min)
unsigned long startTime, currentTime, previousTime = -Interval;

double humd, temp, now;

void setup()
{
  Serial.begin(9600);
  // Serial.println("Lets Go");
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  myHumidity.begin();
  startTime = millis();
}

void loop()
{
  currentTime = millis();
  now = (currentTime - startTime) / 1000.0;
  if (now < Duration * 60){
    if (currentTime - previousTime > Interval){
    previousTime = millis();
    humd = myHumidity.readHumidity();
    temp = myHumidity.readTemperature();
    // Serial.print("Time:");
    Serial.println(now);
    // Serial.print(" ");
    Serial.println(temp, 1);
    // Serial.print("C");
    // Serial.print(" ");
    Serial.println(humd, 1);
    // Serial.print("%");
    // Serial.println();
    }
  }
  else{
    sleep_mode();
  }
}
