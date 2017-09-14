/*	Programa para mover un motor a pasos con arduino y el driver 28BYJ-48
	Hecho por Daniel Rodríguez para el curso de Arduino nivel 2
	Septiembre 2017
*/

//:: Definicion de las onnexiones del motor
#define m1 8
#define m2 9
#define m3 10
#define m4 11

long contadorDePasos;
int velocidad = 2;

void setup(){
	pinMode(m1, OUTPUT);
	pinMode(m2, OUTPUT);
	pinMode(m3, OUTPUT);
	pinMode(m4, OUTPUT);
}

void loop()
{
	vueltas(0,1);
	delay(2000);
	vueltas(1,1);
	delay(2000);
}

void vueltas(int sentido, float numVueltas){
	float vueltas = numVueltas * 510;
    int contadorDeVueltas;
    while (contadorDeVueltas != vueltas){
    	if (sentido == 1){
    		girarReloj();
    		contadorDeVueltas++;
    	}
    	if (sentido == 0){
    		girarEncontraReloj();
    		contadorDeVueltas++;
    	}
    } 
	return;
}

void girarReloj(void){
	digitalWrite(m1,HIGH);
	digitalWrite(m2,LOW);
	digitalWrite(m3,LOW);
	digitalWrite(m4,LOW);
	delay(velocidad);
	digitalWrite(m1,LOW);
	digitalWrite(m2,HIGH);
	digitalWrite(m3,LOW);
	digitalWrite(m4,LOW);
	delay(velocidad);
	digitalWrite(m1,LOW);
	digitalWrite(m2,LOW);
	digitalWrite(m3,HIGH);
	digitalWrite(m4,LOW);
	delay(velocidad);
	digitalWrite(m1,LOW);
	digitalWrite(m2,LOW);
	digitalWrite(m3,LOW);
	digitalWrite(m4,HIGH);
	delay(velocidad);
	contadorDePasos++;
	return;
}

void girarEncontraReloj(void){
	digitalWrite(m1,LOW);
	digitalWrite(m2,LOW);
	digitalWrite(m3,LOW);
	digitalWrite(m4,HIGH);
	delay(velocidad);
	digitalWrite(m1,LOW);
	digitalWrite(m2,LOW);
	digitalWrite(m3,HIGH);
	digitalWrite(m4,LOW);
	delay(velocidad);
	digitalWrite(m1,LOW);
	digitalWrite(m2,HIGH);
	digitalWrite(m3,LOW);
	digitalWrite(m4,LOW);
	delay(velocidad);
	digitalWrite(m1,HIGH);
	digitalWrite(m2,LOW);
	digitalWrite(m3,LOW);
	digitalWrite(m4,LOW);
	delay(velocidad);
	contadorDePasos++;
	return;
}
