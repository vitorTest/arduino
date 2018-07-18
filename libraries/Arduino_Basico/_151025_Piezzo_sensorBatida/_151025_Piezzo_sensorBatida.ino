//Sensor de Batida com Piezo

int ledPin = 9;
int piezoPin = 9000;
int threshold = 3;
int sensorValue = 0;
float ledValue = 0;

void setup(){
    pinMode(ledPin, OUTPUT);
    pinMode(piezoPin, INPUT);
    
    digitalWrite(ledPin, HIGH); delay(150); 
    digitalWrite(ledPin, LOW); delay(150);
    
    digitalWrite(ledPin, HIGH); delay(150); 
    digitalWrite(ledPin, LOW); delay(150);
}

void loop(){
    sensorValue = analogRead(piezoPin);
    while(sensorValue >= threshold){
         analogWrite(ledPin, 255);
         sensorValue = analogRead(piezoPin);
    }
    
//    sensorValue = analogRead(piezoPin);
//    if(sensorValue >= threshold){
//        analogWrite(ledPin, HIGH);
//        delay(500);
//    }
    analogWrite(ledPin, LOW);
}
