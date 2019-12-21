//La lectura de ADC debe iniciarse cada segundo de forma automatica
//Al finalizar la lectura se genera una interrupcion

void adc_setup (void)
{
	// Set the ADC input to PC1/ADC1
	ADMUX |= (1 << MUX0);
	ADMUX |= (1 << ADLAR);
	
	//Voltaje de referencia AVCC
	ADMUX |= (1 << REFS0);
	
	//Habilita ADC
	ADCSRA |= (1 << ADEN);
	
	//Habilita auto disparo
	//ADCSRA |= (1 << ADATE);
	
	//Habilita interrupcion por fin de conversion
	//ADCSRA |= (1 << ADIE);
	
	// Set the prescaler to clock/128
	ADCSRA |= (1 << ADPS2) |(1 << ADPS1) | (1 << ADPS0);
	
	//Sobreflujo Timer1
	//ADCSRB |= (1 << ADTS2) | (1 << ADTS1);
	
}

void adc_off(void){
	//Deshabilita ADC
	ADCSRA &= (0 << ADEN);
}

int adc_read (void)
{
	//Inicia conversion
	ADCSRA |= (1 << ADSC);
	
	//Espera a finalizar la lectura
	while (ADCSRA & (1 << ADSC));
	
	return ADCH;
}