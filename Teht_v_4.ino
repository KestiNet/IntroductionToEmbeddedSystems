#include <EEPROM.h>
#define AIKA 5000

int lampotilaAnturi = A0;
int tulostusNappi = 3;
int tyhjennysNappi = 2;
int ajastin;
int muisti = 0;

volatile boolean tyhjennys = false;
volatile boolean tulostus = false;

void setup() {
  Serial.begin(115200);
  pinMode(tulostusNappi, INPUT);
  pinMode(tyhjennysNappi, INPUT);
  ajastin = millis();

  attachInterrupt(digitalPinToInterrupt(tyhjennysNappi), tyhja, CHANGE);
  attachInterrupt(digitalPinToInterrupt(tulostusNappi), tulosta, CHANGE);

}

void loop() {
 if (millis() - ajastin > AIKA) 
  {
    tulostaLampotila();
    ajastin = millis();
  }
}

void tulostaLampotila()
{
  byte arvo = analogRead(lampotilaAnturi);     

  EEPROM.write(muisti, arvo);        

  muisti++;                      
  if (muisti == EEPROM.length()) 
  {
    muisti = 0;         
  }
  
}

void tyhja(){
  for (int i = 0 ; i < EEPROM.length() ; i++) {
    if (EEPROM.read(i) != 0)                    
        {
          EEPROM.write(i, 0);                       
        }
      }
      Serial.println("Tyhjennetään EEPROM");
      muisti = 0;                                  
      Serial.println("EEPROM on tyhjä");
    }
 

void tulosta(){
      for (int i = 0 ; i < EEPROM.length() ; i++) {
    byte arvo = EEPROM.read(i);                
    if (arvo != 0)                             
    {
      float lampotila = arvo * (5.0 / 1024.0);          
      lampotila = (lampotila - 0.5) * 100;               
      
      Serial.print(String("Aika: ") + ajastin/1000);
      Serial.print(" ");
      Serial.print("\t");
      Serial.print(String("ADC: ") + arvo);
      Serial.print(" ");
      Serial.print("\t");
      Serial.print(String("Lämpötila: ") + lampotila);
      Serial.println();
    }
  }
}
