/*********************************
This program will test the lcd
with a hello world string displayed
Kemal Kapetanovic, 8/5 - 2019
********************************/



// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);


void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16,2);
}

void loop(){
  // set the cursor to (0,0):
  lcd.setCursor(0, 0);
  // print from 0 to 9: {
   lcd.print("hello world");  
}
