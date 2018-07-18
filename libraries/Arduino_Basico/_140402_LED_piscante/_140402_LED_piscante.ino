int ledPin = 10;

void setup(){
  pinMode(ledPin, OUTPUT);
}

void loop(){
  for(int x=0; x<2; x++ ){
   digitalWrite(ledPin, HIGH);
   delay(1000);
   digitalWrite(ledPin, LOW);
   delay(1000);
  }
  
  for(int x=0; x<2; x++){ 
    digitalWrite(ledPin, HIGH);
    delay(3000);
    digitalWrite(ledPin, LOW);
    delay(3000);
  }
}  
