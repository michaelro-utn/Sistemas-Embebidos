
const int a=8;
const int b=9;
const int c=10; 
const int d=11; 
int entrada=7;
int entrada1=6;
int cont=0;
int estado=0;
const int decenas=13;
const int unidades=12;
int dec;
int uni;
const int led1=5;
const int led2=4;

void setup() {
  pinMode (entrada,INPUT);
  pinMode (entrada1,INPUT);
  pinMode (a,OUTPUT);
  pinMode (b,OUTPUT);
  pinMode (c,OUTPUT);
  pinMode (d,OUTPUT);
  pinMode (decenas,OUTPUT);
  pinMode (unidades,OUTPUT);
  pinMode (led1,OUTPUT);
  pinMode (led2,OUTPUT);
}

void loop() {
  if(estado=digitalRead(entrada)){
  if (estado==LOW){
    cont++;
    while (estado==LOW){ //Antirebote
      estado=digitalRead(entrada);
    } 
  }
    delay(300);
    if(cont<30)
        cont++;
      else
        cont=cont; 
        dec=cont/10;      // 15/10=1.5->1    5/10=0.5->0
        uni= cont-(dec*10);  // 15-10=5     5-0=5
  
  digitalWrite (decenas,HIGH);
  digitalWrite (unidades, LOW);
  /*
   * Imprimir valor decenas 
   */
   segmentos(dec); 
   delay (200);
   digitalWrite (decenas,LOW);
   digitalWrite (unidades, HIGH);
   /*
    * Imprimir valor de unidades 
    */
    segmentos(uni);
    delay(200);
  }else{
  if(estado=digitalRead(entrada1)){
  if (estado==LOW){
    cont=cont-1;
    while (estado==LOW){ //Antirebote
      estado=digitalRead(entrada1);
    } 
  }
    delay(300);
    if(cont<30)
        cont=cont-1;
      else
        cont=cont; 
        dec=cont/10;      // 15/10=1.5->1    5/10=0.5->0
        uni= cont-(dec*10);  // 15-10=5     5-0=5
  
  digitalWrite (decenas,HIGH);
  digitalWrite (unidades, LOW);
  /*
   * Imprimir valor decenas 
   */
   segmentos(dec); 
   delay (200);
   digitalWrite (decenas,LOW);
   digitalWrite (unidades, HIGH);
   /*
    * Imprimir valor de unidades 
    */
    segmentos(uni);
    delay(200);
  }
}
if (cont==30){
  digitalWrite (led2,LOW);
  digitalWrite (led1, HIGH);
}else{
  digitalWrite (led2,HIGH);
  digitalWrite (led1, LOW);
}
if (cont==30){
      if(cont==30)
        cont=cont;
      else
        cont=0; 
        dec=cont/10;      // 15/10=1.5->1    5/10=0.5->0
        uni= cont-(dec*10);  // 15-10=5     5-0=5
  
  digitalWrite (decenas,HIGH);
  digitalWrite (unidades, LOW);
  /*
   * Imprimir valor decenas 
   */
   segmentos(dec); 
   delay (200);
   digitalWrite (decenas,LOW);
   digitalWrite (unidades, HIGH);
   /*
    * Imprimir valor de unidades 
    */
    segmentos(uni);
    delay(200);
}
}
void segmentos (int i){
  switch(i){
        case 0: 
          digitalWrite (d,LOW);
          digitalWrite (c,LOW);
          digitalWrite (b,LOW);
          digitalWrite (a,LOW);
        break;
        case 1:  
          digitalWrite (d,HIGH);
          digitalWrite (c,LOW);
          digitalWrite (b,LOW);
          digitalWrite (a,LOW);
        break;
        case 2:  
          digitalWrite (d,LOW);
          digitalWrite (c,HIGH);
          digitalWrite (b,LOW);
          digitalWrite (a,LOW);
        break;
        case 3:  
          digitalWrite (d,HIGH);
          digitalWrite (c,HIGH);
          digitalWrite (b,LOW);
          digitalWrite (a,LOW);
        break;
        case 4:  
          digitalWrite (d,LOW);
          digitalWrite (c,LOW);
          digitalWrite (b,HIGH);
          digitalWrite (a,LOW);
        break;
        case 5:  
          digitalWrite (d,HIGH);
          digitalWrite (c,LOW);
          digitalWrite (b,HIGH);
          digitalWrite (a,LOW);
        break;
        case 6:  
          digitalWrite (d,LOW);
          digitalWrite (c,HIGH);
          digitalWrite (b,HIGH);
          digitalWrite (a,LOW);
        break;
        case 7:  
          digitalWrite (d,HIGH);
          digitalWrite (c,HIGH);
          digitalWrite (b,HIGH);
          digitalWrite (a,LOW);
        break;
        case 8:  
          digitalWrite (d,LOW);
          digitalWrite (c,LOW);
          digitalWrite (b,LOW);
          digitalWrite (a,HIGH);
        break;
        case 9:  
          digitalWrite (d,HIGH);
          digitalWrite (c,LOW);
          digitalWrite (b,LOW);
          digitalWrite (a,HIGH);
        break;
  }
}
