#include "_BASE.h"
void setup() {
  clockFreq(80);                        //Specify in MHZ
  singlePWMSetup(1); 
 
}

void loop() {
  
  writePWM(1,5000,.5);
}
