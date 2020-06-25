
/*
 * Universidad Técnica del Norte 
 * Sistemas Embebidos 
 * Juego de Luces   
 * Rodriguez Pozo Anthony Michael 
 */
const int vector[6]={8,9,10,11,12,13};
const int btn=7;
int i=0;
int j;
int p;
const int led1=8;
const int led2=9;
const int led3=10;
const int led4=11;
const int led5=12;
const int led6=13;
const int btn1=6; 
int k; 
int l; 
int state=0; 
void setup() {
  // put your setup code here, to run once:
  for (i=0;i<6;i++){
    pinMode (vector[i],OUTPUT);
  }
  pinMode (btn, INPUT);
  pinMode (led1,OUTPUT);
  pinMode (led2,OUTPUT);
  pinMode (led3,OUTPUT);
  pinMode (led4,OUTPUT);
  pinMode (led5,OUTPUT);
  pinMode (led6,OUTPUT);
  pinMode (btn1,INPUT);
}


void loop() {
  if (digitalRead (btn)== HIGH){
    delay (300);
    state=1-state;
    if(state==1){
    while (j<=7){
      j++;
        for(i=0;i<6;i++){
          digitalWrite(vector[i], HIGH);
          delay(150);
          digitalWrite(vector[i],LOW);
          delay(150);
      }
    }
    }else{
    while (p<=7){
      p++;
        for(i=0;i<6;i++){
          digitalWrite(vector[i], HIGH);
          delay(200);
          digitalWrite(vector[i],LOW);
          delay(200);
        }      
      }
    }
  }
  if (digitalRead (btn1)==HIGH){
    delay(300);
    state=1-state;
    if (state==1){
      while (k<=9){
        k++;
        digitalWrite (led1, HIGH);
        digitalWrite (led6, HIGH);
        delay(200); 
        digitalWrite (led1,LOW);
        digitalWrite (led6,LOW);
        delay (200);
        digitalWrite (led2, HIGH);
        digitalWrite (led5, HIGH);
        delay(200); 
        digitalWrite (led2,LOW);
        digitalWrite (led5,LOW);
        delay (200);
        digitalWrite (led3, HIGH);
        digitalWrite (led4, HIGH);
        delay(200); 
        digitalWrite (led3,LOW);
        digitalWrite (led4,LOW);
        delay (200);
      }
      }else{ 
        while (l<=9){
          l++;
          digitalWrite (led1, HIGH);
          digitalWrite (led6, HIGH);
          delay(200); 
          digitalWrite (led1,LOW);
          digitalWrite (led6,LOW);
          delay (200);
          digitalWrite (led2, HIGH);
          digitalWrite (led5, HIGH);
          delay(200); 
          digitalWrite (led2,LOW);
          digitalWrite (led5,LOW);
          delay (200);
          digitalWrite (led3, HIGH);
          digitalWrite (led4, HIGH);
          delay(200); 
          digitalWrite (led3,LOW);
          digitalWrite (led4,LOW);
          delay (200);
      }
    }
  }
}
          
