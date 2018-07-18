
#include <Servo.h>
#define SERVO 6

Servo s;
int pos;

void setup(){
    s.attach(SERVO);
    Serial.begin(9600);
    s.write(0);
}

void loop(){
    for(pos= 0; pos< 360; pos++){
         s.write(pos);
         delay(15);
    }
    for(pos= 360; pos>= 0; pos--){
        s.write(pos);
        delay(15);
    }
}

