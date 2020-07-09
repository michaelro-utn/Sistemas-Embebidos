#include <TimerOne.h>
#include <MsTimer2.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd (13,12,11,10,9,8);
const int led1=7;
const int btn1=5;
const int btn2=4;
const int buzzer=3;
int tono=0;

//variables de reloj
int segundos=0;
int minutos=0;
int minutos1=0;
int segundos1=0;

//variables conteo
int i,j,valor,frecuencia,duracion;
String dato,dato1;

void setup() {
  pinMode (led1,OUTPUT);
  pinMode (btn1,INPUT);
  pinMode (btn2,INPUT);
  pinMode (buzzer,OUTPUT);
  lcd.begin(16,2);
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(seconds);
  MsTimer2::set(59000,minutes);
  MsTimer2::start();
}

void loop() {
  if(digitalRead (btn1)==HIGH){
    lcd.setCursor(0,0);
    lcd.print("Alarma-");
    delay (400);
    minutos1=minutos1+1;
    if(minutos1>23){
      minutos1=0;
    }
    if(minutos1<10){
      lcd.setCursor(8,0);
      lcd.print(String("0")+String(minutos1)+String(":"));
    }else{
      lcd.setCursor(8,0);
      lcd.print(String(minutos1)+String(":"));
    }
  }
  if(digitalRead (btn2)==HIGH){
    delay(400);
    segundos1=segundos1+1;
    if(segundos1>59){
      segundos1=0;
    }
    if(segundos1<10){
      lcd.setCursor(11,0);
      lcd.print(String("0")+String(segundos1));
    }else{
    lcd.setCursor(11,0);
    lcd.print(segundos1);
    }
  }
  valor=analogRead(0);
  frecuencia=map (valor,0,1024,100,5000);
  duracion=1000;
  if(minutos1==minutos && segundos1==segundos){
    digitalWrite(led1,HIGH);
    delay(1000);
    digitalWrite(led1,LOW);
  tone(buzzer,frecuencia,duracion);
  delay(100);
  }
}

void seconds (){
  lcd.setCursor (0,1);
  lcd.print("TIME->");
  segundos++;
  if(segundos>59){
    segundos=0;
  }
  if(segundos<10){
    lcd.setCursor(11,1);
    lcd.print(String("0")+String(segundos));
  }else{
    lcd.setCursor(11,1);
    lcd.print(segundos);
  }
  if(minutos==0){
    lcd.setCursor(8,1);
    lcd.print("00:");
  }
}

void minutes (){
  minutos++;
  if(minutos>23){
    minutos=0;
  }
  if(minutos<10){
    lcd.setCursor(8,1);
    lcd.print(String("0")+String(minutos));
  }else{
    lcd.setCursor(8,1);
    lcd.print(minutos);
  }
}
