<h1>Circuit Documentation</h1><br/>
<h2>Summary</h2><br/>
<p>This project is like a toy for my kids. It opens a safe door by linear actuator. It activates by inputting the result of calculations. LCD screen displays some math tasks (for example 4*8), if the answer is correct, the safe door starts to open. Also the circuit allows the use of RFID for opening the door of the safe.</p>
<p>This circuit integrates various components controlled by an Arduino Mega 2560 microcontroller to perform a range of functions. The circuit includes an RFID-RC522 module for RFID reading, a 16x4 LCD display for user interface, a 4x4 membrane matrix keypad for input, a two-channel relay to control a linear actuator, a green LED for indication, a buzzer for audio signaling, and a rotary potentiometer to adjust the contrast of the LCD display. The circuit is powered by a 3.3V and 5V for low-voltage components and a 12V for the actuator.</p>

<h2>Component List</h2><br/>
Arduino Mega 2560: A microcontroller board based on the ATmega2560, with numerous digital and analog I/O pins.
16x4 LCD Display: A liquid crystal display capable of showing 4 lines of 16 characters each.
RFID-RC522: An RFID reader/writer module operating at 13.56 MHz.
4x4 Membrane Matrix Keypad: A keypad with 16 buttons arranged in a 4x4 grid for user input.
9V AC/DC adapter: A power source for Arduino by itself.
LED (Green): A two-pin light-emitting diode for indication purposes.
Buzzer: An electronic component that produces sound.
Two Channel Relay 5V: A relay module with two channels that can control high power devices.
Linear Actuator: A device that creates motion in a straight line, controlled by the relay.
12V AC/DC Adapter: A power source for the relay and actuator.
Rotary Potentiometer: A variable resistor with a knob used to adjust the LCD contrast.
<h2>Wiring Details</h2>
<h3>Arduino Mega 2560</h3>
D11 PWM to RFID-RC522 SDA
D52 to RFID-RC522 SCK
D51 to RFID-RC522 MOSI
D50 to RFID-RC522 MISO
D10 PWM to RFID-RC522 RST
D13 PWM to LED anode
GND to LED cathode
D12 PWM to Buzzer PIN
D30 to Relay IN1
D31 to Relay IN2
D14/TX3 to Keypad R1
D15/RX3 to Keypad R2
D16 PWM/TX2 to Keypad R3
D17 PWM/RX2 to Keypad R4
D18/TX1 to Keypad C1
D19/RX1 to Keypad C2
D20/SDA to Keypad C3
D21/SCL to Keypad C4
D7 PWM to LCD DB7
D6 PWM to LCD DB6
D5 PWM to LCD DB5
D4 PWM to LCD DB4
D1 TX0 to LCD RS
D2 PWM to LCD E
<h3>16x4 LCD Display</h3>
LEDK, VSS, RW to GND
LEDA, VDD to 3.3V
VO to Rotary Potentiometer wiper
DB7, DB6, DB5, DB4, RS, E to Arduino Mega 2560
<h3>RFID-RC522</h3>
VCC (3.3V) to 3.3V Battery +
RST to Arduino Mega 2560 D10 PWM
GND to 3.3V Battery -
IRQ (Not connected)
MISO to Arduino Mega 2560 D50
MOSI to Arduino Mega 2560 D51
SCK to Arduino Mega 2560 D52
SDA to Arduino Mega 2560 D11 PWM
<h3>4x4 Membrane Matrix Keypad</h3>
R1 to Arduino Mega 2560 D14/TX3
R2 to Arduino Mega 2560 D15/RX3
R3 to Arduino Mega 2560 D16 PWM/TX2
R4 to Arduino Mega 2560 D17 PWM/RX2
C1 to Arduino Mega 2560 D18/TX1
C2 to Arduino Mega 2560 D19/RX1
C3 to Arduino Mega 2560 D20/SDA
C4 to Arduino Mega 2560 D21/SCL
<h3>LED (Green)</h3>
Anode to Arduino Mega 2560 D13 PWM
Cathode to GND
<h3>Buzzer</h3>
PIN to Arduino Mega 2560 D12 PWM
GND to GND
<h3>Two Channel Relay 5V</h3>
VCC to 3.3V Battery +
IN1 to Arduino Mega 2560 D30
IN2 to Arduino Mega 2560 D31
GND to GND
NO1, NO2 to 12V Battery +
NC1, NC2 to 12V Battery -
C1 to Linear Actuator +
C2 to Linear Actuator -
<h3>Linear Actuator</h3>
+ to Relay C1
- to Relay C2
<h3>Rotary Potentiometer</h3>
Leg1 to GND
Wiper to LCD VO
Leg2 to 3.3V<br/>

<p><h2>Circuit:</h2></p><br/>
![Picture of schema](schema_)

