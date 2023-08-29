#include <Wire_slave.h>
#include "ad9850.h"
#include "stm32_adc_dual_mode.h"
#include "dft.h"

byte comando =0;

void setup(){ 
  Serial.begin(115200);         // start serial for output
  Wire.begin(0X40);                // join i2c bus with address #4
  Wire.onReceive(dadorecebido); // register event

  ad9850_setup();

 
}

#define REFERENCE_VOLTS   3.3                    // fundo de escala do ADC
#define CHANNELS_PER_ADC  1                      // number of channels for each ADC. Must match values in ADCx_Sequence array below
#define NUM_SAMPLES_MAX   300                     // number of samples for each ADCx. Each channel will be sampled NUM_SAMPLES/CHANNELS_PER_ADC
#define ADC_SMPR          ADC_SMPR_7_5           // when using dual mode, each pair of channels must have same rate. Here all channels have the same
#define PRE_SCALER        RCC_ADCPRE_PCLK_DIV_6  // Prescaler do ADC
#define FAST_INTERLEAVED  false                  // Fast Interleave Mode Flag. Para "dobrar" taxa de amostragem medindo o mesmo canal dos 2 ADCs.
                                                 // Se 'false', habilita "Regular simultaneous mode". Se 'true', habilita "Fast interleaved mode".

// #define GANHO_CORRENTE 355.0 // para Rg=3,3k e Rs=22ohm -> G = (1+50k/Rg)*Rs


uint32 adcbuf[NUM_SAMPLES_MAX+1];  // buffer to hold samples, ADC1 16bit, ADC2 16 bit

// O STM32F103 possui 10 pinos do ADC disponíveis:
// pino A0 (PA0) -> 0 (ADC0)
// ...
// pino A7 (PA7) -> 7 (ADC7)
// pino B0 (PB0) -> 8 (ADC8)
// pino B1 (PB1) -> 9 (ADC9)
// Para "dobrar" taxa de amostragem (FAST_INTERLEAVED true), medir o mesmo canal dos 2 ADCs.
uint8 ADC1_Sequence[]={8,0,0,0,0,0};   // ADC1 channels sequence, left to right. Unused values must be 0. Note that these are ADC channels, not pins  
uint8 ADC2_Sequence[]={9,0,0,0,0,0};   // ADC2 channels sequence, left to right. Unused values must be 0

char comando;
int num_samples = 12;
float freq_sinal  = 50000; // 
float sample_freq = 600000; // 600kSps
int pontos_por_ciclo = 12;

float media1, media2, amplit1, amplit2, phase1, phase2;
void envia_medidas(){
  // medindo valores:
  start_convertion_dual_channel(adcbuf, num_samples);
  wait_convertion_dual_channel();

  // imprimindo valores lidos:
  for(int i=0;i<(num_samples);i++) {
    float volts= ((adcbuf[i] & 0xFFFF) / 4095.0)* REFERENCE_VOLTS;
    float voltss=  (((adcbuf[i] & 0xFFFF0000) >>16) / 4095.0)* REFERENCE_VOLTS;
    
    if(FAST_INTERLEAVED){ // Fast interleaved mode
      /*Serial.print("ADC:");
      Serial.println(voltss); //ADC2 é convertido primeiro... Ver [2], pág 10.
      Serial.print("ADC:");
      Serial.println(volts);*/
    }
    else{ // Regular simultaneous mode
      Serial.print("C1:");
      Serial.print(volts);
      Serial.print("\tC2:");
      Serial.println(voltss);
    }
  }
  Serial.println();
}
void loop(){
  
  if(comando!=0){
    
  }
}


void dadorecebido(int howmany){
  //Wire.available();
  
  comando = Wire.read();   
}
  
void processacomando(){
  
  switch (comando) {

    case 1: // 200Khz 3 pontos
      freq_sinal = 200000;
      ad9850_sendFrequency(freq_sinal);
      num_samples = 3;
      break;
   
    case 2: // 125Khz 48 pontos
      freq_sinal = 125000;
      ad9850_sendFrequency(freq_sinal);
      num_samples = 24;   // 5 ciclos    
      break;
   
    case 3: // 100Khz 6 pontos
      freq_sinal = 100000;
      ad9850_sendFrequency(freq_sinal);
      num_samples = 6;
      break;
    
    case 4: // 50Khz 12 pontos
      freq_sinal = 50000;
      ad9850_sendFrequency(freq_sinal);
      num_samples = 12;
      break; 
      
    default:
      break;
  }
  comando =0;

}



