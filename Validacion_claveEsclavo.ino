#include <Wire.h>
char dato;
const int led1=8;
const int led2=9;
String deco=" ";

void setup() {
 Wire.begin(4);
 Wire.onReceive(receiveEvent);
 Serial.begin(9600);
 pinMode (led1,OUTPUT);
 pinMode (led2,OUTPUT);
}

void loop() {
}
void receiveEvent(int bytes){
  deco="";
  while(Wire.available()){
    dato=Wire.read();
    deco.concat(dato);
  }
  Serial.println(String ("Clave codificada: ")+String (deco));
  if(deco=="1111"){
    Serial.println("Clave Correcta");
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
  }else{
    Serial.println("Clave incorrecta");
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
  }
}
