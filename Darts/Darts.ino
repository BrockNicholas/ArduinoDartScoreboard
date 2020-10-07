#include "Globals.h"
#include "Config.h"
#include "Player.h"
#include "LiquidCrystal_I2C.h"

Globals g;
Config c;
Player p1;
Player p2;
bool GameOver = false;
int JoystickPosition = 0;
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(c.LCDAddress, c.LCDNumberOfColumns, c.LCDNumberOfRows);

void setup() {
  
  pinMode(c.AButton, INPUT);
  digitalWrite(c.AButton, HIGH);
  Serial.begin(9600);
  lcd.begin();  
  
  
  Println("Dart");
  Print("Scoreboard");
  
  while (true){  // Main game loop
    WaitForButton();
    lcd.clear();
    // Print("Points?");

    while (!GameOver){
      PlayARound(p1);
      PlayARound(p2);
      PrintScores();
    }
    lcd.clear();
  }
    
}

void PlayARound(Player player){  
  player.ScoreThisRound = 0;
  
  GetDartValue();
  player.ScoreThisRound = JoystickPosition;
  GetDartValue();
  player.ScoreThisRound = JoystickPosition;
  GetDartValue();
  player.ScoreThisRound = JoystickPosition;

  if (player.Score - player.ScoreThisRound >= 0){
    player.SetScore();
  }


  
 
}

void GetDartValue() {  
  JoystickPosition = 0;
  while (!IsButtonPressed()){
    int newPos;
    int xLoc = analogRead(c.XAxis);
    xLoc = map(xLoc, 0, 1026, 1, 11);
  
    int yLoc = analogRead(c.YAxis);
    yLoc = map(yLoc, 0, 1026, 1, 11);
  
  
    newPos = g.GetJoystickPosition(xLoc, yLoc, JoystickPosition);
  
    if (newPos != -1) {
      lcd.clear();
      lcd.setCursor(7, 0);
      Print(newPos);
      JoystickPosition = newPos;
    }
  }

}

void PrintScores(){
  lcd.clear();
  
  Print("Player 1: ");
  Println(p1.Score);  
  
  Print("Player 2: ");
  Println(p2.Score);
}

void Println(const char* txt){
  Print(txt);
  Serial.print("\n");
  lcd.setCursor(0, 1);
}

void Println(int txt){
  Print(txt);
  Serial.print("\n");
  lcd.setCursor(0, 1);
}

void Print(const char* txt){
  Serial.print(txt);
  lcd.print(txt);
}

void Print(int txt){
  Serial.print(txt);
  lcd.print(txt);
}

void WaitForButton() {
  while (!IsButtonPressed()){    
    
  }
}

bool IsButtonPressed(){
  if (digitalRead(c.AButton) == 0){
      delay(800); // To make sure control doesn't try to continue while button is still pressed
      return true;
    }
  return false;
}
