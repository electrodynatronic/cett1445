/*
  Analog input, serial output
  Built to interface with a python script which posts data to cosm.com
Waits for incoming serial one-byte messages, reads & parses them, and sends an answer via the serial port
 Reads an analog input pin, scales and prints data

 
 The circuit:
 LM35 output is connected to Analog In 3
 Phototransistor circuit output is connected to Analog In 0
 Potentiometer wiper connected to analog pin 1.
 Center pin of the potentiometer goes to the analog pin.
 side pins of the potentiometer go to +5V and ground
// Photocell + Resistor 3.3k connected to Analog In 5  NOTE, no photocells are available 
 
 This example code is in the public domain.
 
 */

// These constants won't change.  They're used to give names
// to the pins used: 
const int analogLightInput = A0;  // Analog input pin that the phototransistor is attached to
const int analogPotInput = A1;    // Analog input pin that the potentiometer is attached to
const int analogTempInput = A3; // Analog output pin that the LM35 is attached to

int LightSensorValue = 0;        // value read from the pot
int TempSensorValue = 0;        // value output to the PWM (analog out)
char command='0';
boolean ticker=0;               //Holds state for our indicator LED

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
  pinMode(13,OUTPUT);
  tick();                      //Toggle the LED connected to 13
}

void loop() {
  // read the analog in value:
  while (Serial.available()){
  command=Serial.read();
  }
  switch (command) {
    case 't':    
    case 'T':    //read temperature and lighting status, and print them to the serial port
      readAndSendData();
      break;
    case 'a':    
    case 'A':    //
      Serial.print(command);
      readAndSendAllData();
      break;
    case 'b':    
    case 'B':    //
      Serial.print(command);
      noFunctionYet();
      break;
    case 'c':    
    case 'C':    
      Serial.print(command);
      noFunctionYet();
      break;
    case 'd':    
    case 'D':    
      Serial.print(command);
      noFunctionYet();
      break;
    case 'e':    
    case 'E':    
      Serial.print(command);
      noFunctionYet();
      break;
    case 'h':
    case 'H':
      noFunctionYet();
      break;
    case 'l':
    case 'L':
      Serial.print(command);
      Serial.print("=");
      readAndSendLightLevel();
      break;
    default:
      notDefined();
      break;
      }
      command ='0';
      tick();//Toggle the LED connected to 13

  
}
void noFunctionYet(){
  Serial.print("Nothing to do yet for: ");
  Serial.print(command);
  Serial.println(". Try another.");
  
}
void notDefined(){
  if (command != '0'){
    Serial.print(command);
    Serial.println(" is not defined. Bad command.");
  }
  
}
void readAndSendLightLevel(){
//  LightSensorValue = analogRead(analogLightInput); 
//  Serial.print(LightSensorValue);
  Serial.println(analogRead(analogLightInput));
}
void readAndSendData(){
  LightSensorValue = analogRead(analogLightInput);            
  TempSensorValue = analogRead(analogTempInput);            
// print the results to the serial monitor:
//  Serial.print("light = " );                       
  Serial.print(LightSensorValue);  
  Serial.print(" ");  
//  Serial.print(" \t temperature = ");      
  Serial.print(map(TempSensorValue,0,1023,0,500));   
  Serial.flush();
  // wait 10 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(10);    //ugly hack    
  }
  
void readAndSendAllData(){
  LightSensorValue = analogRead(analogLightInput);            
  TempSensorValue = analogRead(analogTempInput);            
// print the results to the serial monitor:
//  Serial.print("light = " );                       
  Serial.print(LightSensorValue);  
  Serial.print(" ");  
//  Serial.print(" \t temperature = ");      
  Serial.print(map(analogRead(A0),0,1023,0,500));   
  Serial.print(" ");  
//  Serial.print(" \t temperature = ");      
  Serial.print(map(analogRead(A1),0,1023,0,500));   
  Serial.print(" ");  
//  Serial.print(" \t temperature = ");      
  Serial.print(map(analogRead(A2),0,1023,0,500));   
  Serial.print(" ");  
//  Serial.print(" \t temperature = ");      
  Serial.print(map(analogRead(A4),0,1023,0,500));   
  
  Serial.flush();
  // wait 10 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(10);    //ugly hack    
  
  
}

void tick(){
  ticker=!ticker;
  digitalWrite(13,ticker);
}

