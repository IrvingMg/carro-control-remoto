#define Motor1A PD5
#define Motor2A PD7
#define PWMOut PD6

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include "IntExt.h"
#include "ADC.h"
#include "PWM.h"
#include "USART.h"
#include "Timer.h"
#include "Motor.h"
#include "LCD.h"

//Apagado por default
int encendido = 0;

void system_setup(){
	DDRD |= (1 << Motor1A) | (1 << Motor2A);
	DDRD |= (1 << PWMOut);
	timer_setup();
	adc_setup();
	pwm_setup();
	usart_setup();
}

void system_off(){
	timer_off();
	adc_off();
	pwm_off();
	usart_off();
}

int main(void)
{
	//Configuracion de interrupcion externa
	int_ext0_setup();
	sei();
	
	//Inicializa pantalla
	LCD_init();
	LCD_write_string(20,0,"Apagado");
	
    while (1) 
    {
    }
}


ISR(INT0_vect){
	encendido = !encendido;
	
	if(encendido){
		LCD_clear();
		system_setup();	
	}else{
		system_off();
		LCD_clear();
		LCD_write_string(20,0,"Apagado");
	}
}

ISR(USART_RX_vect){
	int accion = UDR0;

	control_motor(accion);
}

ISR(TIMER1_COMPA_vect){
	
	//Lee valor de ADC
	int luz = adc_read();
	
	//Convierte entero a cadena
	char valor_luz[12];
	sprintf(valor_luz, "%d", luz);
	
	//Desactiva timer para escribir en pantalla
	timer_off();
	
	//Borra pantalla y escribe los nuevos valores
	LCD_clear();
	LCD_write_string(10,0,"Intensidad");
	if(luz > 200){
		LCD_write_string(25,10,"Alta");	
	}else{
		if(luz > 100){
			LCD_write_string(25,10,"Media");	
		}else{
			LCD_write_string(25,10,"Baja");	
		}
	}
	LCD_write_string(30,20, valor_luz);
	
	//Activa timer
	timer_setup();
	
	//Transmite valor
	usart_transmitir(luz);
}


