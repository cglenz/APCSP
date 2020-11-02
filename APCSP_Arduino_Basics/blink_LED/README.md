

# Blinky Light Tutorial
Exactly what it sounds like - makes an LED connected to the arduino blink - oh yeah!

## Materials
- Arduino
- LED
- 220 Ohm Resistor
- Wires
- Breadboard

## Sketch


<!--- ![blinky_light_sketch](blink_LED_bb.png)   --->

<a href="blink_LED_bb.png"><img src="blink_LED_bb.png" width="480" ></a>

## Code

```
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
```
