#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
#include <avr/sleep.h>
#include <avr/wdt.h>
#include <TimerOne.h>
#include<MsTimer2.h>
#include <EEPROM.h>

//variables clave
String dato;
int clave;

//variables reloj 
int minutos=0;
int hora=0;
int peri=5500;
unsigned long ttiempo=0;
//variables hardware
int led1=2;
int led2=3;
int led3=4;
int numAleatorio;
int contled=0;
int periodo=2000;
int btn=5;
int btn1=6;
int btn2=7;
int cont=0;
unsigned long tiempo=0;
void setup() {
  minutos=EEPROM.read(0);
  hora=EEPROM.read(2);
  MsTimer2::set(2000,activacion);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("System:Ener.S.");
  Timer1.initialize(100000);
  Timer1.attachInterrupt(reloj);
  Serial.begin(9600);
  Serial.println("Sistema Seguridad HOMETIC");
  Serial.println("Ingrese Clave Activacion ");
  set_sleep_mode(SLEEP_MODE_STANDBY);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(btn,INPUT);
  pinMode(btn1,INPUT);
  pinMode(btn2,INPUT);
}
void loop() {
  cont=EEPROM.read(29);
  if(Serial.available()>0){
    dato=Serial.readString();
    clave=dato.toInt();
    if(clave==2112){
     sleep_disable();
     MsTimer2::start();
     tiempo=millis();
     while(millis()<tiempo+periodo){
     }
     for(contled=0;contled<1000;contled++){
     numAleatorio=random(2,5);
     digitalWrite(numAleatorio,HIGH);
     delay(300);
     digitalWrite(numAleatorio,LOW);
     delay(300);
     }
    }else{
      sleep_mode();
      lcd.setCursor(8,0);
      lcd.print("EnergyS.");
      MsTimer2::stop();
      sleep_disable();
      wdt_disable();
      wdt_enable(WDTO_2S);
    }
  }
}
void reloj(){
  minutos++;
  if(minutos<60){
    if(minutos<10){
      lcd.setCursor(3,1);
      lcd.print(String("0")+String(minutos));
    }else{
      lcd.setCursor(3,1);
      lcd.print(minutos);
    }
  }
  if(minutos==60){
      hora++;
      minutos=0;
      lcd.setCursor(3,1);
      lcd.print("00");  
  }
  if(hora<10){
      lcd.setCursor(0,1);
      lcd.print(String("0")+String(hora)+String(":"));
  }else{
    lcd.setCursor(0,1);
    lcd.print(String(hora)+String(":"));
  }
  if(hora==24){
    hora=0;
  }
  if(millis()>ttiempo+peri){
    ttiempo=millis();
    Serial.println("");
    Serial.println("Resplado");
    Serial.println(String(hora)+String(":")+String(minutos));
    lcd.setCursor(7,1);
    lcd.println(String("R-")+String(hora)+String(":")+String(minutos));
    int minu=minutos/4;
    int ho=hora/4;
    EEPROM.write(0,minutos);
    EEPROM.write(2,hora);
  }
}
void activacion(){
   lcd.setCursor(7,0);
   lcd.print("Active ");
      if(digitalRead(btn)==LOW){
        cont=1;
        delay(400);
        Serial.println("");
        Serial.println("Sensor1");
        Serial.print(cont);
        lcd.setCursor(15,0);
        lcd.print(cont);
        delay(400);
        int con=cont/4;
        EEPROM.write(29,cont);
      }
      if(digitalRead(btn1)==LOW){
        cont=2;
        delay(400);
        Serial.println("");
        Serial.println("Sensor2");
        Serial.print(cont);
        lcd.setCursor(15,0);
        lcd.print(cont);
        delay(400);
    int con=cont/4;
    EEPROM.write(29,cont);
      }
      if(digitalRead(btn2)==LOW){
        cont=3;
        delay(400);
        Serial.println("");
        Serial.println("Sensor3");
        Serial.print(cont);
        lcd.setCursor(15,0);
        lcd.print(cont);
        delay(400);
    int con=cont/4;
    EEPROM.write(29,cont);
      }
}
