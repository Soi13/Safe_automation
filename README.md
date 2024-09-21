<h1>Circuit Documentation</h1><br/>
<h2>Summary</h2><br/>
<p>This project is like a toy for my kids. It opens a safe door by linear actuator. It activates by inputting the result of calculations. LCD screen displays some math tasks (for example 4*8), if the answer is correct, the safe door starts to open. Also the circuit allows the use of RFID for opening the door of the safe.</p>
<p>This circuit integrates various components controlled by an Arduino Mega 2560 microcontroller to perform a range of functions. The circuit includes an RFID-RC522 module for RFID reading, a 16x4 LCD display for user interface, a 4x4 membrane matrix keypad for input, a two-channel relay to control a linear actuator, a green LED for indication, a buzzer for audio signaling, and a rotary potentiometer to adjust the contrast of the LCD display. The circuit is powered by a 3.3V and 5V for low-voltage components and a 12V for the actuator.</p>

<h2>Component List</h2><br/>
<b>Arduino Mega 2560:</b> A microcontroller board based on the ATmega2560, with numerous digital and analog I/O pins.<br/>
<b>16x4 LCD Display:</b> A liquid crystal display capable of showing 4 lines of 16 characters each.<br/>
<b>RFID-RC522:</b> An RFID reader/writer module operating at 13.56 MHz.<br/>
<b>4x4 Membrane Matrix Keypad:</b> A keypad with 16 buttons arranged in a 4x4 grid for user input.<br/>
<b>9V AC/DC adapter:</b> A power source for Arduino by itself.<br/>
<b>LED (Green):</b> A two-pin light-emitting diode for indication purposes.<br/>
<b>Buzzer:</b> An electronic component that produces sound.<br/>
<b>Two Channel Relay 5V:</b> A relay module with two channels that can control high power devices.<br/>
<b>Linear Actuator:</b> A device that creates motion in a straight line, controlled by the relay.<br/>
<b>12V AC/DC Adapter:</b> A power source for the relay and actuator.<br/>
<b>Rotary Potentiometer:</b> A variable resistor with a knob used to adjust the LCD contrast.<br/>
<h2>Wiring Details</h2>
<h3>Arduino Mega 2560</h3>
<b>D11</b> PWM to RFID-RC522 SDA<br/>
<b>D52</b> to RFID-RC522 SCK<br/>
<b>D51</b> to RFID-RC522 MOSI<br/>
<b>D50</b> to RFID-RC522 MISO<br/>
<b>D10</b> PWM to RFID-RC522 RST<br/>
<b>D13</b> PWM to LED anode<br/>
<b>GND</b> to LED cathode<br/>
<b>D12</b> PWM to Buzzer PIN<br/>
<b>D30</b> to Relay IN1<br/>
<b>D31</b> to Relay IN2<br/>
<b>D14/TX3</b> to Keypad R1<br/>
<b>D15/RX3</b> to Keypad R2<br/>
<b>D16 PWM/TX2</b> to Keypad R3<br/>
<b>D17 PWM/RX2</b> to Keypad R4<br/>
<b>D18/TX1</b> to Keypad C1<br/>
<b>D19/RX1</b> to Keypad C2<br/>
<b>D20/SDA</b> to Keypad C3<br/>
<b>D21/SCL</b> to Keypad C4<br/>
<b>D7 PWM </b>to LCD DB7<br/>
<b>D6 PWM</b> to LCD DB6<br/>
<b>D5 PWM</b> to LCD DB5<br/>
<b>D4 PWM</b> to LCD DB4<br/>
<b>D1 TX0</b> to LCD RS<br/>
<b>D2 PWM</b> to LCD E<br/>
<h3>16x4 LCD Display</h3>
<b>LEDK, VSS, RW</b> to GND<br/>
<b>LEDA, VDD</b> to 3.3V<br/>
<b>VO</b> to Rotary Potentiometer wiper<br/>
<b>DB7, DB6, DB5, DB4, RS, E</b> to Arduino Mega 2560<br/>
<h3>RFID-RC522</h3>
<b>VCC (3.3V)</b> to 3.3V Battery +<br/>
<b>RST</b> to Arduino Mega 2560 D10 PWM<br/>
<b>GND</b> to 3.3V Battery -<br/>
<b>IRQ</b> (Not connected)<br/>
<b>MISO</b> to Arduino Mega 2560 D50<br/>
<b>MOSI</b> to Arduino Mega 2560 D51<br/>
<b>SCK</b> to Arduino Mega 2560 D52<br/>
<b>SDA</b> to Arduino Mega 2560 D11 PWM<br/>
<h3>4x4 Membrane Matrix Keypad</h3>
<b>R1</b> to Arduino Mega 2560 D14/TX3<br/>
<b>R2</b> to Arduino Mega 2560 D15/RX3<br/>
<b>R3</b> to Arduino Mega 2560 D16 PWM/TX2<br/>
<b>R4</b> to Arduino Mega 2560 D17 PWM/RX2<br/>
<b>C1</b> to Arduino Mega 2560 D18/TX1<br/>
<b>C2</b> to Arduino Mega 2560 D19/RX1<br/>
<b>C3</b> to Arduino Mega 2560 D20/SDA<br/>
<b>C4</b> to Arduino Mega 2560 D21/SCL<br/>
<h3>LED (Green)</h3>
<b>Anode</b> to Arduino Mega 2560 D13 PWM<br/>
<b>Cathode</b> to GND<br/>
<h3>Buzzer</h3>
<b>PIN</b> to Arduino Mega 2560 D12 PWM<br/>
<b>GND</b> to GND<br/>
<h3>Two Channel Relay 5V</h3>
<b>VCC</b> to 3.3V Battery +<br/>
<b>IN1</b> to Arduino Mega 2560 D30<br/>
<b>IN2</b> to Arduino Mega 2560 D31<br/>
<b>GND</b> to GND<br/>
<b>NO1, NO2</b> to 12V Battery +<br/>
<b>NC1, NC2</b> to 12V Battery -<br/>
<b>C1</b> to Linear Actuator +<br/>
<b>C2</b> to Linear Actuator -<br/>
<h3>Linear Actuator</h3>
<b>+</b> to Relay C1<br/>
<b>-</b> to Relay C2<br/>
<h3>Rotary Potentiometer</h3>
<b>Leg1</b> to GND<br/>
<b>Wiper</b> to LCD VO<br/>
<b>Leg2</b> to 3.3V<br/><br/><br/><br/>

<p><h2>Watch the video</h2></p><br/>

[![Video Title](https://img.youtube.com/vi/93Auo3oyyt0/mq2.jpg)](https://youtube.com/shorts/93Auo3oyyt0)


<p><h2>Circuit:</h2></p><br/>

![Picture of schema](schema.png)

