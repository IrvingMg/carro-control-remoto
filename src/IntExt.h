void int_ext0_setup(){
	//Cualquier cambio logico
	EICRA  |= (0 << ISC10) | (1 << ISC00);
	//Habilita interrupcion 0
	EIMSK |= (1 << INT0);
}