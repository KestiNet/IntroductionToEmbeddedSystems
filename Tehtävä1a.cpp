int ledPin = 5;
int ledPin1 = 4;
int ledPin2 = 3;

void setup(){
  pinMode(ledPin,OUTPUT);
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);
}
void loop() {
  digitalWrite(ledPin, HIGH);
  delay(300);
  
  digitalWrite(ledPin, LOW);
  delay(300);
  
  digitalWrite(ledPin1, HIGH);
  delay(300);
  
  digitalWrite(ledPin1, LOW);
  delay(300);
  
  digitalWrite(ledPin2, HIGH);
  delay(300);
  
  digitalWrite(ledPin2, LOW);
  delay(300);
  
}