
int maara = 0;      

volatile boolean buttonState = false;   

void setup() {
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  pinMode(3, INPUT);
  attachInterrupt(0, keskeytys, RISING);
  delay(25);

}

void loop() {
  
}

void keskeytys() {

  if(buttonState){
    buttonState = false;
    digitalWrite(12, LOW);
  }
  else{
      buttonState = true;
      maara++;
      if((maara%2) == 0){
        digitalWrite(12, LOW);
      }
      else{
        digitalWrite(12,HIGH);
      }
      Serial.println(String("Laskuri: ") + maara);
      delay(250);
    }
  }
