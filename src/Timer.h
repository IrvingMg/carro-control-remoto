//Para obtener el Timer en 1 seg se realiza preescalador/ (frecuencia de oscilador/contador)

void timer_setup(void){
	
	//Periodo de 1s
	OCR1A = 15624;
	
	//Modo de operacion 4 - CTC con maximo en OCR1A
	TCCR1B |=   (1 << WGM12);
	
	//Prescalador en 1024
	TCCR1B |= (1 << CS12) | (0 << CS11) |(1 << CS10);
	
	//Habilitar interrupcion por comparacion
	TIMSK1 |= (1 << OCIE1A);
	
	// Limpia OC1A
	TCCR1A |= (1 << COM1A1);
	
}

void timer_off(void){
	//Modo de operacion 0 - Normal
	TCCR1B &=   (0 << WGM12);
	
	//Prescalador en 1024
	TCCR1B &= (0 << CS12) & (0 << CS11) & (0 << CS10);
	
	//Deshabilitar interrupcion por comparacion
	TIMSK1 &= (0 << OCIE1A);
	
	// Limpia OC1A
	TCCR1A &= (0 << COM1A1);
}
