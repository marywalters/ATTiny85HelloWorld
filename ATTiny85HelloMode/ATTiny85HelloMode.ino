    int led = 7; 

    int but = 2;

    int butState;  // current state of the button 
    int prevState; // previous state of the button

    int switchVal; // switch between states

void setup() {
    pinMode(led, OUTPUT);
    pinMode(but,INPUT);
    
    butState = 0;
    prevState = 0;          // initial values

    switchVal = 0;
}

void loop() {
    
  butState = digitalRead(but);  // read the current state of the button
  
if(butState != prevState){       // if the current button state is not what it previoulsy was, read the button
  butState = digitalRead(but);
   if(butState == HIGH){        // if the button is high,
    switchVal++;                // go to next case
   }
}
prevState = butState;           // set the previous state to the one that was read
if (switchVal == 3){            // if switchVal increases to 3,
  switchVal = 0;                // reset to back to 0 since theres only three states
}

switch(switchVal){
 case 0: 
     digitalWrite(led, LOW);    // LED is off
    break;
 case 1:
    digitalWrite(led, HIGH);    // LED is on
    break;
 case 2:
    digitalWrite(led, HIGH);
    delay(100);
    digitalWrite(led, LOW);      // LED binks on for 100 ms and off for 100 ms
    delay(100);
    break;
 default:
    digitalWrite(led, LOW);
    break;
}

}
