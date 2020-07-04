#include <Wire.h>
# include <LiquidCrystal.h>
LiquidCrystal lcd = {13, 12, 11, 10, 9, 8};

const int led1=7; 


char dato;
String deco="";
String salida;
int tam,i;

void setup() {
  lcd.begin(16,2);
  Wire.begin(6); //comienzo de la transmición a través del mismo puerto de comunicación 
  Wire.onReceive(eventReceive);
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
}

void loop() {
}

void eventReceive (int bytes){
  deco=""; 
  while (Wire.available()){ //leer datos que llegan desde el arduino Master
    dato=Wire.read();
    deco.concat(dato); //concatenar todos los caracteres que entran desde el virtual terminal para formar un String
    Serial.println("Mensaje Codificado");
    Serial.println(deco);
    delay(500);
      if(Wire.available()){
        digitalWrite(led1,HIGH);
        }
      }
        tam=deco.length()+1; //Empieza decodificación palabra por palabra
        char vector[tam];
        deco.toCharArray(vector,tam); 
        delay(1000);
        for (i=0;i<tam-1;i++){
          switch(vector[i]){
                 case '0':
                  salida=salida+"a";
                 break;
                 case '1':
                  salida=salida+"b";
                 break;
                 case '2':
                  salida=salida+"c";
                 break;
                 case '3':
                  salida=salida+"d";
                 break;
                 case '4':
                  salida=salida+"e";
                 break;
                 case '5':
                  salida=salida+"f";
                 break;
                 case '6':
                  salida=salida+"g";
                 break;
                 case '7':
                  salida=salida+"h";
                 break;
                 case '8':
                  salida=salida+"i";
                 break;
                 case '9':
                  salida=salida+"j";
                 break;
                 case '!':
                  salida=salida+"k";
                 break;
                 case '@':
                  salida=salida+"l";
                 break;
                 case ']':
                  salida=salida+"m";
                 break;
                 case '-':
                  salida=salida+"n";
                 break;
                 case '#':
                  salida=salida+"o";
                 break;
                 case '&':
                  salida=salida+"p";
                 break;
                 case '/':
                  salida=salida+"q";
                 break;
                 case '(':
                  salida=salida+"r";
                 break;
                 case ')':
                  salida=salida+"s";
                 break;
                 case '=':
                  salida=salida+"t";
                 break;
                 case '?':
                  salida=salida+"u";
                 break;
                 case '{':
                  salida=salida+"v";
                 break;
                 case '*':
                  salida=salida+"w";
                 break;
                 case '^':
                  salida=salida+"x";
                 break;
                 case 'ç':
                  salida=salida+"y";
                 break;
                 case '}':
                  salida=salida+"z";
                 break;
                 case '[':
                  salida=salida+" ";
                 break;      
            }
        Serial.println("Mensaje decodificado");
        Serial.println(salida);
      }
    lcd.setCursor(0,0);   //Imprimir en pntalla lcd
    lcd.print(String("Codigo: ")+String (deco));
    lcd.setCursor(0,1);
    lcd.print(String("SMS:")+String (salida));
}
