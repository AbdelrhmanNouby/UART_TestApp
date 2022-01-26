/*
 * UART_TestApp.c
 *
 * Created: 1/24/2022 
 * Author : Abdelrhman Elsawy
 */ 

#include "../MCAL/UART/UART.h"
#include "../MCAL/TIMER0/TIMER0.h"
#include "../ECUAL/LED/LED.h"
#include "../LIB/STRING.h"


/*
 * ECHO app repeat what you sent by terminal 
*/

int main(void)
{
	UART_u8Init();					// initialize UART comm
	TIMER0_u8Init();				// initialize TIMER0 to use delay 
	uint8_t R_Str [256] ;			// array to contain received string 
    while (1) 
    {
		UART_u8ReceiveString(R_Str);				// receive string from terminal
		UART_u8SendString(R_Str);					// send that received string 
		UART_u8SendByte(NEWLINE);					// print newline 
    }
}
