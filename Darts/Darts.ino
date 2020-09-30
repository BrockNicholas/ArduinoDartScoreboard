#include "Eval.h"
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
Eval e;

void setup() {
  pinMode(A, INPUT);  
  Serial.begin(9600);

  lcd.begin();
  lcd.clear();
  lcd.setCursor(0,0);
    
}

void loop() {
  getVals();

  int xLoc = analogRead(X);
  xLoc = map(xLoc, 0, 1026, 1, 11);

  int yLoc = analogRead(Y);
  yLoc = map(yLoc, 0, 1026, 1, 11);


  Serial.print(xLoc);
  Serial.print(", ");  
  Serial.print(yLoc);
  Serial.println(" ");

  nw = e.GetPos(xLoc, yLoc, old);  

  if (nw != -1){
    // Serial.println(nw);
    lcd.clear();
    lcd.setCursor(7,0);
    lcd.print(nw);
    old = nw;
  }

}

bool aValue(){
  bool val = digitalRead(A);
  if (val == 1){
    aReset = 1;
  }
  else if (val == 0 && aReset == 1){
    aReset = 0;
    return 1;
  }
  
  return 0;
}

int xValue(){
  long val = analogRead(X);
  if (val > 400 && val < 600){
    xReset = 1;
    return 0;
  }
  else if (val <= 400 && xReset == 1){
    xReset = 0;
    return -1;
  }
  else if (val >= 600 && xReset == 1){
    xReset = 0;
    return 1;
  }
  return 0;
}

int yValue(){
  long val = analogRead(Y);
  if (val > 400 && val < 600){
    yReset = 1;
    return 0;
  }
  else if (val <= 400 && yReset == 1){
    yReset = 0;
    return -1;
  }
  else if (val >= 600 && yReset == 1){
    yReset = 0;
    return 1;
  }
  return 0;
}

void getVals(){
  if (aValue()){
    Serial.println("A");
  }
  
}
