/*
      Utils.h - Library for collecting simple functions I keep on using
      Created by pedro lopes, 2015
      Released into the public domain.
*/

#include "Arduino.h"
#include "Utils.h"

Utils::Utils(int ledPin)
{
	  pinMode(ledPin, OUTPUT);
	  _ledPin = ledPin;
	  _blinkTime = 100; //default value
}
		       
void Utils::set_blinkTime(int blinkTime){
	_blinkTime = blinkTime;
}

int Utils::get_blinkTime(){
	return _blinkTime;
}

void Utils::blink(){
	digitalWrite(_ledPin, HIGH);
	delay(_blinkTime);
	digitalWrite(_ledPin, LOW);
	delay(_blinkTime); 
}

void Utils::blink_times(int times){
	for(int i=0;i<times;i++) blink();
}


boolean Utils::search_in_array(int search_term, int array[], int size_of_array){
	for (int i = 0; i < size_of_array; i++) {
		if (search_term == array[i]) {
			return true;
		}
	}
	return false;
}
