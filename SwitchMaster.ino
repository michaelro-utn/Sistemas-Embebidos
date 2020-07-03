
#include <Wire.h>
char m;
const int btn1=8;
const int btn2=9;
const int btn3=10;
const int btn4=11;
int conditional;


void setup() {
  Wire.begin();
  Serial.begin(9600);
  pinMode (btn1,INPUT);
  pinMode (btn2,INPUT);
  pinMode (btn3,INPUT);
  pinMode (btn4,INPUT);
}

void loop() {
  if(Serial.available()>0){ //Revisa si existen mensajes en el registro de comunicación serial
    m=Serial.read(); // En caso de tener mensajes, lo almacena en la variable llamada dato
   }
  if(digitalRead (btn1)==HIGH){
    conditional=1;
  }
  if(digitalRead (btn1==LOW && conditional==1)){
    delay(300);
    conditional=1-conditional;
    if(conditional==0){
      m='1';
    }
  }
  conditional=0;
  if(digitalRead (btn2)==HIGH){
    conditional=1;
  }
  if(digitalRead (btn2==LOW && conditional==1)){
    delay(300);
    conditional=1-conditional;
    if(conditional==0){
      m='2';
    }
  }
  conditional=0;
  if(digitalRead (btn3)==HIGH){
    conditional=1;
  }
  if(digitalRead (btn3==LOW && conditional==1)){
    delay(300);
    conditional=1-conditional;
    if(conditional==0){
      m='3';
    }
  }
  conditional=0;
  if(digitalRead (btn4)==HIGH){
    conditional=1;
  }
  if(digitalRead (btn4==LOW && conditional==1)){
    delay(300);
    conditional=1-conditional;
    if(conditional==0){
      m='4';
    }
  }
  conditional=0;
  Serial.println("El led a encender: ");
  Serial.println(m);
  
  Wire.beginTransmission(7);
  Wire.write(m);
  Wire.endTransmission();
}
