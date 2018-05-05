#include <SoftwareSerial.h> 
#include <Servo.h>

SoftwareSerial BT(10,11); //10 RX, 11 TX.

Servo miservo;


char data[100];
int lectura;
float voltaje;
float temperatura;
int posicion;


void setup()
{
  BT.begin(9600); 
  Serial.begin(9600); 
  miservo.attach(5);
  delay(3000);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
}

void loop()
{
  if(BT.available()){
    leerBluetooth();
  }
}


void leerBluetooth(){
  delay(30);
  int contador = 0;
  Serial.println("*** Datos recibidos por bluetooth!!");
  while (BT.available()>0){
    data[contador] = BT.read();
    contador = contador + 1;
  }
  interpretarDatos();
  return;
}

void interpretarDatos(){
  if (data[0] == 'L' && data[1] == 'A'&& data[2] == '1'){
    digitalWrite(2,HIGH);
    Serial.println("Led A encendido");
  }
  else if (data[0] == 'L' && data[1] == 'A' && data[2] == '0'){
    digitalWrite(2,LOW);
    Serial.println("Led A apagado");
  }
  if (data[0] == 'L' && data[1] == 'B'&& data[2] == '1'){
    digitalWrite(3,HIGH);
    Serial.println("Led B encendido");
  }
  else if (data[0] == 'L' && data[1] == 'B' && data[2] == '0'){
    digitalWrite(3,LOW);
    Serial.println("Led B apagado");
  }
  if (data[0] == 'T' && data[1] == 'E' && data[2] == 'M' && data[3] == 'P'){
    lectura = analogRead(A1); //leemos la entrada analoga
    voltaje = (lectura * 5.0)/1023;  //convertimos a voltaje
    temperatura = voltaje * 100; //convertimos a temperatura
    BT.print(temperatura); //enviamos la temperatura al bluetooth
    BT.println("°C"); //enviamos esl signo de grados centigrados
    Serial.println("Comando de temperatura recibido");
    Serial.print("Temperatura enviada: ");
    Serial.println(temperatura);
  }
  if (data[0] == 'P' && data[1] == 'O' && data[2] == 'S'){
    posicion = ((data[3] - 0x30)*100)+((data[4] - 0x30)*10)+(data[5] - 0x30); //convertimos el valor de texto a valor numerico
    if (posicion < 0 || posicion > 180){
      Serial.println("#### Posicion recibida incorrecta! intente de nuevo!");
    }
    else{
      Serial.print("Posicion para el servo recibida: ");
      Serial.println(posicion);
      Serial.print("Moviendo el servo en 3...");
      delay(1000);
      Serial.print(" 2...");
      delay(1000);
      Serial.println(" 1... ");
      delay(1000);
      Serial.println("Servomotor se movio a la posicion indicada!");
      miservo.write(posicion);
      
    }
  }
  //Reiniciamos los datos de data
  data[0] = ' ';
  data[1] = ' ';
  data[2] = ' ';
  data[3] = ' ';
  data[4] = ' ';
  data[5] = ' ';
  return;
}


