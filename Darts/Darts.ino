#include "Globals.h"
#include "LiquidCrystal_I2C.h"

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);


// Arduino pin numbers
const int A = 3; // digital pin connected to switch output
const int X = 0; // analog pin connected to X output
const int Y = 2; // analog pin connected to Y output
bool aReset = 1;
bool xReset = 1;
bool yReset = 1;
int old = -1;
int nw = -1;
Globals g;

void setup() {
  pinMode(A, INPUT);
  digitalWrite(A, HIGH);
  Serial.begin(9600);

  lcd.begin();
  lcd.clear();
  
  Serial.println("HOLD");
  Serial.println(g.hold);
}

void loop() {  

  int xLoc = analogRead(X);
  xLoc = map(xLoc, 0, 1026, 1, 11);

  int yLoc = analogRead(Y);
  yLoc = map(yLoc, 0, 1026, 1, 11);


  nw = g.GetPos(xLoc, yLoc, old);

  if (nw != -1) {
    lcd.clear();
    lcd.setCursor(7, 0);
    lcd.print(nw);
    old = nw;
  }

}

bool isButtonPressed() {
  if (digitalRead(A) == 0)
    return true;
  return false;
}
