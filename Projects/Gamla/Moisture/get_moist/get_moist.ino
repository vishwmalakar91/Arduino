/*
  LiquidCrystal Library - Hello World

  This sketch prints "Hello World!" to the LCD
  and shows the time.

  The circuit:
   LCD RS pin to digital pin 12,   LCD Enable pin to digital pin 11,   LCD D4 pin to digital pin 5,   LCD D5 pin to digital pin 4
   LCD D6 pin to digital pin 3,   LCD D7 pin to digital pin 2,   LCD R/W pin to ground,   LCD VSS pin to ground
   LCD VCC pin to 5V,
*/

// include the library code:
#include <LiquidCrystal.h>
#include <math.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor

int buzzer = 7;

int MoistValue;
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2); // Print a message to the LCD.
  Serial.begin(9600); // Starts the serial communication
  pinMode(buzzer, OUTPUT);

}

void loop() {
  sensorValue = analogRead(sensorPin);
  MoistValue = 1024 - sensorValue;
  Serial.print(MoistValue);
  Serial.print(" Soil Moisture Level =");
  int MoistPer = MoistValue / 9;
  Serial.print(MoistPer);
  Serial.print("%");
  Serial.print("\n");

  if(MoistPer<30)
  {
   digitalWrite(buzzer, HIGH);
     Serial.print("  Buzzer ON - ");
    }
    else
    {
      digitalWrite(buzzer, LOW);
      Serial.print("  Buzzer OFF - ");
      }

  lcd.setCursor(0, 0);
  lcd.print("hello, Vishwa :)");
  delay(100);
  lcd.setCursor(0, 1);
  lcd.print("Soil Moist=");

  lcd.print(MoistPer);
  lcd.print("%");
  delay(100);


}
