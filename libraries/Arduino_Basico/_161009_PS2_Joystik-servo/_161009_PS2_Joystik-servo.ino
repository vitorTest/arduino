#include <Servo.h>

Servo servo1;
Servo servo2;
int pot1, pot2;

void setup(){
  servo1.attach(5);
  servo2.attach(6);

  servo1.write(90);
  servo2.write(90);
}

void loop(){
  pot1 = analogRead(3);
  pot2 = analogRead(4);

  pot1 = map(pot1, 0, 1023, 0, 180);
  pot2 = map(pot2, 0, 1023, 0, 180);

  servo1.write(pot1);
  servo2.write(pot2);
  delay(15);
}
