#include <Servo.h>

//Ultrasom
const int trigPin = 3;
const int echoPin = 2;
long duration, distance;

//Servo
//servo1 = servo 360
//servo2 = servo 180 hackeado
Servo servo1;//, servo2;
const int servo1Ctrl = 9;
int val;
unsigned long timeToTurn;

void setup() {
  
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(servo1Ctrl, OUTPUT);
  
  servo1.attach(8);
  //servo2.attach(9);
  
  Serial.begin(9600); 

}

void loop() {
  
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // convert the time into a distance
  distance = (duration/2) / 29.1;

  // Stop
  if(distance < 25){

    servo1.write(90); 
    analogWrite(servo1Ctrl, 0);
    
    Serial.println(distance);

    // Walking backwards 
//    int waiter = 0;
//    while(waiter != 1){
//      waiter = turnDecision();
//    }
      timeToTurn = millis();
    
      while(timeToTurn - millis() < 10000){
        servo1.write(180);
      }
  }
  else{
    
    // Walking towards
    servo1.write(0);                   
    analogWrite(servo1Ctrl,200);
  } 
}
//
//int turnDecision(){
//  char decision;
//  Serial.println("Escreva 'd' para virar à direita");
//  Serial.println("ou 'e' para virar à esquerda");
//  
//  if(Serial.available() > 0){
//    delay(20); //small time to fill the buffer
//    decision = Serial.read();
//  }
//  
//  switch(decision){
//    case 'd':
//      Serial.println("Virando à direita");
//      turnRight();
//      return 1;
//      
//    case 'e':
//      Serial.println("Virando à esquerda");
//      turnLeft();
//      return 1;
//
//    default:
//      Serial.println("Opcao Invalida");
//      return 0;
//  }
//}
//
//void turnLeft(){
//  timeToTurn = millis();
//    
//    while(timeToTurn - millis() < 10000){
//      servo1.write(180);
//    }
//    Serial.println("opcao 'virar à esquerda' completa");
//}
//
//void turnRight(){
//  timeToTurn = millis();
//    
//    while(timeToTurn - millis() < 10000){
//      analogWrite(servo1Ctrl, 10);
//    }
//    Serial.println("opcao 'virar à direita' completa");
//}
