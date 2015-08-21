const int firstPin = 1; //change to first Pin on arduino
const int lastPint = 20; //change to last Pin on arduino
int skipPins[] = {1, 2}; //select which pins you don't want to Bit Bash
const int time = 500; //ms of bit on/off
const int skip_array_size = sizeof(skipPins)/sizeof(int);

#include <Utils.h>
Utils utils(13);

void setup() {
  for (int i=firstPin; i<=lastPint; i++) if (!utils.search_in_array(i,skipPins,skip_array_size)) pinMode(i, OUTPUT);
}

void loop() {
  for (int i=firstPin; i<=lastPint; i++) if (!utils.search_in_array(i,skipPins,skip_array_size)) digitalWrite(i, HIGH);  
  delay(time);  
  for (int i=firstPin; i<=lastPint; i++) if (!utils.search_in_array(i,skipPins,skip_array_size)) digitalWrite(i, LOW);   
  delay(time);             
}
