#include <LiquidCrystal.h >
LiquidCrystal lcd (13,12,11,10,9,8); 

const char vector [7]={'A','R','D','U','I','N','O'};
int i;
int cont=0;
const int btn=7;
int j; 
const String plb="ARDUINO"; // Palabra a mostrar
const String plb1="-------";
int longitu_p=plb.length(); // Longitud de la Palabra
int longitu_p1=plb1.length(); 
int estado=0;

void setup() {
  // put your setup code here, to run once:
  pinMode (btn, INPUT);
  lcd.begin (16,2);
  lcd.setCursor(0,0);
  lcd.print (plb);
  lcd.setCursor(0,1);
  lcd.print (plb1);
}

void loop() {
  
  lcd.setCursor (0,0);
  if (digitalRead (btn)==LOW){
    estado=1;
  }  
  if(digitalRead (btn)==HIGH && estado ==1){
  for (i=0;i<(16+longitu_p);i++){
    lcd.scrollDisplayRight();
    delay (200);
   }
  }
}
