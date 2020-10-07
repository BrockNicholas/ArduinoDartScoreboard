#include "Globals.h"
#include "Config.h"
#include "LiquidCrystal_I2C.h"


int position = -1;
int nw = -1;
Globals g;
Config c;
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(c.LCDAddress, c.LCDNumberOfColumns, c.LCDNumberOfRows);

void setup() {
  pinMode(c.AButton, INPUT);
  digitalWrite(c.AButton, HIGH);
  Serial.begin(9600);

  lcd.begin();
  lcd.clear();

  while (true){
    lcd.print("Player 1: 501");
  
    while (!isButtonPressed()){
      
      
    }
    delay(800);
    lcd.clear();
    lcd.print("Points?");
    while (!isButtonPressed()){
      GetDartValue();
    }
    lcd.clear();
  }
    
}

void GetDartValue() {  

  int xLoc = analogRead(c.XAxis);
  xLoc = map(xLoc, 0, 1026, 1, 11);

  int yLoc = analogRead(c.YAxis);
  yLoc = map(yLoc, 0, 1026, 1, 11);


  nw = g.GetPosition(xLoc, yLoc, position);

  if (nw != -1) {
    lcd.clear();
    lcd.setCursor(7, 0);
    lcd.print(nw);
    position = nw;
  }

}

bool isButtonPressed() {
  if (digitalRead(c.AButton) == 0)
    return true;
  return false;
}
