#include <TimerOne.h>
#include <MsTimer2.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);

const int led[4]={7,6,5,4};
//Interrupciones
int on=0;
int modo=0;
//Variables
int segundos=0; //Minutos
int minutos=0; //Horas 
int j,i,sec,minu;
//Conversor análogo
int conversor,conversor1;
int vol,dutty;
void setup() {
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("System: ");
  for (i=0;i<4;i++){
    pinMode(led[i],OUTPUT);
  }
  attachInterrupt(digitalPinToInterrupt(2),activation,LOW);
  attachInterrupt(digitalPinToInterrupt(3),state,LOW);
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(seconds);
  MsTimer2::set(60000,minutes);
  MsTimer2::start();
}

void loop() {
  if(modo==0 && on==1){
          for(j=0;j<5;j++){
//        lcd.setCursor(0,1);
//        lcd.print("                ");
        digitalWrite(led[j],HIGH);
        delay(200);
        digitalWrite(led[j],LOW);
        delay(200);
      }
  }
  if(modo==1){
      conversor=analogRead(0);
      segundos=(conversor*4)/68;
      lcd.setCursor(10,1);
      lcd.print(segundos);
  }
  if(modo==1 && on==1){
      conversor1=analogRead(1);
      minutos=(conversor1*4)/68;
      lcd.setCursor(7,1);
      lcd.print(minutos);
  }
}

void activation(){
  switch(on){
    case 0:
      lcd.setCursor(9,0);
      lcd.print("ON ");
      on++;
    break;
    case 1:
      lcd.setCursor(9,0);
      lcd.print("OFF");
      on=0;
    break;
  }
}
void state(){
  switch(modo){
    case 0:
      modo++;
    break;
    case 1:
        modo=1-modo;
    break;
  }
}
void seconds(){
  lcd.setCursor(0,1);
  lcd.print("TIME->");
  lcd.setCursor(12,1);
  lcd.print(" ECU");
  segundos++;
  if(segundos>60){
    segundos=0;
  }
  if(segundos<10){
    lcd.setCursor(10,1);
    lcd.print(String("0")+String(segundos));
  }else{
    lcd.setCursor(10,1);
    lcd.print(segundos);
  }
  if(minutos==0){
     lcd.setCursor(7,1);
     lcd.print("00:");
  }
}
void minutes(){
  minutos++;
  if(minutos>60){
    minutos=0;
  }
  if(minutos<10){
    lcd.setCursor(7,1);
    lcd.print(String("0")+String(minutos)+String(":"));
  }else{
    lcd.setCursor(7,1);
    lcd.print(String(minutos)+String(":"));
  }
}
