/*
Project for openning safe door by linear actuator. It will activates by inputing result of calculations.
This is for kids. Screen will display some math tasks (for example 4*8), if correct answer will be inputed, the safe door will start open.
*/
#include <LiquidCrystal.h>
#include <Keypad.h>

LiquidCrystal lcd(1, 2, 4, 5, 6, 7); 
const int minVal =  1;   //Inclusive
const int maxVal = 10;   //Exclusive

int res;
int attempt = 0;

int trigPin = 9; //TRIG pin
int echoPin = 8; //ECHO pin
float duration_us, distance_cm;

const byte ROWS = 4;
const byte COLUMNS = 4;
char keys[ROWS][COLUMNS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {14, 15, 16, 17}; // Connect to the row pinouts of the keypad
byte columnPins[COLUMNS] = {18, 19, 20, 21}; // Connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, columnPins, ROWS, COLUMNS );

void display_task() {
  int randNumber1 = random(minVal, maxVal);
  int randNumber2 = random(minVal, maxVal);
  res = randNumber1 * randNumber2;

  lcd.print("Dasha & Liza");
  delay(2000);
  lcd.setCursor(0,1);
  lcd.print("Solve it:" + String(randNumber1) + "*" + String(randNumber2) + "=");
}

void setup() {
  //Serial.begin(9600);
  randomSeed(analogRead(0)); // Seed the random number generator otherwise at the first start arduino will generate the same digits
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.begin(16,2);
  display_task();
}

void loop() {
  String enteredDigits = "";
  //Person has three attempts for entering solved tasks
  while (attempt < 3) {
    //Collect digits until a '#' key is pressed
    while (true) {
      char key = keypad.getKey();
      if (key != NO_KEY) {
        if (key == '#') {
          break;
        }
        enteredDigits += key;
        lcd.setCursor(13, 1);
        lcd.print(enteredDigits);
      }
    }

    if (enteredDigits.equals(String(res))) {
      lcd.clear();
      lcd.print("Correct answer!");
      enteredDigits="";
      attempt++;
    } else {
      lcd.clear();
      lcd.print("Incorrect answer!");
    }

    // Delay to avoid rapid key detection
    delay(1000);
    lcd.clear();
    display_task();
  }
  
  //After threes successfull attempts open the cabinet door
  lcd.clear();
}
