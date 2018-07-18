#include <Servo.h>

int trigPin = 11;
int echoPin = 12;
int pos     = 0;
int logicPin = 7;
long duration, cm;

//Bluetooth
String data;

void setup() {
  
  Serial.begin(9600);

  //Setting Pins
  //Ultrasom
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(logicPin, OUTPUT);
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
  cm = (duration/2) / 29.1;

  if(cm < 20){
    Serial.println(data);
    Serial.println(cm);
    digitalWrite(logicPin, LOW);
//
//    data="";
//    Serial.println("Estado critico");
//    Serial.print(cm); 
//    Serial.print("cm\n");
    data = "erased";
  }
  else{
    digitalWrite(logicPin, HIGH); 
  }

  while(Serial.available()){
    delay(20); //small time to fill the buffer

    char c = Serial.read();
    if(c == 'a'){
      delay(700); 
    }
    if(c == ','){
      break;  
    }

    data += c;
         
    //data[0] = Serial.read();
//    tap.write(180);
//    Serial.print(data);
//    Serial.print("\n");
//    delay(1000);
//    Serial.flush();
//    data = "";
  }

//  if(data.length() > 0){
//    Serial.println(data);
//
//    data="";
//  }
  
}

//https://randomnerdtutorials.com/complete-guide-for-ultrasonic-sensor-hc-sr04/
