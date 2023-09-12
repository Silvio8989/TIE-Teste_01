#include <Wire_slave.h>
#include "ad9850.h"

byte comando =0;

void setup(){ 
  Wire.begin(0X40);                // join i2c bus with address #4
  Wire.onReceive(dadorecebido); // register event
  ad9850_setup(); 
  ad9850_sendFrequency(50000);
}

void loop(){
  if(comando!=0){
    processacomando();
  }
}

void dadorecebido(int howmany){
  comando = Wire.read();   
}
  
void processacomando(){
  switch (comando) {
    case 1: // 200Khz 3 pontos
      ad9850_sendFrequency(200000);
      break;
   
    case 2: // 125Khz 48 pontos
      ad9850_sendFrequency(125000);    
      break;
   
    case 3: // 100Khz 6 pontos
      ad9850_sendFrequency(100000);
      break;
    
    case 4: // 50Khz 12 pontos
      ad9850_sendFrequency(50000);
      break; 
      
    default:
      break;
  }
  comando =0;
}



