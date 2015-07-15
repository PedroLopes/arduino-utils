//note to self: there is a better approach for Teensy 2.0, check TeensyUARTHardSerialBluetooth_Test
//this is based on   Example Bluetooth Serial Passthrough Sketch  by: Jim Lindblom  SparkFun Electronics date: February 26, 2013, check that license for details
//at https://learn.sparkfun.com/tutorials/using-the-bluesmirf

#include <SoftwareSerial.h>  
#include <Utils.h>
Utils utils(LED_BUILTIN);
const int SETUP_BT = false;

int bluetoothTx = 2; 
int bluetoothRx = 3; 

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup()
{
  Serial.begin(9600);  

  if (SETUP_BT) { //I changed my bluetooth to directly hit the correct baudRate so no need to set up temporary baudRates anymore
    bluetooth.begin(115200);  
    bluetooth.print("$");  
    bluetooth.print("$");
    bluetooth.print("$");  
    delay(100);  
    bluetooth.println("U,9600,N");  
  }
  bluetooth.begin(9600);  
  utils.blink_times(2); //blink twice at the end of setup
}

void loop()
{
  if(bluetooth.available())  
  {
    Serial.print((char)bluetooth.read());  
    utils.blink(); 
    Serial.print("BT");  
    
  }
  if(Serial.available())  
  {
    bluetooth.print((char)Serial.read());
    Serial.print("SER");
    
  }
}

