#include <Wire.h>
#define LEDPIN 10
#define ANALOGPIN A0
#define I2C_ADDRESS 0x0A
int analogValue = 0;

void receiveHandler(int numBytes);
void requestHandler();



void setup() {
  
  Wire.begin(I2C_ADDRESS);
  Wire.onReceive(receiveHandler);
  Wire.onRequest(requestHandler);
  
  pinMode(LEDPIN,OUTPUT);
  pinMode(ANALOGPIN,INPUT);
}

void loop() {
  analogValue = analogRead(ANALOGPIN);
  delay(1000);
}


/*Functions*/

 void receiveHandler(int numBytes){
    int data=0;
    data=Wire.read() ;
    if(data){
      digitalWrite(LEDPIN,HIGH);
    }
    else{
      digitalWrite(LEDPIN,LOW);
    }
 }

 void requestHandler(void){
  Wire.write(analogValue);
 }

