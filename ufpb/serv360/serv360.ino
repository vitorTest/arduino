#include <Servo.h>

Servo servomotor;

void setup(){
  servomotor.attach(9);
}

void loop(){

  for(int i = 0; i<=180; i++){
    servomotor.write(i);
    delay(20);
  }
  delay(2000);
  for(int i = 180; i>= 0; i--){
    servomotor.write(i);
    delay(20);
  }
  delay(2000);
}


