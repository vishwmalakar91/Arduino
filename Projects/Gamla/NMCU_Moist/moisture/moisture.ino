/*
  vishwa
*/
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#include <LiquidCrystal.h>
#include <math.h>

char auth[] = "cbdbb8e5d10a4d2e821a0e24ae4f08b3";
char ssid[] = "S-404";
char pass[] = "123456789a";


int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor
int buzzer = D2;
int MoistValue;


BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable

  // process received value
}

void setup() {

  Serial.begin(9600); // Starts the serial communication
  pinMode(buzzer, OUTPUT);
  Blynk.begin(auth, ssid, pass);
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

  if (MoistPer < 30)
  {
    digitalWrite(buzzer, HIGH);
    Serial.print("  Buzzer ON - ");
  }
  else
  {
    digitalWrite(buzzer, LOW);
    Serial.print("  Buzzer OFF - ");
  }
  Blynk.run();

}
