#include <Wire.h> 
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

void setup() {
  pinMode(A, INPUT);
  digitalWrite(A, HIGH);
  Serial.begin(9600);

  lcd.begin();
  lcd.clear();
  lcd.setCursor(0,0);
  
  lcd.print("Test");

  lcd.setCursor(0,1);
  lcd.print("Drive");
}

void loop() {
  //getVals();

  int xLoc = analogRead(X);
  xLoc = map(xLoc, 0, 1026, 1, 11);

  int yLoc = analogRead(Y);
  yLoc = map(yLoc, 0, 1026, 1, 11);


//  Serial.print(xLoc);
//  Serial.print(", ");  
//  Serial.print(yLoc);
//  Serial.print(" ");

  nw = getPos(xLoc, yLoc);

  //Serial.println(nw);

  if (nw != -1){
    Serial.println(nw);
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

int getPos(int xLoc, int yLoc){
  int x = -1;
  if (xLoc == 6 && yLoc == 10){
    x = 20;
  }
  if (xLoc == 7 && yLoc == 10){
    x = 1;
  }
  if (xLoc == 8 && yLoc == 9){
    x = 18;
  }
  if (xLoc == 9 && yLoc == 9){
    x = 4;
  }
  if (xLoc == 10 && yLoc == 6){
    x = 13;
  }

  if (x != old){
    return x;
  }
  else {
    return -1;
  }
  
}

void getVals(){
  if (aValue()){
    Serial.println("A");
  }
  
}
