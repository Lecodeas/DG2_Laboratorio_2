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

//LIBRERÍAS PROPIAS

//VARIABLES valor adc, conversion a voltaje
//Posiblemente usar un array de chars para los caracteres de LCD (16 bit + null)

int main(void)
{
    //SETUP LCD y ADC
	//SETUP UART
    while (1) 
    {
		//leer adc en P1
		//convertir a voltaje
		//leer adc en P2
		//convertir a voltaje
		//Limpiar pantalla
		//Reset Cursor
		//Headers
		//Cursor Linea 2
		//Escribir Valores (investigar formatos) en el array
		//Desplegar el string formado
		//Esperar un tiempo para otra lectura
    }
}

