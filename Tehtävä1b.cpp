int ledPin = 5;
int ledPin1 = 4;
int ledPin2 = 3;
int vilkkuaika = 300;

void setup(){
  {
  pinMode(ledPin, OUTPUT);
  vilkku(3, vilkkuaika); 
}
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);

}

void vilkku(int toisto, int aika)
{
  
 
  for (int i = 0; i < toisto; i++)
  {    
    digitalWrite(ledPin, HIGH);
    delay(300);
    digitalWrite(ledPin, LOW);
    delay(300);
    
  }
}


void loop() {

}