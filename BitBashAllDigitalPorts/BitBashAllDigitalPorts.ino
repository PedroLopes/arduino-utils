const int firstPin = 1; //change to first Pin on arduino
const int lastPint = 13; //change to last Pin on arduino
int skipPins[] = {1, 2}; //select which pins you don't want to Bit Bash
const int time = 500; //ms of bit on/off
const int skip_array_size = sizeof(skipPins)/sizeof(int);

void setup() {
  for (int i=firstPin; i<lastPint; i++) if (search_in_array(i,skipPins,skip_array_size)) pinMode(i, OUTPUT);
}

void loop() {
  for (int i=firstPin; i<lastPint; i++) if (search_in_array(i,skipPins,skip_array_size)) digitalWrite(i, HIGH);  
  delay(time);  
  for (int i=firstPin; i<lastPint; i++) if (search_in_array(i,skipPins,skip_array_size)) digitalWrite(i, LOW);   
  delay(time);             
}

boolean search_in_array(int search_term, int array[], int size_of_array){
  for (int i = 0; i < size_of_array; i++) {
    if (search_term == array[i]) {
      return false;
    }
  }
  return true;
}
