int pin8(8); 
 
int melody[] = {660,660,660,510,660,770,380,510,380,320,440,
  480,450,430,380,660,760,860,700,760,660,520,580,480,510,380,
  320,440,480,450,430,380,660,760,860,700,760,660,520,580,480,
  500,760,720,680,620,650,380,430,500,430,500,570,500,760,720,
  680,620,650,1020,1020,1020,380,500,760,720,680,620,650,380,
  430,500,430,500,570,585,550,500,380,500,500,500,500,760,720,
  680,620,650,380,430,500,430,500,570,500,760,720,680,620,650,
  1020,1020,1020,380,500,760,720,680,620,650,380,430,500,430,
  500,570,585,550,500,380,500,500,500,500,500,500,500,580,660,
  500,430,380,500,500,500,500,580,660,870,760,500,500,500,500,
  580,660,500,430,380,660,660,660,510,660,770,380};
 
int duration[] = {100,100,100,100,100,100,100,100,100,100,100,
  80,100,100,100,80,50,100,80,50,80,80,80,80,100,100,100,100,
  80, 100,100,100,80,50,100,80,50,80,80,80,80,100,100,100,100,
  150,150,100,100,100,100,100,100,100,100,100,100,150,200,80,80,
  80,100,100,100,100,100,150,150,100,100,100,100,100,100,100,100,
  100,100,100,100,100,100,100,100,100,150,150,100,100,100,100,
  100,100,100,100,100,100,150,200,80,80,80,100,100,100,100,100,
  150,150,100,100,100,100,100,100,100,100,100,100,100,100,100,
  60,80,60,80,80,80,80,80,80,60,80,60,80,80,80,80,80,60,80,60,80,
  80,80,80,80,80,100,100,100,100,100,100,100};
 
void setup() { 
  pinMode(8, OUTPUT);
}
 
void loop() {
    for(int note=0; note<156; note++) {
      int durationForNote = duration[note];
      tone(pin8, melody[note], durationForNote);

      int pauseAfterNote[] ={150,300,300,100,300,550,
        575,450,400,500,300,330,150,300,200,200,150,300,150,
        350,300,150,150,500,450,400,500,300,330,150,300,200,
        200,150,300,150,350,300,150,150,500,300,100,150,150,
        300,300,150,150,300,150,100,220,300,100,150,150,300,
        300,300,150,300,300,300,100,150,150,300,300,150,150,
        300,150,100,420,450,420,360,300,300,150,300,300,100,
        150,150,300,300,150,150,300,150,100,220,300,100,150,
        150,300,300,300,150,300,300,300,100,150,150,300,300,
        150,150,300,150,100,420,450,420,360,300,300,150,300,
        150,300,350,150,350,150,300,150,600,150,300,350,150,
        150,550,325,600,150,300,350,150,350,150,300,150,600,
        150,300,300,100,300,550,575};
      delay(pauseAfterNote[note]);}
      
      //noTone(portSpeak);
}
