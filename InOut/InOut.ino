/*
Zach Thomas
HCDE 439: Physical Computing
Assignment 3: Input/Output
*/

// These constants won't change. They're used to give names to the pins used:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int outputValue9 = 0;        // value output to the PWM (analog out)
int outputValue10 = 0;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map analog in value to the range of the analog out for light 1:
  outputValue9 = map(sensorValue, 115, 365, 5, 250);
  // map analog in value to the range of the analog out for light 2:
  outputValue10 = map(sensorValue, 365, 115, 5, 250);
  // Check if the analog in is within the normal parameters:
  if(sensorValue > 115 && sensorValue < 365) {
    // Set analog out 1:
    analogWrite(9, outputValue9);
    // Set analog out 2:
    analogWrite(10, outputValue10);
    // Check if the sensor value is too high:
  } else if(sensorValue > 365) {
    // Set analog 1:
    analogWrite(9, 250);
    // Set analog 2:
    analogWrite(10, 5);
    // If analog in is too low:
  } else {
    // Set analog 1:
    analogWrite(9, 5);
    // Set analog 2:
    analogWrite(10, 250);
  }

  // print the results to the Serial Monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t Light One = ");
  Serial.print(outputValue9);
  Serial.print("\t Light Two = ");
  Serial.println(outputValue10);

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(2);
}
