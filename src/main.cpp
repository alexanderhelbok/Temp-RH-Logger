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

#include <Wire.h>
#include "HTU21D.h"

//Create an instance of the object
HTU21D myHumidity;

unsigned long previousTime = millis();

void setup()
{
  Serial.begin(9600);
  // Serial.println("Lets Go");

  myHumidity.begin();
}

void loop()
{
  unsigned long currentTime = millis();
  float humd = myHumidity.readHumidity();
  float temp = myHumidity.readTemperature();
  float now = (currentTime - previousTime) / 1000;

  // Serial.print("Time:");
  Serial.println(now);
  // Serial.print(" ");
  Serial.println(temp, 1);
  // Serial.print("C");
  // Serial.print(" ");
  Serial.println(humd, 1);
  // Serial.print("%");

  // Serial.println();
  delay(15000);
}
