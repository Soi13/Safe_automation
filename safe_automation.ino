/*
Project for openning safe door by linear actuator. It will activates by inputing result of calculations.
This is for kids. Screen will display some math tasks (for example 4*8), if correct answer will be inputed, the safe door will start open.
*/

/*
PINOUT FOR RFID MODULE:
RC522 MODULE    Uno/Nano     MEGA
SDA             D10          D9
SCK             D13          D52
MOSI            D11          D51
MISO            D12          D50
IRQ             N/A          N/A
GND             GND          GND
RST             D9           D8
3.3V            3.3V         3.3V
*/

#include <LiquidCrystal.h>
#include <Keypad.h>
#include <SPI.h>
#include <RFID.h>

#define SDA_DIO 11
#define RESET_DIO 10

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

RFID RC522(SDA_DIO, RESET_DIO);
String RFID_Token = "5971f9b869";
String RFID_Card = "67db2c3cac";

void display_task() {
  int randNumber1 = random(minVal, maxVal);
  int randNumber2 = random(minVal, maxVal);
  res = randNumber1 * randNumber2;

  lcd.print("Dasha & Liza");
  delay(2000);
  lcd.setCursor(0,1);
  lcd.print("Solve it:" + String(randNumber1) + "*" + String(randNumber2) + "=");
}

void open_cabinet() {
  lcd.clear();
  digitalWrite(13, HIGH);
  tone(12, 1000); 
  delay(1000);              // wait for a second
  digitalWrite(13, LOW);
  noTone(12);  
}

void setup() {
  //Serial.begin(115200);
  randomSeed(analogRead(0)); // Seed the random number generator otherwise at the first start arduino will generate the same digits
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.begin(16,2);
  display_task();
  SPI.begin(); 
  RC522.init();
  pinMode(13, OUTPUT); //LED
  pinMode(12, OUTPUT); //Buzzer
}

void loop() {
  //Check why RFID doesn't work with codepanel but alone works great.
  /*if (RC522.isCard()) {
    String id_key = "";
    RC522.readCardSerial();
    
    for (int i=0; i<5; i++) {
      id_key.concat(String(RC522.serNum[i], HEX));
    }
    Serial.print(id_key);

    if (id_key == RFID_Card || id_key == RFID_Token) {
      id_key = "";
      open_cabinet();
    }
  } 
*/

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
  //open_cabinet();
}
