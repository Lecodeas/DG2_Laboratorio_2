/* -----------------------------------------------
 Universidad del Valle de Guatemala
 IE2023: Programacion de Microcontroladores
 ADC.c
 Autor: Ian Anleu Rivera
 Proyecto: Proyecto 2 Micros 1
 Hardware: ATMEGA328P
 Creado: 24/04/2024
 Ultima modificacion: 22/01/2024
 -----------------------------------------------
 */

#include "ADC.h"

uint8_t valoradc;

void setupADC(void){
	//Digital disable
	DIDR0 = 0;
	DIDR0 |= (1<<ADC0D) | (1<<ADC1D); //ADC0 POT1 y ADC1 POT2
	//Setup general
	ADMUX = (1<<REFS0); //Vcc ref | Just. Der.
	ADCSRA = 0;
	ADCSRA |= (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0); //Presc. 128 (125kHz)
	ADCSRA |= (1<<ADEN); // Enable
}
uint16_t fetchADCH(uint8_t channel){
	ADMUX = (ADMUX & 0xF0) | (channel & 0x0F); //Clear de MUX bits y selección de canal
	ADCSRA |= (1<<ADSC); //Inicio de conversión
	while (ADCSRA & (1<<ADSC)); //Bucle hasta que termine la conversión
	
	return ADC;
}