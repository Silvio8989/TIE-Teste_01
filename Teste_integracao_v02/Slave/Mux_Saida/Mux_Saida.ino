#include <Wire_slave.h>


#define S0 PA2 //LSB
#define S1 PA3 
#define S2 PA4 
#define S3 PA5 
#define S4 PA6 // MSB

#define MUX1 PB0  
#define MUX2 PB1 
#define MUX3 PA10  
#define MUX4 PA9 
#define MUX5 PA8 

void setup() {
 
  Wire.begin(0X61);
   
  // Variaveis de seleção do Mux
  pinMode(S0, OUTPUT); 
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(S4, OUTPUT); 
  
  //  Variaveis de Habilitação do MUX (Nivel logico baixo)
  pinMode(MUX1, OUTPUT); // MUX 1 "Eletrodo 1 a 8"
  pinMode(MUX2, OUTPUT); // MUX 2 "Eletrodo 9 a 16"
  pinMode(MUX3, OUTPUT); //MUX 3 'Eletrodo 17 a 24"
  pinMode(MUX4, OUTPUT); // MUX 4 "Eletrodo 25 a 32"
  pinMode(MUX5, OUTPUT); // MUX 5 " Seleção do MUX
 
}


void loop() {
 switch () {
    case 1: 
       //Eletrodo_02
      digitalWrite(MUX1, LOW);   
      digitalWrite(MUX2, HIGH);   
      digitalWrite(MUX3, HIGH);   
      digitalWrite(MUX4, HIGH);   
      digitalWrite(MUX5, LOW);
    
      digitalWrite(S0, HIGH);   
      digitalWrite(S1, LOW);   
      digitalWrite(S2, LOW);   
      digitalWrite(S3, LOW);   
      digitalWrite(S4, LOW);
      break;
   
    case 2: 
      //Eletrodo_03
      digitalWrite(MUX1, LOW);   
      digitalWrite(MUX2, HIGH);   
      digitalWrite(MUX3, HIGH);   
      digitalWrite(MUX4, HIGH);   
      digitalWrite(MUX5, LOW);
      
      digitalWrite(S0, LOW);   
      digitalWrite(S1, HIGH);   
      digitalWrite(S2, LOW);   
      digitalWrite(S3, LOW);   
      digitalWrite(S4, LOW); 
      break;
   
    case 3: 
      //Eletrodo_04
      digitalWrite(MUX1, LOW);   
      digitalWrite(MUX2, HIGH);   
      digitalWrite(MUX3, HIGH);   
      digitalWrite(MUX4, HIGH);   
      digitalWrite(MUX5, LOW);
    
      digitalWrite(S0, HIGH);   
      digitalWrite(S1, HIGH);   
      digitalWrite(S2, LOW);   
      digitalWrite(S3, LOW);   
      digitalWrite(S4, LOW);
      break;
    
    case 4:
      //Eletrodo_05
       digitalWrite(MUX1, LOW);   
       digitalWrite(MUX2, HIGH);   
       digitalWrite(MUX3, HIGH);   
       digitalWrite(MUX4, HIGH);   
       digitalWrite(MUX5, LOW);
      
       digitalWrite(S0, LOW);   
       digitalWrite(S1, LOW);   
       digitalWrite(S2, HIGH);   
       digitalWrite(S3, LOW);   
       digitalWrite(S4, LOW);
      break; 
      
    case 5: 
       //Eletrodo_06
      digitalWrite(MUX1, LOW);   
      digitalWrite(MUX2, HIGH);   
      digitalWrite(MUX3, HIGH);   
      digitalWrite(MUX4, HIGH);   
      digitalWrite(MUX5, LOW);
    
      digitalWrite(S0, HIGH);   
      digitalWrite(S1, LOW);   
      digitalWrite(S2, HIGH);   
      digitalWrite(S3, LOW);   
      digitalWrite(S4, LOW); 
      break; 

    case 6:
      //Eletrodo_07  
      digitalWrite(MUX1, LOW);   
      digitalWrite(MUX2, HIGH);   
      digitalWrite(MUX3, HIGH);   
      digitalWrite(MUX4, HIGH);   
      digitalWrite(MUX5, LOW);
    
      digitalWrite(S0, LOW);   
      digitalWrite(S1, HIGH);   
      digitalWrite(S2, HIGH);   
      digitalWrite(S3, LOW);   
      digitalWrite(S4, LOW); 
    break;
    case 7:
      //Eletrodo_08
       digitalWrite(MUX1, LOW);   
       digitalWrite(MUX2, HIGH);   
       digitalWrite(MUX3, HIGH);   
       digitalWrite(MUX4, HIGH);   
       digitalWrite(MUX5, LOW);
      
       digitalWrite(S0, HIGH);   
       digitalWrite(S1, HIGH);   
       digitalWrite(S2, HIGH);   
       digitalWrite(S3, LOW);   
       digitalWrite(S4, LOW); 
    break;
    case 8:
       //Eletrodo_01
      digitalWrite(MUX1, LOW);   
      digitalWrite(MUX2, HIGH);   
      digitalWrite(MUX3, HIGH);   
      digitalWrite(MUX4, HIGH);   
      digitalWrite(MUX5, LOW);
  
      digitalWrite(S0, LOW);   
      digitalWrite(S1, LOW);   
      digitalWrite(S2, LOW);   
      digitalWrite(S3, LOW);   
      digitalWrite(S4, LOW);
    break; 
    default:
      break;
}
