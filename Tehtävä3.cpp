void setup(){
 Serial.begin(9600);
 pinMode(7,OUTPUT);

}

void loop(){
  digitalWrite(7, HIGH);
  
  Serial.println("led ON ");
  delay(2000);
  digitalWrite(7, LOW);
  
  Serial.println("led is OFF ");
  delay(2000);
  

  }
    

    