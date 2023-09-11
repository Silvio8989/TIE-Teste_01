/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(PA12, OUTPUT);
  pinMode(PA11, OUTPUT);
  pinMode(PA10, OUTPUT);
  pinMode(PA9, OUTPUT);
  pinMode(PA8, OUTPUT);
  pinMode(PA2, OUTPUT);
  pinMode(PA3, OUTPUT);
  pinMode(PA4, OUTPUT);
  pinMode(PA5, OUTPUT);
  pinMode(PA6, OUTPUT);

  digitalWrite(PA12, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(PA11, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(PA10, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(PA9, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(PA8, LOW);   // turn the LED on (HIGH is the voltage level)
}

// the loop function runs over and over again forever
void loop() {
  // Eletrodo_1
  digitalWrite(PA2, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(PA3, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(PA4, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(PA5, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(PA6, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  // Eletrodo_2
  digitalWrite(PA2, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(PA3, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(PA4, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(PA5, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(PA6, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(1000);
  // Eletrodo_3
  digitalWrite(PA2, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(PA3, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(PA4, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(PA5, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(PA6, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(1000);
  // eletrodo_4
  digitalWrite(PA2, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(PA3, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(PA4, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(PA5, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(PA6, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(1000);
  // Eletrodo_5
  digitalWrite(PA2, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(PA3, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(PA4, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(PA5, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(PA6, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(1000);
  // Eletrodo_6
  digitalWrite(PA2, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(PA3, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(PA4, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(PA5, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(PA6, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(1000);
  // Eletrodo_7
  digitalWrite(PA2, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(PA3, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(PA4, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(PA5, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(PA6, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(1000);
  // Eletrodo_8
  digitalWrite(PA2, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(PA3, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(PA4, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(PA5, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(PA6, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
}
