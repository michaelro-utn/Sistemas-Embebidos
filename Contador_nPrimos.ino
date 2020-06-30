const int d=11;
const int c=10;
const int b=9;
const int a=8; 
const int btn=7; 
const int decenas=13;
const int unidades=12;
int dec;
int uni; 
int cont; 
int i;
int presionado = 0;

void setup() {
  pinMode (d,OUTPUT);
  pinMode (c,OUTPUT);
  pinMode (b,OUTPUT);
  pinMode (a,OUTPUT);
  pinMode (decenas,OUTPUT);
  pinMode (unidades,OUTPUT);
  pinMode (btn,INPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead (btn)==LOW){
    presionado=1;
  }
  if (digitalRead (btn)==HIGH && presionado==1){
    delay(300);
    for (cont=1;cont<100;cont++){
      bool primo=true;
        for (i=2;i<cont;i++){
          if (cont%i==0)
          primo=false;
        }
        if(primo){
          presionado=0;
          dec=cont/10;//15/10=1.5->1    5/10=0.5->0
          uni= cont-(dec*10); // 15-10=5     5-0=5
  }
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
  presionado=0;
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
