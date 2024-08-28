#include <IRremote.h>
IRrecv irrecv(2);      // IR module is connected to pin 2
decode_results results; // create a variable of type decode_results
void setup() { 
  Serial.begin(9600); 
  irrecv.enableIRIn(); // initialize irrecv
} 
void loop() { 
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);   // get and decode IR pulses received by the module
    irrecv.resume();                      // get the next value
  }
  delay (100);    // wait 100 milliSeconds
}