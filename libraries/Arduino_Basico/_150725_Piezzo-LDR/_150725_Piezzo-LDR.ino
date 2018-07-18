int pinoPiezzo = 9;
int pinoLDR = 3;
int luz;

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  luz = analogRead(pinoLDR);
  tone(pinoPiezzo, 1000);
  delay(25);
  noTone(pinoPiezzo);
  delay(luz);
}
