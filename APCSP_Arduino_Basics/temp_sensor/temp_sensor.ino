/*
  TMP36 Sensor

  This is a basic temperature sensor. The sketch below reads the output from the TMP36,
  converts this to a voltage and then converts that to temperature. The sketch also 
  turns on an LED if the temperature passes some threashold.

  The circuit:
  * TMP36
  * LED
  * 220 Ohm resistor

  Created 9 Aug 2015
  By C. Glenz
  Modified 
  By C. Glenz

  sensor: https://www.adafruit.com/product/165

*/



// voltage should also work with 3.3, but does not, even with "analogReference(EXTERNAL)" - why?

#define aref_voltage 5.0
#define LEDPIN 12

int tempPin = 0;
int tempReading;
float threshTemp = 25.0;

void setup(void) 
{
  Serial.begin(9600);
  
  //analogReference(EXTERNAL);
  pinMode(LEDPIN, OUTPUT);
}

void loop(void) {
  
  tempReading = analogRead(tempPin);
  Serial.print("Raw Temp Sensor Reading = ");
  Serial.println(tempReading);

  float voltage = tempReading * aref_voltage;
  voltage /= 1024.0;

  Serial.print("Sensor voltage = ");
  Serial.print(voltage);
  Serial.println(" volts");

  float tempC = (voltage - 0.5) * 100.0;

  Serial.print(tempC);
  Serial.println(" degrees C");

  float tempF = (tempC * 1.8) + 32.0;
 
  Serial.print(tempF);
  Serial.println(" degrees F");

  Serial.println();

  if (tempC > threshTemp)
  {
    digitalWrite(LEDPIN, HIGH);
  }
  else
  {
    digitalWrite(LEDPIN, LOW);
  }
  
  
  delay(2000);

}
