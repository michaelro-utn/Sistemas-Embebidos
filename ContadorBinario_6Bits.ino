
/*const int leda=8;
const int ledb=9;
const int ledc=10;
const int ledd=11;
const int lede=12;
const int ledf=13;*/
const int btn=7;
int numero=0;
int k;
void setup() {
for(int i=8;i<=13;i++){ // inicializa variables de salida de forma secuencial
pinMode(i, OUTPUT);
pinMode (btn,INPUT);
}
}

void loop() {
if (digitalRead (btn)==HIGH){
numero++;
if (numero>64){
  numero=0;
}
while (digitalRead (btn)==HIGH){
}
k=numero;
for (int j=8;j<=13;j++){
  digitalWrite (j,k%2); //Secuencia de encendido por cada led 
  k=k/2;
}
}
  }
