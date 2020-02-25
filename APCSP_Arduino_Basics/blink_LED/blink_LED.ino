/*
  

  Blink

  One of the most basic tasks - get the led to blink on and off

  The circuit:
  * LED
  * 220 Ohm resistor

  Created 26 Dec 2013
  By C. Glenz
  Modified 20 Jun 2019
  By C. Glenz


*/


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 12 as an output.
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

// the loop function runs over and over again forever
void loop() {
  delay(1000);              // wait for a second
  digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);              // wait for half a second
}

