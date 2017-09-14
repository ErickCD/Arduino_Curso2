#include <SD.h>

const int chipSelect = 4;
 
void setup(){
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  digitalWrite(10,HIGH);
  delay(1000);
  if (!SD.begin(chipSelect)){
    Serial.println("Error al leer la tarjeta.");
    return;
  }
}
 
void loop(){
  File dataFile = SD.open("CursoPID.txt", FILE_WRITE);
  if (dataFile) {
    dataFile.println("Curso PID Dominical nivel 2");
    dataFile.println("hola");
    dataFile.println("Arduino");
    dataFile.println("Datos 3");
    dataFile.println("Datos 4");
    dataFile.close();
    Serial.println("Los datos se enviaron al archivo");
  }
  else{
    Serial.println("Error al intentar accesar al archivo!");
  }
  while(true){
  }
}
