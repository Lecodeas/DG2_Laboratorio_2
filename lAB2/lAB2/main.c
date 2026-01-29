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
uint16_t Vent_P1 = 0;
uint16_t Vdec_P1 = 0;
uint16_t v_P2 = 0;
//Posiblemente usar un array de chars para los caracteres de LCD (16 bit + null)
char displ1[17];
char displ2[17];  //Opté por usar un array por línea para el LCD
//Contador de UART
uint16_t contadorUART = 0;
//Buffer para UART
char bufferUART[40];
//Manejo de un caracter
char car;

int main(void)
{
//SETUP LCD y ADC
lcd_setup();
setupADC();
 	
//SETUP UART
UART_setup(9600); //El Baud rate es de 9600 para serial con computadora
 	
while (1) 
{
	//leer adc en P1
	v_P1 = fetchADCH(0); //Channel 0 es P1
	_delay_ms(2);
	//leer adc en P2
	v_P2 = fetchADCH(1); //Channel 1 es P2
	
	//Convertir V_P1 a voltaje
	Volt_P1 = (uint32_t)v_P1 * (5000UL/1023UL); //UL para mantener el formato Unsigned 16 bits
	//Voltaje entero y decimal
	Vent_P1 = Volt_P1 / 1000;
	Vdec_P1 = (Volt_P1 % 1000)/10;
	
	// Leer el Serial
	
	if (UART_listo()){
		car = UART_readChar();
		if (c == '+')  //Si es + se añade al contador, si es - se resta.
			contadorUART++;
		else if (c == '-')
			contadorUART--;
	}
	
	//Escribir a Computadora
	snprintf(bufferUART, sizeof(bufferUART), "P1=%u  P2=%u\r\n", v_P1, v_P2);
	UART_writeString(bufferUART); //El buffer me sirve para almacenar antes de desplegar
	
	//Limpiar pantalla
	lcd_clear();
	
	//Reset Cursor
	lcd_cursor(0,0); //Origen
	//Headers
	snprintf(displ1, sizeof(displ1),("P1    P2  CNT "))
	snprintf(displ2, sizeof(displ2),("P1    P2  CNT "))
	
	//Cursor Linea 2
	lcd_cursor(1,0); //Fila 2 para display de datos
	//Escribir Valores (investigar formatos) en el array
	snprintf(disp,sizeof(disp),"%u.%02u %4u",Vent_P1,Vdec_P1,v_P2);
	
	//Desplegar el string formado
	lcd_writestring(disp);
	//Esperar un tiempo para otra lectura
	_delay_ms(30);
}
