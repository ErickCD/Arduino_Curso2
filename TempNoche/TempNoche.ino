
#include <SD.h>

const int chipSelect = 4;
File dataFile;

int lectura;
float voltaje;
float temperatura;
char temp[5];
char datos[20];
int contadorTiempo;
int contadorEventos;

void setup(){
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  digitalWrite(10,HIGH);
  if (!SD.begin(chipSelect)){
    Serial.println("Error al leer la tarjeta.");
    return;
  }
  pinMode(5,OUTPUT);
}

void loop(){
  lectura = analogRead(A0);
  voltaje = lectura * (5.0/1023.0);
  temperatura = voltaje * 100.0;
  delay(10);
  contadorTiempo++;
  if (contadorTiempo == 60){
    enviarDato(temperatura);
    contadorEventos++;
    Serial.print("contador de enventos: ");
    Serial.println(contadorEventos);
    contadorTiempo = 0;
  }
  Serial.println(contadorTiempo);
}

void enviarDato (float x){
  dtostrf(x,4,2,temp);
  sprintf(datos,"%02d,%s",contadorEventos,temp);
  if (SD.exists("REGTEMP.CSV")){
    Serial.println("El archivo existe!");
  }
  else{
    Serial.println("El archivo no existe!");
    Serial.println("Creando el archivo PIDExcel.csv...");
    dataFile = SD.open("REGTEMP.CSV", FILE_WRITE);
    dataFile.close();
  }
  dataFile = SD.open("REGTEMP.CSV", FILE_WRITE);
  if (dataFile) {
    dataFile.println(datos);
    dataFile.close();
    Serial.println("Los datos se enviaron al archivo");
  }
  else{
    Serial.println("Error al intentar accesar al archivo!");
  }
  return;
}

