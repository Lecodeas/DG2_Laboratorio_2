/* -----------------------------------------------
 Universidad del Valle de Guatemala
 IE2023: Programacion de Microcontroladores
 ADC.h
 Autor: Ian Anleu Rivera
 Proyecto: Proyecto 2 Micros 1
 Hardware: ATMEGA328P
 Creado: 24/04/2024
 Ultima modificacion: 22/01/2026
    -----------------------------------------------
*/	


#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>//IO registros
#include <stdint.h> //Lib para enteros

void setupADC(void);
uint16_t fetchADCH(uint8_t channel);

#endif /* ADC_H_ */