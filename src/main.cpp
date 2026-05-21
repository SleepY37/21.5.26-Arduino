#include <Arduino.h>
#include "oled.h"

const int TRIG_PIN = 9;   
const int ECHO_PIN = 10;  

int readUltrasonicDistance(int trigPin, int echoPin);

void setup() {
  Serial.begin(9600);
  
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  Serial.println("Ultraschallsensor-Test gestartet...");
}

void loop() {
  Serial.print("Entfernung: ");
  Serial.print(readUltrasonicDistance(TRIG_PIN, ECHO_PIN));
  Serial.println(" cm");
  
  delay(200); 
  
  writeToOled("test");
}

int readUltrasonicDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  int duration = pulseIn(echoPin, HIGH);
  
  if (duration == 0) {
    return -1; 
  }
  
  int distanceCM = (duration * 0.0343) / 2;
  return distanceCM;
}
