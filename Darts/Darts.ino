#include "Globals.h"
#include "Config.h"
#include "Player.h"
#include "LiquidCrystal_I2C.h"

Globals g;
Config c;
Player p1;
Player p2;
int WhoseTurn = 1;
bool GameOver = false;
int JoystickPosition = 0;
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(c.LCDAddress, c.LCDNumberOfColumns, c.LCDNumberOfRows);

void setup() {
  
  pinMode(c.AButton, INPUT);
  digitalWrite(c.AButton, HIGH);
  Serial.begin(9600);
  lcd.begin();    
  
  ResetGame();   
  
  while (true){  // Main game loop --------------------------------------
    GameOver = false;
    WaitForButton();
    lcd.clear();
    // Print("Points?");

    while (!GameOver){
      p1.ScoreThisRound = 0;
      p2.ScoreThisRound = 0;
      
      WhoseTurn = 1;
      p1 = PlayARound(p1);
      p1 = PlayARound(p1);
      p1 = PlayARound(p1);
      if (p1.Score - p1.ScoreThisRound >= 0){
        p1.SetScore();
      }
      WhoseTurn = 2;
      p2 = PlayARound(p2);
      p2 = PlayARound(p2);
      p2 = PlayARound(p2);
      if (p2.Score - p2.ScoreThisRound >= 0){
        p2.SetScore();
      }
      
      PrintScores();
      WaitForButton();

      CheckIfGameOver();
    }
    lcd.clear();
  } // -------------------------------------------------------------------
    
}

Player PlayARound(Player player){    
  JoystickPosition = 0;

  GetDartValue();
  int mult = GetMultiplier();
  player.ScoreThisRound += JoystickPosition * mult;
  
  return player;  
 
}

void CheckIfGameOver(){
      if (p1.Score == 0 && p2.Score == 0){
        NotifyGameOver("TIE GAME");
      }
      else if (p1.Score == 0){
        NotifyGameOver("P1 WINS");
      }
      else if (p2.Score == 0){
        NotifyGameOver("P2 WINS");
      }
}

void NotifyGameOver(const char* txt){
  lcd.clear();
  Print(txt);
  WaitForButton();
  WaitForButton();
  GameOver = true;
  ResetGame();
}

void GetDartValue() {  
  JoystickPosition = 0;
  lcd.clear();
  PrintFooter();  
  
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
      PrintFooter();
      JoystickPosition = newPos;
    }
  }

}

int GetMultiplier() {  
  int mult, oldMult = 2;  
  lcd.clear();
  // PrintFooter();  
  
  while (!IsButtonPressed()){    
    int xLoc = analogRead(c.XAxis);
    mult = map(xLoc, 0, 1026, 1, 3);
     
  
    if (mult != oldMult) {
      lcd.clear();
      lcd.setCursor(7, 0);
      Print(mult);
      // PrintFooter();
      oldMult == mult;
    }
  }
  return mult;

}

void PrintScores(){
  lcd.clear();
  
  Print("Player 1: ");
  Println(p1.Score);  
  
  Print("Player 2: ");
  Println(p2.Score);
}

void PrintFooter(){
  lcd.setCursor(0, 1);
  lcd.print("P");
  lcd.print(WhoseTurn);
  lcd.setCursor(13, 1);
  if (WhoseTurn == 1)
    lcd.print(p1.Score - p1.ScoreThisRound);
  else
    lcd.print(p2.Score - p2.ScoreThisRound);
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

void ResetGame(){
  Println("Dart");
  Print("Scoreboard"); 
  p1.Score, p2.Score = 501;
  
}
