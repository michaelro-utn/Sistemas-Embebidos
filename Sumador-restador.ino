#include <LiquidCrystal.h>
LiquidCrystal lcd (13, 12, 11, 10, 9, 8);

int num1, num2, suma, resta;
int contador = 0;
int contador2 = 0;
int mode=0;
int on=0;
String dato1, dato2;
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  attachInterrupt(digitalPinToInterrupt(2),activacion,LOW);
  attachInterrupt(digitalPinToInterrupt(3),modo,LOW);
  Serial.println("Ingrese el primer #");
}

void loop() {
    lcd.setCursor(0,0);
      if (contador == 0) {
        if (Serial.available() > 0) {
         dato1 = Serial.readString();
         num1 = dato1.toInt();
         Serial.println("");
         Serial.println(String("numero ingresado:")+String(num1));
         contador++;
         Serial.println("Ingrese el segundo #");
        }  
    }
    if (contador == 1) {
        if (Serial.available() > 0) {
         dato2 = Serial.readString();
         num2 = dato2.toInt();
         Serial.println("");
         Serial.println(String ("Numero ingresado: ")+String(num2));
         contador++;
        }  
    }
    if (contador == 2) {
       contador=0;
    }
    if(mode==0 && on==1){
       lcd.setCursor(0,1);
       lcd.print(String("Suma:")+String(suma));
    }
    if(mode==1 && on==1){
      lcd.setCursor(7,1);
      lcd.print(String("resta:")+String(resta));
    }
}

void modo(){
  switch(mode){
    case 0:
      suma = num1 + num2;
      Serial.println("suma: " + String(suma));
      mode++;
    break;
    case 1:
      resta=num1 - num2;
      Serial.println(String("resta: ")+String(resta));
      mode++;
    break;
    case 2:
      mode=0;
    break;
  }
}

void activacion (){
  switch (on){
    case 0:
      lcd.setCursor(0,0);
      lcd.print("System: ON ");
      on++;
    break;
    case 1:
      lcd.setCursor(0,0);
      lcd.print("System: OFF     ");
      on++;
    break;
    case 2:
      on=0;
    break;
  }
}
