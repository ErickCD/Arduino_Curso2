#include <SD.h>

const int chipSelect = 4;
File dataFile;
void setup(){
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  digitalWrite(10,HIGH);
  if (!SD.begin(chipSelect)){
    Serial.println("Error al leer la tarjeta.");
    return;
  }
}
 
void loop(){
  if (SD.exists("CursoPID.txt")){
    Serial.println("El Archivo existe!!");
    dataFile = SD.open("CursoPID.txt");
    if (dataFile){
      Serial.println("######## Datos del archivo:");
      while (dataFile.available()){
        Serial.write(dataFile.read());
      }
      dataFile.close();
      Serial.println("######## Fin del archivo");
    }
  }
  else {
    Serial.println("El Archivo NO existe!!");
  }
  while(true){
  }
}
