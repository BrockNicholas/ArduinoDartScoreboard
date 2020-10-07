#include "Globals.h"

int Globals::GetPosition(int xLoc, int yLoc, int old) {
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
  if (xLoc == 10 && yLoc == 5){
    x = 6;
  }
  if (xLoc == 10 && yLoc == 4){
    x = 10;
  }
  if (xLoc == 10 && yLoc == 3){
    x = 15;
  }
  if (xLoc == 9 && yLoc == 2){
    x = 2;
  }
  if (xLoc == 7 && yLoc == 1){
    x = 17;
  }
  if (xLoc == 6 && yLoc == 1){
    x = 3;
  }
  if (xLoc == 3 && yLoc == 1){
    x = 19;
  }
  if (xLoc == 2 && yLoc == 2){
    x = 7;
  }
  if (xLoc == 1 && yLoc == 3){
    x = 16;
  }
  if (xLoc == 1 && yLoc == 4){
    x = 8;
  }
  if (xLoc == 1 && yLoc == 5){
    x = 11;
  }
  if (xLoc == 1 && yLoc == 6){
    x = 14;
  }
  if (xLoc == 1 && yLoc == 8){
    x = 9;
  }
  if (xLoc == 3 && yLoc == 10){
    x = 12;
  }
  if (xLoc == 5 && yLoc == 10){
    x = 5;
  }

  if (x != old){
    return x;
  }
  else {
    return -1;
  }
  
}
