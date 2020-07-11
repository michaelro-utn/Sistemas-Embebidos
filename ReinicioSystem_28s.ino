#include <LiquidCrystal.h>
LiquidCrystal lcd (13,12,11,10,9,8);
#include <TimerOne.h>

#include<avr/wdt.h>

const int led1=7;

int i;
int segundos=0;
int periodo=28000;
unsigned long Tiempo=0;
int cont=0;

void setup() {
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("System-");
  pinMode(led1,OUTPUT);
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(seconds);
  Serial.begin(9600);
  }

void loop() {
  Serial.println(i++);
  delay(300);    
  if(millis()>Tiempo + periodo){
    Tiempo= millis();
    digitalWrite(led1,HIGH);
    cont++;
    lcd.setCursor(9,0);
    lcd.print(String("Reset"));
    wdt_disable();
    wdt_enable(WDTO_120MS);
    delay(800);
    digitalWrite (led1,LOW);
  }
}

void seconds(){
  lcd.setCursor(0,1);
  lcd.print("Second:");
  segundos++;
  if(segundos>99){
    segundos=0;
  }
  if(segundos<10){
    lcd.setCursor(10,1);
    lcd.print(String("0")+String(segundos));
  }else{
    lcd.setCursor(10,1);
    lcd.print(segundos);
  }
}
