
#include <LiquidCrystal.h>
LiquidCrystal lcd (13,12,11,10,9,8);
int conversor,velocidad,dutty; 
float voltaje,vol;
const int motor=6;
String dato;

  
void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);
  Serial.println("Ingrese valor numerico de velocidad de motor");
}

void loop() {
  conversor=analogRead(0);
  if(Serial.available()>0){
    dato=Serial.readString();
    velocidad=dato.toInt();
    if(velocidad <300){
      conversor=map(conversor,0,1023,0,velocidad);
      analogWrite (motor,velocidad);
      lcd.setCursor(0,0);
      lcd.print("Velocidad:");
      lcd.setCursor(12,0);
      lcd.print(velocidad);
      delay(5000);
      lcd.clear();
    }else{
      Serial.println ("Error:Dato incorrecto");
      lcd.setCursor(5,0);
      lcd.print("ERROR");
      delay(5000);
      lcd.clear(); 
    }
  }
  vol=(conversor*5.0)/1023.0;
  dutty=conversor/4;
  analogWrite(motor,dutty);
  lcd.setCursor(0,0);
  lcd.print("Velocidad:");
  lcd.setCursor(12,0);
  lcd.print(dutty);
  delay(5000);
  lcd.clear();
}
