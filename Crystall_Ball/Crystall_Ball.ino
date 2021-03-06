#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
const int switchPin = 6; 
int switchState = 0; 
int prevSwitchState = 0; 
int reply;
void setup(){ 
  pinMode(switchPin, INPUT);
  lcd.begin(16, 2); 
  lcd.print("Kysy "); 
  lcd.setCursor(0, 1); 
  lcd.print("Kristallipallolta"); 
}
void loop(){ 
  switchState = digitalRead(switchPin);
  if(switchState != prevSwitchState){ 
    if(switchState == LOW){ 
      reply = random(8); 
                lcd.clear(); 
      lcd.setCursor(0, 0); 
      lcd.print("Vastaus on: "); 
      lcd.setCursor(0,1 );

      switch(reply){ 
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
  prevSwitchState = switchState;  
} 
