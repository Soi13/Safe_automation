/*
Project for openning safe door by linear actuator. It will activates by inputing result of calculations.
This is for kids. Screen will display some math tasks (for example 4*8), if correct answer will be inputed, the safe door will start open.
*/
#include <LiquidCrystal.h>
#include <Keypad.h>

LiquidCrystal lcd(1, 2, 4, 5, 6, 7); 
const int minVal =  1;   // Inclusive
const int maxVal = 10;   // Exclusive

const byte ROWS = 4; // Four rows
const byte COLUMNS = 4; // Four columns
char keys[ROWS][COLUMNS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; // Connect to the row pinouts of the keypad
byte columnPins[COLUMNS] = {5, 4, 3, 2}; // Connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, columnPins, ROWS, COLUMNS );


void setup() {
  //Serial.begin(9600);
  lcd.begin(16,2);
}

void loop() {
  int randNumber1 = random(minVal, maxVal);
  int randNumber2 = random(minVal, maxVal);
  //int res = randNumber1*randNumber2;
  //Serial.print(String(randNumber1) + "*" + String(randNumber2) + "=" + String(res));
  //Serial.println();
  //delay(1000);

  //char key = keypad.getKey();// Read the key
  // Print if key pressed
  //if (key){
  //  Serial.print("Key Pressed : ");
  //  Serial.println(key);
  / / }

  lcd.print("Dasha & Liza"); // Prints "Arduino" on the LCD 
  delay(2000); // 3 seconds delay 
  lcd.setCursor(0,1); // Sets the location at which subsequent text written to the LCD will be displayed 
  lcd.print("Solve it :" + String(randNumber1) + "*" + String(randNumber2) + "="); 
  delay(5000); 
  lcd.clear(); // Clears the display 
  //lcd.blink(); //Displays the blinking LCD cursor 
  //delay(4000); 
  //lcd.setCursor(7,1); 
  //delay(3000); 
  //lcd.noBlink(); // Turns off the blinking LCD cursor 
  //lcd.cursor(); // Displays an underscore (line) at the position to which the next character will be written 
  //delay(4000); 
  //lcd.noCursor(); // Hides the LCD cursor 
  //lcd.clear(); // Clears the LCD screen 
}
