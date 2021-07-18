int ledPin = 5;
int ledPin1 = 4;
int ledPin2 = 3;

byte vilkkuLaskuri = 0;

void setup(){
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);

}

void loop(){  
  
  for (byte i = 0; i < vilkkuLaskuri; i++) {
  digitalWrite(ledPin1, HIGH);    
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin, LOW);
  delay(300);
  digitalWrite(ledPin, HIGH);
  delay(300);
}
delay(1000);

vilkkuLaskuri++;
  
  if (vilkkuLaskuri == 3){
    digitalWrite(ledPin, LOW);
    digitalWrite (ledPin1, LOW);
    digitalWrite (ledPin2, LOW);
    delay(1000);
}
  }