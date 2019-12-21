void avanzar(void){
	PORTD &= (0 << Motor1A) & (0 << Motor2A) ;
	OCR0A = 200;
}

void detener(void){
	PORTD &= (0 << Motor1A) & (0 << Motor2A) ;
	OCR0A = 0;
}

void reversa(void){
	PORTD |= (1 << Motor1A) | (1 << Motor2A) ;
	OCR0A = 0;
}

void gira_derecha(){
	PORTD &= (0 << Motor1A) & (0 << Motor2A) ;
	OCR0A = 250;
	PORTD |= (1 << Motor1A) ;
}

void gira_izquierda(){
	PORTD &= (0 << Motor1A) & (0 << Motor2A) ;
	OCR0A = 250;
	PORTD |= (1 << Motor2A) ;
}

void control_motor(int accion){
	switch(accion){
		case '1':
			OCR0A = 150;
		break;
		case '2':
			OCR0A = 200;
		break;
		case '3':
			OCR0A = 250;
		break;
		case 'a':
			avanzar();
		break;
		case 'p':
			detener();
		break;
		case 'i':
			gira_izquierda();
		break;
		case 'd':
			gira_derecha();
		break;
		case 'r':
			reversa();
	}
}