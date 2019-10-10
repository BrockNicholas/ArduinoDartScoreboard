#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
int p1 = 501;
int p2 = 501;
  
void setup()
{
  
  // initialize the LCD
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.print("Dart Test");
  ShowScores();
}

void loop()
{
  // Do nothing here...
}

void ShowScores(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("P1: " + (String)p1);
  lcd.setCursor(0,1);
  lcd.print("P2: " + (String)p2);
}
