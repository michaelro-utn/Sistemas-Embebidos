#include <Wire.h>
String contra;
int tama;
int i=0;
String sal;

void setup() {
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0){
    contra=Serial.readString();
    Serial.println("");
    contra.toLowerCase();
//    tama=contra.length();
//    char vector[tama];
//    contra.toCharArray(vector,tama);
//    Serial.println("Contraseña Ingresada!")
    if (contra=="7482"){
      sal="1111";
    }else{
      sal="0000";
    }
    Serial.println("Clave codificada");
    Serial.println(sal);
    Wire.beginTransmission(4);
    Wire.write(sal.c_str());
    Wire.endTransmission();
  }
}
