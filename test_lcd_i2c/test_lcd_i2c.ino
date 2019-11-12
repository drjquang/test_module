/*
 * Date: Tue, 12/11/2019
 * Desc: UNO, test LCD I2C
 * Info: I2C address is 0x3F
 *       Using library LiquidCrystal_v1.2.1
 *       Unzip LiquidCrystal_I2C.zip, Wire.zip and add to arduino\libraries
 */
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() {
  // initialize LCD1602, backlight ON
  lcd.begin(16,2); //(col,row)
  lcd.backlight();
}

void loop() {
  lcd.clear();               // Clean the screen
  lcd.setCursor(1,0);        // We start writing from the second column and the first row
  lcd.print("MCS_TECH_FELIX");
  delay(1000);               // Delay used to give a dynamic effect
  lcd.setCursor(0,1);
  lcd.print("Have a nice day!");
  delay(5000);
  
  lcd.clear();               // Clean the screen
  lcd.setCursor(0,0);
  lcd.print("How are you now?");
  lcd.setCursor(1,1);
  lcd.print("MCS_TECH_FELIX");
  delay(5000);
}
