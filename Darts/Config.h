
#include <Arduino.h>
#include "LiquidCrystal_I2C.h"

class Config {

    public:
        static const int AButton;
        static const int XAxis;
        static const int YAxis;

        static LiquidCrystal_I2C lcd(uint8_t lcd_addr, uint8_t lcd_cols, uint8_t lcd_rows);
};
