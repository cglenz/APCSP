/*
  Ultrasonic Distance Sensor
  ????
  
  The circuit:
  * Ultrasonic sensor
  * 
  * LED
  * 220 Ohm resistor

  Created 20 Sept. 2018
  By C. Glenz
  Modified 
  By C. Glenz

  sensor: https://www.electroschematics.com/8902/hc-sr04-datasheet/

*/


const int triggerPin = 10;
const int echoPin = 11;
const int ledPin = 12;
const float targetDistance = 25.0;
const float tolerance = 2.0;
  
void setup() {
  Serial.begin (9600);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  long duration, distance;
  
  digitalWrite(triggerPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(triggerPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  
  delayMicroseconds(10); // Added this line
  digitalWrite(triggerPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  
  if (distance < (targetDistance + tolerance) && distance > (targetDistance - tolerance)) {  // This is where the LED On/Off happens
    digitalWrite(ledPin,HIGH);
}
  else {
    digitalWrite(ledPin,LOW);
  }
  
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);
} 
