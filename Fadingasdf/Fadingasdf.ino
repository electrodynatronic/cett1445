/*
 Fading
 
 This example shows how to fade an LED using the analogWrite() function.
 
 The circuit:
 * LED attached from digital pin 9 to ground.
 
 Created 1 Nov 2008
 By David A. Mellis
 modified 30 Aug 2011
 By Tom Igoe
 
 http://arduino.cc/en/Tutorial/Fading
 
 This example code is in the public domain.
 
 */
#define WAIT 3
#define RED 9
#define GREEN 6
#define TRIGGER 13
boolean status_blinker =0;
void setup()  { 
  // nothing happens in setup 
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(TRIGGER, OUTPUT);
} 

void loop()  {
 
 statusBlink(); 
  // fade in from min to max in increments of 5 points:
  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=1) { 
    // sets the value (range from 0 to 255):
    analogWrite(RED, fadeValue);         
    analogWrite(GREEN, 255-fadeValue);         
    // wait for 30 milliseconds to see the dimming effect    
    delay(WAIT);                            
    //statusBlink();
  } 

  // fade out from max to min in increments of 5 points:
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=1) { 
    // sets the value (range from 0 to 255):
    analogWrite(RED, fadeValue);         
    analogWrite(GREEN, 255-fadeValue);         
    // wait for 30 milliseconds to see the dimming effect    
    delay(WAIT);
//statusBlink();    
  } 
}

void statusBlink(){
  status_blinker = !status_blinker;
  digitalWrite(TRIGGER,status_blinker); 
  
}


