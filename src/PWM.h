//EL PWM con los diferentes ciclos de trabajo cambia las velocidades del motor

void pwm_setup (void)
{
	//Ciclo de trabajo - 255 = 100%
	 OCR0A = 0;

	 //Modo no invertido
	 TCCR0A |= (1 << COM0A1);

	 //Modo Fast PWM
	 TCCR0A |= (1 << WGM01) | (1 << WGM00);

	//CLK sin pre-escalador
	 TCCR0B |= (1 << CS00);
}

void pwm_off(void){
	//Desactiva PWM
	TCCR0A &= (0 << WGM01) & (0 << WGM00);
}
