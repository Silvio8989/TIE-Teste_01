#include <Wire_slave.h>
#include "ad9850.h"
#include "stm32_adc_dual_mode.h"
#include "dft.h"

void setup(){ 
  Serial.begin(115200);         // start serial for output
  Wire.begin(0X40);                // join i2c bus with address #4
  Wire.onReceive(receiveEvent); // register event

  ad9850_setup();

}

void loop(){
  delay(100);
}


void receiveEvent(int howMany){
  
    Wire.available();
  int x = Wire.read();   

  switch (x) {

  case 1: // 200Khz 30 pontos
    ad9850_sendFrequency(200000.0);
    Serial.println("Frequencia 200 Khz"); 
     
 
    break;
 
  case 2: // 125Khz 48 pontos
    ad9850_sendFrequency(125000.0);
    Serial.println("Frequencia 125 Khz");       
    break;
 
  case 3: // 100Khz 60 pontos
    ad9850_sendFrequency(100000.0);
    Serial.println("Frequencia 100Khz"); 
    break;
  
  case 4: // 50Khz 120 pontos
    ad9850_sendFrequency(50000.0);
    Serial.println("Frequencia 50 Khz"); 
    break; 
  
  default:
    break;
}
}
