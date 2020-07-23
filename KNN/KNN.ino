#include "datos.h" //archivo local 
#include "QuickSortLib.h"
float test[5]={6.5,3.2,5.1,2,3}; //datos provenientes de sensores
int fil=0;
int i=0;
int col=0;
int k=0;
float data_o;
float distancia=0;
float matrizdata[90];
float distancia_menor=20000;
float etiqueta;
float values90Length;
String dato;
int vecino;

void setup() {
  Serial.begin(9600);
  for(;fil<90;fil++){
    for(col=0;col<4;col++){
      //Distancia
      distancia=distancia+pow(matriz[fil][col]-test[col],2);   
    }
    distancia=sqrt(distancia);
    matrizdata[fil]=distancia;
//  size_t values90Length=sizeof(matrizdata)/sizeof(matrizdata[0]);
    Serial.println(matrizdata[fil]);
    if(distancia<distancia_menor){
      distancia_menor=distancia;
      etiqueta=matriz[fil][4];
    }
  }
  ordenamiento(matrizdata, 90);
  Serial.println("Distancias Ordenadas");
  for(int h=0;h<90;h++){
    Serial.println(matrizdata[h]);
  }
  Serial.println("Ingrese el valor de vecinos 3 o 5");
}


void loop() {
  if(Serial.available()>0){
    Serial.println("");
    dato=Serial.readString();
    vecino=dato.toInt();
    if(vecino==3 || vecino==5){
      float kveci[vecino];
    Serial.println(String("Vecinos Seleccionados: ")+String(vecino));
      for(int h=0;h<vecino;h++){
        kveci[h]=matrizdata[h];
        Serial.println(kveci[h]);
      }
    Serial.println(String("Datos son de etiqueta: ")+String(etiqueta));
    if(etiqueta==test[4]){
      Serial.println("Acierto");
    }else{
      Serial.println("Error");
      }
    }else{
      Serial.println("# Vecino Incorrecto");
      Serial.println("Ingrese k vecinos: ");
      dato=Serial.readString();
      vecino=dato.toInt();
    }
  }
}

void ordenamiento(float *dat, int longitud){
 for (int i = 1; i < longitud; ++i){
   data_o= dat[i];
   k;
   for (k = i-1; (k>=0) && (data_o < dat[k]); k--){
     dat[k + 1] = dat[k];
   }
   dat[k + 1] = data_o;
 }
}
