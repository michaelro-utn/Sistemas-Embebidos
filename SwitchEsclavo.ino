#include<Wire.h>
char m;
const int led1 = 8;
const int led2 = 9;
const int led3 = 10;
const int led4 = 11;

void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  Wire.begin(7);
  Wire.onReceive(receiveEvent); 
  Serial.begin(9600);
}

void loop() {

}

void receiveEvent (int bytes){
  
  while(Wire.available()){
    m=Wire.read();
    switch(m){
      case '1':
      digitalWrite(led1,HIGH);
      digitalWrite(led2,LOW);
      digitalWrite(led3,LOW);
      digitalWrite(led4,LOW);
      break;  
    
     
      case '2':
      digitalWrite(led1,LOW);
      digitalWrite(led2,HIGH);
      digitalWrite(led3,LOW);
      digitalWrite(led4,LOW);
      break;  
    
     
      case '3':
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      digitalWrite(led3,HIGH);
      digitalWrite(led4,LOW);
      break;  
    
      case '4':
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      digitalWrite(led3,LOW);
      digitalWrite(led4,HIGH);
      break;  
    }
  }
  Serial.println(String("El led a encender:")+String(m));
}
