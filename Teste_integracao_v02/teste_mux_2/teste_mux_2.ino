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
  pinMode(PB0, OUTPUT);
  pinMode(PB1, OUTPUT);
  pinMode(PA10, OUTPUT);
  pinMode(PA9, OUTPUT);
  pinMode(PA8, OUTPUT);
  pinMode(PA2, OUTPUT);
  pinMode(PA3, OUTPUT);
  pinMode(PA4, OUTPUT);
  pinMode(PA5, OUTPUT);
  pinMode(PA6, OUTPUT);

  
  digitalWrite(PB0, LOW);   
  digitalWrite(PB1, HIGH);   
  digitalWrite(PA10,HIGH);   
  digitalWrite(PA9, HIGH);   
  digitalWrite(PA8, LOW);   
}

// the loop function runs over and over again forever
void loop() {
  // Eletrodo_1
  digitalWrite(PA2, LOW);   
  digitalWrite(PA3, LOW);   
  digitalWrite(PA4, LOW);   
  digitalWrite(PA5, LOW);   
  digitalWrite(PA6, LOW);  
}
