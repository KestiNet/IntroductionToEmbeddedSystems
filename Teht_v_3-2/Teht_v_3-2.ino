int sensePin = A0;  
int lukuArvot = 50;
int mittausArvot = 0;

volatile boolean buttonState = false;   

void setup() {
  Serial.begin(9600);
  pinMode(3, INPUT);
  attachInterrupt(0, mittaus, CHANGE);
}
void loop() {
  
  
}

void mittaus() {

  if(buttonState){
    buttonState = false;
    
  }
  else{
      buttonState = true;
        for(int i = 0; i < lukuArvot; i++){
      mittausArvot += analogRead(A0);
      delay(20);
    }
    int mittausKeskiarvo = mittausArvot / lukuArvot;
    int LT = ((5*mittausKeskiarvo / 1024.0)-0.5)*100;
    Serial.print(String("lt: ") + LT);
    Serial.print(" ");
    Serial.print("\t");
    Serial.print(String("ADC: ") + mittausKeskiarvo);
    Serial.println();
  }
}
