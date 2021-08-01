#include <EEPROM.h>

#define AIKA 5000  //The time between each EEPROM write function call in ms

int lampotilaAnturi = A0;      //the ADC pin
int tulostusNappi = 2;     //the print button pin
int tyhjennysNappi = 3;    //the erase button pin

volatile boolean tyhjennys = false;
volatile boolean tulostus = false;
int address = 0;      //EEPROM address counter

unsigned long timer;

float conv_coeff = 0.0;   //coefficient for converting from 0-1024 to 0-5 range

void tulostaAika();
//void tyhjennaEEPROM();
void tulostaLampotila();

void setup() {
  Serial.begin(115200);     //start the serial connection as always
  conv_coeff = 5.0 / 1024.0; //find the coefficient to do the conversion
  timer = millis();         //millis() returns the time since program start in ms
  attachInterrupt(0, keskeytys, CHANGE);
  attachInterrupt(0, tulostus, CHANGE);

}

void loop() {
  if (millis() - timer > AIKA) //check if it's time to do a lampotila sensor sample
  {
    tulostaLampotila();
    timer = millis();
  }

  if (!digitalRead(tulostusNappi)) //check if print button is pressed
  {
    tulostaAika();
    delay(500);
  }

  /*if (!digitalRead(tyhjennysNappi)) //check if erase button is pressed
  {
    tyhjennaEEPROM();
    delay(500);
  }
*/
  delay(1);
}

void tulostaAika()
{
  for (int i = 0 ; i < EEPROM.length() ; i++) {
    byte arvo = EEPROM.read(i);                //read EEPROM data at address i
    if (arvo != 0)                             //skip "empty" addresses
    {
      float lampotila = arvo * conv_coeff;          //convert ADC arvos to lampotilaerature
      lampotila = (lampotila - 0.5) * 100;                //take care of the offset

      Serial.println(lampotila);
    }
  }
}

/*void tyhjennaEEPROM()
{
  for (int i = 0 ; i < EEPROM.length() ; i++) {
    if (EEPROM.read(i) != 0)                    //skip already "empty" addresses
    {
      EEPROM.write(i, 0);                       //write 0 to address i
    }
  }
  Serial.println("Tyhjennetään EEPROM");
  address = 0;                                  //reset address counter
  Serial.println("EEPROM on tyhjä");
}
*/
void tulostaLampotila()
{
  byte arvo = analogRead(lampotilaAnturi);     //read sensor arvo

  EEPROM.write(address, arvo);         //write arvo to current address counter address

  Serial.print("Sensor arvo stored at address ");
  Serial.println(address);

  address++;                      //increment address counter
  if (address == EEPROM.length()) //check if address counter has reached the end of EEPROM
  {
    address = 0;              //if yes: reset address counter
  }
}


void tulostus(){
  if (tulosta) {
    tyhjennys = false;
    exit;
  }
  
}

void keskeytys() {

  if (tyhjennys) {
    tyhjennys = false;
    exit;
  }
  else {
    tyhjennys = true;
    {
      for (int i = 0 ; i < EEPROM.length() ; i++) {
        if (EEPROM.read(i) != 0)                    //skip already "empty" addresses
        {
          EEPROM.write(i, 0);                       //write 0 to address i
        }
      }
      Serial.println("Tyhjennetään EEPROM");
      address = 0;                                  //reset address counter
      Serial.println("EEPROM on tyhjä");
    }
  }
}
