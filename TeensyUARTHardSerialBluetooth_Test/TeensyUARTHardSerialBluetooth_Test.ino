//Note to self: this works on the Teensy2.0 because there is an additional UART hooked up to pins 7 and 8 (D2 and D3)
//see: https://www.pjrc.com/teensy/td_uart.html

#include <Utils.h>
Utils utils(LED_BUILTIN);

#define HWSERIAL Serial1

void setup() {
	Serial.begin(9600);
        HWSERIAL.begin(9600);
        utils.blink_times(2); //blink twice and you know setup is done
}

void loop() {
        int incomingByte;
        
	if (Serial.available() > 0) {
		incomingByte = Serial.read();
		Serial.print("USB received: ");
		Serial.println(incomingByte, DEC);
                HWSERIAL.print("USB received:");
                HWSERIAL.println(incomingByte, DEC);
	}
	if (HWSERIAL.available() > 0) {
		incomingByte = HWSERIAL.read();
		Serial.print("UART received: ");
		Serial.println(incomingByte, DEC);
                HWSERIAL.print("UART received:");
                HWSERIAL.println(incomingByte, DEC);
                utils.blink(); //blink on incoming UART byte (for instance bluetooth connection here)
	}
}

