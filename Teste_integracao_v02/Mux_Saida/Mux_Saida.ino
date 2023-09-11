
#include <Wire_slave.h>

void setup() {
 
  
  // Variaveis de seleção do Mux
  pinMode(PA2, OUTPUT); //LSB
  pinMode(PA3, OUTPUT);
  pinMode(PA4, OUTPUT);
  pinMode(PA5, OUTPUT);
  pinMode(PA6, OUTPUT); //MSB
  
  //  Variaveis de Habilitação do MUX (Nivel logico baixo)
  pinMode(PB0, OUTPUT); // MUX 1 "Eletrodo 1 a 8"
  pinMode(PB1, OUTPUT); // MUX 2 "Eletrodo 9 a 16"
  pinMode(PA10, OUTPUT); //MUX 3 'Eletrodo 17 a 24"
  pinMode(PA9, OUTPUT); // MUX 4 "Eletrodo 25 a 32"
  pinMode(PA8, OUTPUT); // MUX 5 " Seleção do MUX
 
}


void loop() {
  // Eletrodo_2
  digitalWrite(PA2, HIGH);   
  digitalWrite(PA3, LOW);   
  digitalWrite(PA4, LOW);   
  digitalWrite(PA5, LOW);   
  digitalWrite(PA6, LOW);  
}
