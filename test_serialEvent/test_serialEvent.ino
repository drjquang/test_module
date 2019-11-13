/*
 * Date: Tue, 12/11/2019
 * Desc: UNO, test serialEvent
 * Info: Serial, received string end with <CR>,
 *       then echo received string and number of character
 *       to LCD I2C and serial
 */
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
// Variable declaration
String inputString;          // a String to hold incoming data
int numberofChar;
bool stringComplete;         // the flag that shows whether the string is complete
void setup() {
  // initialize first delay
  delay(2000);
  // initialize serial port
  Serial.begin(9600);        // Uno Xtal=16MHz
  inputString.reserve(16);   // reserve 16 bytes for the inputString

  // initialize variable
  inputString = "";
  numberofChar = 0;
  stringComplete = false;
  // initialize LCD1602, backlight ON
  lcd.begin(16,2); //(col,row)
  lcd.backlight();
  lcd.clear();               // Clean the screen
  lcd.setCursor(0,0);
  lcd.print("Waiting message:");
  delay(1000);
}

void loop() {
  // print the string when a <CR> arrives:
  if (stringComplete) {
    // echo back to serial and display LCD
    display_serial(inputString, numberofChar);
    display_lcd(numberofChar, inputString);
    // clear the string, reset numberofChar and flag stringComplete, clear LCD
    inputString = "";
    numberofChar = 0;
    stringComplete = false;
    
    delay(5000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Waiting message:");
  }
}

/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    numberofChar++;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\r') {
      stringComplete = true;          
    }
  }
}

void display_serial(String rcvString, int numChar ) {
  Serial.print("Received string: ");
  Serial.println(rcvString);
  Serial.print("Number of characters received: ");
  Serial.println(numChar);
}
void display_lcd(int numChar, String rcvString) {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("numChar = ");
  lcd.setCursor(10,0);
  lcd.print(numChar);
  lcd.setCursor(0,1);
  lcd.print(rcvString);
}
