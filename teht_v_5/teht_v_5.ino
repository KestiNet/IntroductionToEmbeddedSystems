//Määritellään pinnit ja muuttuja

#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,7,1);  
const int tilttiSensori = 6;      
int tilttiTila = 0;              
int edellinenTilttiTila = 0; 
int vastaus;
float lampotila;
int tmp = A1;



//Määritellään setup tiedot ja pyydetään käyttäjää kysymään kristallipallolta
void setup(){ 
  pinMode(3, INPUT);
  pinMode(tilttiSensori, INPUT);
  lcd.begin(16, 2); 
  lcd.print("Kysy "); 
  lcd.setCursor(0, 1); 
  lcd.print("Kristallipallolta");
    attachInterrupt(digitalPinToInterrupt(3), keskeytys, CHANGE);
}
//Määritellään satunnainen vastaus käyttäjän kysymyksiin
void loop(){ 
tilttiTila = digitalRead(tilttiSensori);
  if(tilttiTila != edellinenTilttiTila){ 
    if(tilttiTila == LOW){ 
      vastaus = random(8); 
      lcd.clear(); 
      lcd.setCursor(0, 0); 
      lcd.print("Vastaus on: "); 
      lcd.setCursor(0,1 );

      switch(vastaus){ 
        case 0: lcd.print("Kyllä");
        break; 
        case 1: lcd.print("Todennäköisesti"); 
        break; 
        case 2: lcd.print("Todellakin"); 
        break; 
        case 3: lcd.print("Näyttää hyvältä"); 
        break; 
        case 4: lcd.print("Epäselvää"); 
        break; 
        case 5: lcd.print("Kysy uudestaan"); 
        break; 
        case 6: lcd.print("Epätodennäköisesti"); 
        break;
        case 7: lcd.print("Ei"); 
        break; 
      } 
    } 
  } 
  edellinenTilttiTila = tilttiTila; 
} 

//Keskeytys jossa pyritään muuttamaan acd arvo celsiukseksi.
void keskeytys(){
    lcd.clear();
    int lukema = analogRead(tmp);
    lampotila = lukema * 5.0;
    lampotila /= 1024.0;
    float tlampo = (lampotila -0.5)*100;
    lcd.setCursor(0,1);
    lcd.print("Tmp:"); 
    lcd.print(tlampo);
    }

  
