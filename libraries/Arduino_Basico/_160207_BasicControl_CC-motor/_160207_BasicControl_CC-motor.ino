int potPin        = 0;
int transistorPin = 9;
int potValue      = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(transistorPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  potValue    = analogRead(potPin) / 2;
  analogWrite(transistorPin, potValue);
}
