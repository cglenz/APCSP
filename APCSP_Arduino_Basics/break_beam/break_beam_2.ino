/*
	Break Beam Sensor

	This sensor consists of an IR LED and a detector which can be set up to 
	send a signal if the beam is broken. Can use 3.3 V or 5.0 V.

	The circuit:
	* break-beam sensor
	* LED
	* 220 Ohm resistor

	Created 9 Aug 2015
	By C. Glenz
	Modified 
	By C. Glenz

	sensor: https://www.adafruit.com/product/2167

*/

#define aref_voltage 5.0
#define LEDPIN 13
#define SENSORPIN 4

// define and initialize variables for the state of the break-beam sensor.
int sensorState = 0;
int lastState = 0;

unsigned long startTime;
unsigned long finishTime;
unsigned long elapsedTime;

void setup(void) 
{
  Serial.begin(9600);
  analogReference(EXTERNAL);
  pinMode(LEDPIN, OUTPUT);
}

void loop(void) {
  
  sensorState = digitalRead(SENSORPIN);
  if (digitalRead(SENSORPIN) == LOW)
  {
    digitalWrite(LEDPIN, HIGH);
  }
  else
  {
    digitalWrite(LEDPIN, LOW);
  }
  if (sensorState && !lastState)
  {
    finishTime=millis();
    elapsedTime=finishTime-startTime;
    Serial.print("Unbroken - ");
    Serial.print(elapsedTime);
    Serial.println(" ms elapsed");
    Serial.println();
  }
  if (!sensorState && lastState)
  {
    startTime=millis();
    Serial.println("Broken");
  }
  
  lastState = sensorState;
  
  
  //delay(500);

}
