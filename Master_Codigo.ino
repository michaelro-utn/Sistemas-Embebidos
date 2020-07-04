#include <Wire.h>
String sms;
char dato;
String salida;

int tam;
int i;

void setup() {
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0){
    sms=Serial.readString(); //Leer el terminal 
    Serial.println("");
    sms.toLowerCase(); //Trasnformar el string en minusculas
    tam=sms.length()+1;
    char vector[tam];
    sms.toCharArray(vector,tam);
    Serial.println("Mensaje validado con Exito"); //codificacion palabra por palabra
    for (i=0;i<tam-1;i++){
       switch (vector[i]){
           case 'a':
            salida=salida+"0";
           break;
           case 'b':
            salida=salida+"1";
           break;
           case 'c':
            salida=salida+"2";
           break;
           case 'd':
            salida=salida+"3";
           break;
           case 'e':
            salida=salida+"4";
           break;
           case 'f':
            salida=salida+"5";
           break;
           case 'g':
            salida=salida+"6";
           break;
           case 'h':
            salida=salida+"7";
           break;
           case 'i':
            salida=salida+"8";
           break;
           case 'j':
            salida=salida+"9";
           break;
           case 'k':
            salida=salida+"!";
           break;
           case 'l':
            salida=salida+"@";
           break;
           case 'm':
            salida=salida+"]";
           break;
           case 'n':
            salida=salida+"-";
           break;
           case 'o':
            salida=salida+"#";
           break;
           case 'p':
            salida=salida+"&";
           break;
           case 'q':
            salida=salida+"/";
           break;
           case 'r':
            salida=salida+"(";
           break;
           case 's':
            salida=salida+")";
           break;
           case 't':
            salida=salida+"=";
           break;
           case 'u':
            salida=salida+"?";
           break;
           case 'v':
            salida=salida+"{";
           break;
           case 'w':
            salida=salida+"*";
           break;
           case 'x':
            salida=salida+"^";
           break;
           case 'y':
            salida=salida+"ç";
           break;
           case 'z':
            salida=salida+"}";
           break;
           case ' ':
            salida=salida+"[";
           break;
          }
    }
    Serial.println("Mensaje codificado: ");
    Serial.println(salida);   //Impresion codificación 
  }
  Wire.beginTransmission(6); //inicio Transmición y puerto de comunicación 
  Wire.write(salida.c_str()); //convertir String to char para envío de datos
  Wire.endTransmission(); //Fin transmición 
  salida="";
}
