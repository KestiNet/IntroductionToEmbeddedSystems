int sensePin = A0;  //This is the Arduino Pin that will read the sensor output
int sensorInput;    //The variable we will use to store the sensor input
double temp;        //The variable we will use to store temperature in degrees. 

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
      sensorInput = analogRead(A0);
      temp = (double)sensorInput / 1024;   //find percentage of input reading
      temp = temp * 5;                     //multiply by 5V to get voltage
      temp = temp - 0.5;                   //Subtract the offset 
      temp = temp * 100; 

   Serial.print("Current Temperature: ");
   Serial.println(temp);
    }
  }
