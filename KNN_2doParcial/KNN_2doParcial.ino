#include "data.h"
int fil=0;
int col=0;
float matriz[48][4];
int cont=0;
float ren=0;
float test[8][4]={
{0,13176,19264,1},
{3004,11564,20848,1},
{7824,27828,6104,2},
{7824,29096,6104,2},
{6272,2260,10464,3},
{7964,0,11140,3},
{16368,10128,0,4},
{16368,8780,964,4},
};
float testArray[4];
//Variables para KNN
float distancia=0;
float distancia_menor=20000;
float etiqueta;
//variable suma-promedio etiqueta 1
float suma1=0,sumb1=0,sumc1=0,valor1=0;
float proma1=0,promb1=0,promc1=0;
float dista1[40],dista1_1[40],dato1[11][4];
//variable suma-promedio etiqueta 2
float suma2=0,sumb2=0,sumc2=0;
float proma2=0,promb2=0,promc2=0;
float dista2[39],dista2_1[39],dato2[3][4];
//variable suma-promedio etiqueta 3
float suma3=0,sumb3=0,sumc3=0;
float proma3=0,promb3=0,promc3=0;
float dista3[39],dista3_1[39],dato3[15][4];
//variable suma-promedio etiqueta 4
float suma4=0,sumb4=0,sumc4=0;
float proma4=0,promb4=0,promc4=0;
float dista4[39],dista4_1[39],dato4[18][4];
void setup() {
  Serial.begin(9600);
  Serial.println("##################################################");
  Serial.println("BASE DE DATOS CON RANGO DE DITANCIA ENTRE 0.4-0,65");
  Serial.println("##################################################");
  Serial.println("");
  //Ciclo Suma 1
  for(fil=0;fil<40;fil++){
    suma1=suma1 + data[fil][0];
    sumb1=sumb1 + data[fil][1];
    sumc1=sumc1 + data[fil][2];
    //Promedio 1
    proma1=suma1 / 40;
    promb1=sumb1 / 40;
    promc1=sumc1 / 40;
  }
  //Ciclo suma 2
  for(fil=40;fil<79;fil++){
    suma2=suma2 + data[fil][0];
    sumb2=sumb2 + data[fil][1];
    sumc2=sumc2 + data[fil][2]; 
    //Promedio 2
    proma2=suma2 / 39;
    promb2=sumb2 / 39;
    promc2=sumc2 / 39;   
  }
  //Ciclo suma 3
  for (fil=79;fil<118;fil++){
    suma3=suma3 + data[fil][0];
    sumb3=sumb3 + data[fil][1];
    sumc3=sumc3 + data[fil][2]; 
    //Promedio 3 
    proma3=suma3 / 39;
    promb3=sumb3 / 39;
    promc3=sumc3 / 39; 
  }
  //Ciclo suma 4
  for (fil=118;fil<157;fil++){
    suma4=suma4 + data[fil][0];
    sumb4=sumb4 + data[fil][1];
    sumc4=sumc4 + data[fil][2]; 
    //Promedio 4 
    proma4=suma4 / 39;
    promb4=sumb4 / 39;
    promc4=sumc4 / 39;     
  }
  //Distancia Etiqueta 1
  for (fil=0;fil<40;fil++){
    dista1[fil]=sqrt(pow(data[fil][0]-proma1,2)+pow(data[fil][1]-promb1,2)+pow(data[fil][2]-promc1,2));
  }
  //Distancia maxima 1
  float dist_max1=dista1[0];
  for (int i=0;i<40;i++){
    if(dista1[i]>dist_max1){
      dist_max1=dista1[i];
    }
  }
  //Escala 0:1 ->1
  for(fil=0;fil<40;fil++){
    dista1_1[fil]=dista1[fil]/dist_max1;
    //Serial.println(dista1_1[fil]); ->Imprimir datos escala 0-1
    if(dista1_1[fil]>0.4 && dista1_1[fil]<0.65){
      for(col=0;col<4;col++){
        dato1[fil][col]=data[fil][col];
        matriz[fil][col]=dato1[fil][col];
        Serial.println(matriz[fil][col]);
      //Serial.println(dato1[fil][col]);
      }   
    } 
  }
  //Distancia Etiqueta 2 
  for (fil=40;fil<79;fil++){
    dista2[fil]=sqrt(pow(data[fil][0]-proma2,2)+pow(data[fil][1]-promb2,2)+pow(data[fil][2]-promc2,2));
  }
  //Distancia maxima 2
  float dist_max2=dista2[0];
  for (int i=40;i<79;i++){
    if(dista2[i]>dist_max2){
      dist_max2=dista2[i];
    }
  }
  //Escala 0:1 ->2
  for(fil=40;fil<79;fil++){
    dista2_1[fil]=dista2[fil]/dist_max2;
    //Serial.println(dista2_1[fil]); //->Imprimir datos escala 0-1
    if(dista2_1[fil]>0.4 && dista2_1[fil]<0.65){
      for(col=0;col<4;col++){
        dato2[fil][col]=data[fil][col];
        matriz[fil][col]=dato2[fil][col];
//        Serial.println(dato2[fil][col]);
      Serial.println(matriz[fil][col]);
      }   
    } 
  }
  //Distancia Etiqueta 3
  for (fil=79;fil<118;fil++){
    dista3[fil]=sqrt(pow(data[fil][0]-proma3,2)+pow(data[fil][1]-promb3,2)+pow(data[fil][2]-promc3,2));
  }
  //Distancia Maxima 3
  float dist_max3=dista3[0];
  for (int i=79;i<118;i++){
    if(dista3[i]>dist_max3){
      dist_max3=dista3[i];
    }
  }
  //Escala 0:1 ->3
  for(fil=79;fil<118;fil++){
    dista3_1[fil]=dista3[fil]/dist_max3;
    //Serial.println(dista3_1[fil]); //->Imprimir datos escala 0-1
    if(dista3_1[fil]>0.4 && dista3_1[fil]<0.65){
      for(col=0;col<4;col++){
        dato3[fil][col]=data[fil][col];
        matriz[fil][col]=dato3[fil][col];
        Serial.println(matriz[fil][col]);
      }   
    }
  }
  //Distancia 4 
  for (fil=118;fil<157;fil++){
    dista4[fil]=sqrt(pow(data[fil][0]-proma4,2)+pow(data[fil][1]-promb4,2)+pow(data[fil][2]-promc4,2));   
  }
  //Distancia Maxima 4
  float dist_max4=dista4[0];
  for (int i=118;i<157;i++){
    if(dista4[i]>dist_max4){
      dist_max4=dista4[i];
    }
  }
  //Escala 0:1 ->4
  for(fil=118;fil<157;fil++){
    dista4_1[fil]=dista4[fil]/dist_max4;
    //Serial.println(dista4_1[fil]); //->Imprimir datos escala 0-1
    if(dista4_1[fil]>0.4 && dista4_1[fil]<0.65){
      for(col=0;col<4;col++){
        dato4[fil][col]=data[fil][col];
        matriz[fil][col]=dato4[fil][col];
        Serial.println(matriz[fil][col]);
      }   
    }
  }
  Serial.println("");
  Serial.println("######################");
  Serial.println("PROMEDIOS POR ETIQUETA");
  Serial.println("######################");
  Serial.println("");
  Serial.println("######ETIQUETA-1######");
  Serial.println("Columna 1") ;
  Serial.println(proma1);
  Serial.println("Columna 2") ;
  Serial.println(promb1);
  Serial.println("Columna 3") ;
  Serial.println(promc1);
  Serial.println("######ETIQUETA-2######");
  Serial.println("Columna 1") ;
  Serial.println(proma2);
  Serial.println("Columna 2") ;
  Serial.println(promb2);
  Serial.println("Columna 3") ;
  Serial.println(promc2);
  Serial.println("######ETIQUETA-3######");
  Serial.println("Columna 1") ;
  Serial.println(proma3);
  Serial.println("Columna 2") ;
  Serial.println(promb3);
  Serial.println("Columna 3") ;
  Serial.println(promc3);
  Serial.println("######ETIQUETA-4######");
  Serial.println("Columna 1") ;
  Serial.println(proma4);
  Serial.println("Columna 2") ;
  Serial.println(promb4);
  Serial.println("Columna 3") ;
  Serial.println(promc4);
  Serial.println("");
  Serial.println("############################");
  Serial.println("DISTANCIA MAYOR POR ETIQUETA");
  Serial.println("############################");
  Serial.println(""); 
  Serial.println("######ETIQUETA-1######");
  Serial.println(String("Distancia Max: ")+String(dist_max1));
  Serial.println("######ETIQUETA-2######");
  Serial.println(String("Distancia Max: ")+String(dist_max2));
  Serial.println("######ETIQUETA-3######");
  Serial.println(String("Distancia Max: ")+String(dist_max3));
  Serial.println("######ETIQUETA-4######");
  Serial.println(String("Distancia Max: ")+String(dist_max4));
  Serial.println("");
//  for(fil=0;fil<49;fil++){
//    for(col=0;col<3;col++){
//      //distancia 
//      distancia=distancia+pow(matriz[fil][col]-test[fil][col],2);
//    }
//    distancia=sqrt(distancia);
//    Serial.println(String ("Distancia")+String(distancia));
//  }
  int i, j;
  int contador=0;
  for(i=0;i<8;i++){
    for(j=0;j<4;j++){
      testArray[contador]=test[i][j];
      contador++;
    }
  }
  Serial.println("################################");
  Serial.println("DISTANCIA A LOS VECINOS CERCANOS");
  Serial.println("################################");
  Serial.println("");
  for (fil=0;fil<48;fil++){
    for(col=0;col<3;col++){
      distancia=distancia+pow(matriz[fil][col]-testArray[col],2);
    }
    distancia=sqrt(distancia);
    Serial.println(String("Distancia que tienen los Datos de Prueba: ")+String(distancia));
    if(distancia<distancia_menor){
      distancia_menor=distancia;
      etiqueta=matriz[fil][3];
  }
  }
  Serial.println("");
  Serial.println("######################");
  Serial.println("CLASIFICACION DEL DATO");
  Serial.println("######################");
  Serial.println("");
  Serial.println(String("Datos son de Etiqueta: ")+String(etiqueta));
  if(etiqueta==testArray[3]){
    Serial.println("Acierto");
  }else{
    Serial.println("Error");
  }
  for(int i=0;i<contador;i++){
    if(testArray[3]==etiqueta){
      ren++;
    }
  }
  ren=(ren / contador)*100;
  Serial.println("");
  Serial.println("#######################");
  Serial.println("RENDIMIENTO DEL SISTEMA");
  Serial.println("#######################");
  Serial.println(String(ren)+String("%"));
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
