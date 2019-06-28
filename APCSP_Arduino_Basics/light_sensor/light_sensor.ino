/*
  Photoresistor Light Sensor



  The circuit:
  * Photoresistor
  * 10K Ohm resistor
  * LED
  * 220 Ohm resistor

  Created 9 Aug 2015
  By C. Glenz
  Modified 
  By C. Glenz

  sensor: https://www.adafruit.com/product/161

*/


#define aref_voltage 5.0
#define ledPin 12

int lightPin = 0;
int lightReading;
float thresh = 350.0;

void setup(void) 
{
  Serial.begin(9600);
  
  //analogReference(EXTERNAL);
  pinMode(ledPin, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop(void) {
  
  lightReading = analogRead(lightPin);
  Serial.print("Raw Photoresistor Reading = ");
  Serial.println(lightReading);

  Serial.println();

  if (lightReading < thresh)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
  
  
  delay(2000);

}
