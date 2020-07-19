import ddf.minim.*;
Minim minim;
AudioPlayer sonido1;
PImage [] galax=new PImage [20];
PImage nave;
PImage columna1;
PImage log;
PFont font1;
int gamestate = 1, score = 0, highScore = 0, x = -200, y, vy = 0, wx[] = new int[2], wy[] = new int[2];
void setup() {
  size(600,800);
  galax[0]=loadImage("1.gif");
  galax[1]=loadImage("2.gif");
  galax[2]=loadImage("3.gif");
  galax[3]=loadImage("4.gif");
  galax[4]=loadImage("5.gif");
  galax[5]=loadImage("6.gif");
  galax[6]=loadImage("7.gif");
  galax[7]=loadImage("8.gif");
  galax[8]=loadImage("9.gif");
  galax[9]=loadImage("10.gif");
  galax[10]=loadImage("11.gif");
  galax[11]=loadImage("12.gif");
  galax[12]=loadImage("13.gif");
  galax[13]=loadImage("14.gif");
  galax[14]=loadImage("15.gif");
  galax[15]=loadImage("16.gif");
  galax[16]=loadImage("17.gif");
  galax[17]=loadImage("18.gif");
  galax[18]=loadImage("19.gif");
  galax[19]=loadImage("20.gif");
  nave=loadImage("nave.png");
  columna1=loadImage("columna.PNG");
  font1=loadFont("ShowcardGothic-Reg-25.vlw");
  textFont(font1);
  minim=new Minim(this);
  sonido1=minim.loadFile("Hello.mp3");
  fill(0);
  //textSize(40);  
}
void draw() { //runs 60 times a second
  if(gamestate == 0) {
    imageMode(CORNER);
    image(galax[frameCount%20],0,0,600,800);
    fill(0);
    x -= 6;
    vy += 1;
    y += vy;
    if(x == -1800) x = 0;
    for(int i = 0 ; i < 2; i++) {
      imageMode(CENTER);
      image(columna1, wx[i], wy[i] - (columna1.height/2+100));
      image(columna1, wx[i], wy[i] + (columna1.height/2+100));
      if(wx[i] < 0) {
        wy[i] = (int)random(200,height-200);
        wx[i] = width;
      }
      if(wx[i] == width/2) highScore = max(++score, highScore);
      if(y>height||y<0||(abs(width/2-wx[i])<25 && abs(y-wy[i])>100)) gamestate=1;
      wx[i] -= 6;
    }
    image(nave, width/2, y,80,100);
    //textSize(20);
    fill(2,177,163);
    text("HIGH SCORE",400,90);
    text("000"+highScore,440,120);
    fill(255,255,255);
    text("YOUR RECORD",50,90);
    text("000"+score,90,120);
  }
  else {
    imageMode(CENTER);
    image(galax[frameCount%20],300,400,600,800);
    imageMode(CENTER);
    image(nave,width/2,400,120,120);
    log=loadImage("logo.png");
    image(log,300,200,300,300);
    image(columna1,100,400,40,300);
    image(columna1,500,400,40,300);
    textSize(30);
    fill(255,255,255);
    text("MAXIMO RECORD", 50, 640);
    text(highScore,50,680);
  }
  if(sonido1.isPlaying()){
    textSize(20);
    fill(2,177,163);
    text("Presione cualquier tecla para desactivar sonido",50,720);
  }else{
    textSize(20);
    fill(2,177,163);
    text("Presione cualquier tecla para activar sonido",50,720);
  }
}
void mousePressed() {
  vy = -17;
  if(gamestate==1) {
    wx[0] = 600;
    wy[0] = y = height/2;
    wx[1] = 900;
    wy[1] = 600;
    x = gamestate = score = 0;
  }
}

void keyPressed(){
  if(sonido1.isPlaying()){
    sonido1.pause();
  }else{
    sonido1.play();
  }
}
