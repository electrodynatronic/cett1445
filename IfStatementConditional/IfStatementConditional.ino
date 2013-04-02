/*
  Conditionals - If statement
 
 This example demonstrates the use of if() statements.
 It reads the state of a potentiometer (an analog input) and turns on an LED
 only if the LED goes above a certain threshold level. It prints the analog value
 regardless of the level.
 
 The circuit:
 * potentiometer connected to analog pin 0.
 Center pin of the potentiometer goes to the analog pin.
 side pins of the potentiometer go to +5V and ground
 * LED connected from digital pin 13 to ground
 
 * Note: On most Arduino boards, there is already an LED on the board
 connected to pin 13, so you don't need any extra components for this example.
 
 created 17 Jan 2009
 modified 30 Aug 2011
 by Tom Igoe

This example code is in the public domain.
 
http://arduino.cc/en/Tutorial/IfStatement
 
 */
 
// These constants won't change:
const int analogPin = A0;    // pin that the sensor is attached to
const int ledPin = 13;       // pin that the LED is attached to
//const int threshold = 400;   // an arbitrary threshold level that's in the range of the analog input

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize serial communications:
  Serial.begin(9600);
}

void loop() {
  // read the value of the potentiometer:
  int analogValue = analogRead(analogPin);

  // if the analog value is high enough, turn on the LED:
  if (analogValue > 768) {
  Serial.print(analogValue);
    Serial.println("\tdark");
  } 
  if (analogValue > 512 && analogValue <=768) {
  Serial.print(analogValue);
    Serial.println("\tdim");
  } 
  if (analogValue > 256 && analogValue <=512) {
  Serial.print(analogValue);
    Serial.println("\tmedium");
  } 
  if (analogValue <=256) {
  Serial.print(analogValue);
    Serial.println("\tbright");
  } 
delay(33);
  // print the analog value:

}
//    digitalWrite(ledPin, HIGH);
//  else {
//    digitalWrite(ledPin,LOW); 
//  }

