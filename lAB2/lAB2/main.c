/* -----------------------------------------------
 Universidad del Valle de Guatemala
 IE3054: Electrónica Digital 2
 main.c
 Autor: Ian Anleu Rivera
 Proyecto: Nombre
 Hardware: ATMEGA328P
 Creado: 22/01/2026
 Ultima modificacion: 22/01/2026
    -----------------------------------------------
*/

//HEADER FILES
#define F_CPU 160000000 //F cpu en 16 Mhz
#include <avr/io.h> // IO regs
#include <util/delay.h> //Delays
#include <stdint.h> //Lib para enteros
#include <stdio.h> //funciones de C

//LIBRERÍAS PROPIAS
#include "ADC.h"
#include "lcd.h"

//VARIABLES valor adc, conversion a voltaje
uint16_t v_P1 = 0;
uint32_t Volt_P1 = 0;
uint16_t v_P2 = 0;
uint32_t Volt_P2 = 0;
//Posiblemente usar un array de chars para los caracteres de LCD (16 bit + null)
char disp[17];

 int main(void)
 {
     //SETUP LCD y ADC
 	lcd_setup();
 	setupADC();
 	
 	//SETUP UART
 	
     while (1) 
     {
 		//leer adc en P1
 		v_P1 = fetchADCH(0); //Channel 0 es P1
 		_delay_ms(5);
 		//Convertir a voltaje
 		Volt_P1 = (uint32_t)v_P1 * (5000UL/1023UL); //UL para mantener el formato Unsigned 16 bits
 		//leer adc en P2
 		v_P2 = fetchADCH(1); //Channel 1 es P2
 		_delay_ms(5);
 		//convertir a voltaje
 		Volt_P2 = (uint32_t)v_P2 * (5000UL/1023UL); //UL para mantener el formato Unsigned 16 bits
 		//Limpiar pantalla
 		lcd_clear();
 		//Reset Cursor
 		lcd_cursor(0,0); //Origen
 		//Headers
 		lcd_writestring("P1"); //Todos los headers Organizados
 		//Cursor Linea 2
 		lcd_cursor(1,0); //Fila 2 para display de datos
 		//Escribir Valores (investigar formatos) en el array
 		snprintf(disp,sizeof(disp),"%lu.%03lu",Volt_P1/1000,Volt_P1%100);
 		//snprintf(disp,sizeof(disp),"%4u",v_P1);
 		//Desplegar el string formado
 		lcd_writestring(disp);
 		//Esperar un tiempo para otra lectura
 		_delay_ms(30);
     }
 }
