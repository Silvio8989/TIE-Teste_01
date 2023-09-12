#include <Wire.h>

#define NUM_ELETRODOS 8
byte num_eletrodos_usados = 8; // mudar para: int num_eletrodos_usados = NUM_ELETRODOS


typedef union{
  float floatingPoint;
  byte binary[4];
} binaryFloat;


float amplitudes[NUM_ELETRODOS];
float fases[NUM_ELETRODOS];


// avisando aos eletodos para iniciar nova leitura
void inicia_leitura_eletrodos(){
  for (byte n = 0; n < num_eletrodos_usados; n++) wire_envia_byte(0X51+n,'i');
}

void pega_leitura_de_um_eletrodo(byte endereco, float *amplitude, float *fase){
  Wire.requestFrom(endereco, 8);

  binaryFloat amplitude_lida, fase_lida;
  for(byte idx = 0; idx < 4; idx++) amplitude_lida.binary[idx] = Wire.read();
  
  for(byte idx = 0; idx < 4; idx++) fase_lida.binary[idx] = Wire.read();

  *amplitude = amplitude_lida.floatingPoint;
  *fase = fase_lida.floatingPoint;
}


void pega_leitura_eletrodos(){
  for (byte n = 0; n < num_eletrodos_usados; n++){
    float ampl, pha;
    pega_leitura_de_um_eletrodo(0X51+n, &ampl, &pha);
    amplitudes[n] = ampl;
    fases[n] = pha;
  }
  
}

void setup()
{ 
  Wire.begin(); // join i2c bus (address optional for master)
  delay(300);  // aguarda 300ms para os slaves ligarem
  wire_envia_byte(0X40,1); // Inciando gerador em 200kHz
  Serial.begin(115200);
}

void loop()
{
  if (Serial.available() > 0) {
    processacomandoserial();
  }
}

void processacomandoserial(){
  int comandoserial = Serial.read();
   
   switch (comandoserial) {
    case '1': // 200Khz 6 pontos (6 pts = 2 ciclos)
      wire_envia_byte(0X40,1); // Inciando gerador em 200kHz
      wire_envia_byte(0X51,1); // Avisando eletrodo1 da nova frequencia
      wire_envia_byte(0X52,1); // Avisando eletrodo2 da nova frequencia
      wire_envia_byte(0X53,1); // Avisando eletrod03 da nova frequencia
      wire_envia_byte(0X54,1); // Avisando eletrodo4 da nova frequencia
      wire_envia_byte(0X55,1); // Avisando eletrodo5 da nova frequencia
      wire_envia_byte(0X56,1); // Avisando eletrodo6 da nova frequencia
      wire_envia_byte(0X57,1); // Avisando eletrodo7 da nova frequencia
      wire_envia_byte(0X58,1); // Avisando eletrodo8 da nova frequencia
      Serial.println("200Khz 6 pontos (6 pts = 2 ciclos)");
      break;
   
    case '2': // 125Khz 24 pontos (24pts = 5 ciclos)
      wire_envia_byte(0X40,2); // Inciando gerador em 125kHz    
      wire_envia_byte(0X51,2); // Avisando eletrodo da nova frequencia
      wire_envia_byte(0X52,2); // Avisando eletrodo2 da nova frequencia
      wire_envia_byte(0X53,2); // Avisando eletrod03 da nova frequencia
      wire_envia_byte(0X54,2); // Avisando eletrodo4 da nova frequencia
      wire_envia_byte(0X55,2); // Avisando eletrodo5 da nova frequencia
      wire_envia_byte(0X56,2); // Avisando eletrodo6 da nova frequencia
      wire_envia_byte(0X57,2); // Avisando eletrodo7 da nova frequencia
      wire_envia_byte(0X58,2); // Avisando eletrodo8 da nova frequencia
      Serial.println("125Khz 24 pontos (24pts = 5 ciclos)");
      break;
   
    case '3': // 100Khz 12 pontos (12 pts = 2 ciclos)
      wire_envia_byte(0X40,3); // Inciando gerador em 100kHz
      wire_envia_byte(0X51,3); // Avisando eletrodo da nova frequencia
      wire_envia_byte(0X52,3); // Avisando eletrodo2 da nova frequencia
      wire_envia_byte(0X53,3); // Avisando eletrod03 da nova frequencia
      wire_envia_byte(0X54,3); // Avisando eletrodo4 da nova frequencia
      wire_envia_byte(0X55,3); // Avisando eletrodo5 da nova frequencia
      wire_envia_byte(0X56,3); // Avisando eletrodo6 da nova frequencia
      wire_envia_byte(0X57,3); // Avisando eletrodo7 da nova frequencia
      wire_envia_byte(0X58,3); // Avisando eletrodo8 da nova frequencia
      Serial.println("100Khz 12 pontos (12 pts = 2 ciclos)");
      break;
    
    case '4': // 50Khz 24 pontos (24 pts = 2 ciclos)
      wire_envia_byte(0X40,4); // Inciando gerador em 50kHz
      wire_envia_byte(0X51,4); // Avisando eletrodo da nova frequencia
      wire_envia_byte(0X52,4); // Avisando eletrodo2 da nova frequencia
      wire_envia_byte(0X53,4); // Avisando eletrod03 da nova frequencia
      wire_envia_byte(0X54,4); // Avisando eletrodo4 da nova frequencia
      wire_envia_byte(0X55,4); // Avisando eletrodo5 da nova frequencia
      wire_envia_byte(0X56,4); // Avisando eletrodo6 da nova frequencia
      wire_envia_byte(0X57,4); // Avisando eletrodo7 da nova frequencia
      wire_envia_byte(0X58,4); // Avisando eletrodo8 da nova frequencia
      Serial.println("50Khz 24 pontos (24 pts = 2 ciclos)");
      break; 
      
    case 'i': // inicia medidas nos eletrodos
      inicia_leitura_eletrodos();
      Serial.println("Leitura dos eletrodos iniciada...");
      break; 
      
    case 'v': // pega valores lidos dos eletrodos
      pega_leitura_eletrodos();
      Serial.println("Valores lidos:");
      
      for (byte n = 0; n < num_eletrodos_usados; n++){
        Serial.print("\t");
        Serial.print(amplitudes[n]);
        Serial.print("\t");
        Serial.print(fases[n]);
        Serial.print("\t");
      }
      Serial.println();
      break; 
      
    default:
      break;
  }
}

void wire_envia_byte(byte endereco, byte com) {
    Wire.beginTransmission(endereco);
    Wire.write(com);
    Wire.endTransmission();    
}
