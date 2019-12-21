void usart_setup()
{
	//Habilita transmisor y receptor
	UCSR0B |= (1 << RXEN0) | (1 << TXEN0);
	
	//Habilita interrupcion por fin de recepcion
	UCSR0B |= (1 << RXCIE0);
	
	//Baudrate en 9600 para frecuencia de 16MHz
	UBRR0 = 103;
	
	//Modo asincrono de USART
	UCSR0B |= ( 0 << UMSEL01) | (0 << UMSEL00);
	
	//Sin bit de paridad
	UCSR0C |= (0 << UPM01) | (0 << UPM00);
	
	//Un bit de paro
	UCSR0C |= (0 << USBS0);
	
	//Tamaño de los datos en 8 bits
	UCSR0B |= (0 << UCSZ02);
	UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);
}

void usart_transmitir(char dato){
	while( !(UCSR0A & (1 << UDRE0)) );
	UDR0 = dato;
}

char usart_recibir(){
	while( !(UCSR0A & (1 << RXC0)) );
	return UDR0;
}

void usart_off(void){
	//Deshabilita transmisor y receptor
	UCSR0B &= (0 << RXEN0) & (0 << TXEN0);
	//Deshabilita interrupcion por fin de recepcion
	UCSR0B &= (0 << RXCIE0);
}