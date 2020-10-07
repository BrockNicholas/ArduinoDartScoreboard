#include "Config.h"
#include "LiquidCrystal_I2C.h"

// Arduino pin numbers
const int Config::AButton = 3;
const int Config::XAxis = 0;
const int Config::YAxis = 2;

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C Config::lcd(uint8_t lcd_addr, uint8_t lcd_cols, uint8_t lcd_rows);
