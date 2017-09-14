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
  if (SD.exists("PIDEXCEL.CSV")){
    Serial.println("El archivo existe!");
  }
  else{
    Serial.println("El archivo no existe!");
    Serial.println("Creando el archivo PIDExcel.csv...");
    dataFile = SD.open("PIDEXCEL.CSV", FILE_WRITE);
    dataFile.close();
  }
  dataFile = SD.open("PIDEXCEL.CSV", FILE_WRITE);
  if (dataFile) {
    dataFile.print("Valor A,");
    dataFile.println("Valor B");
    dataFile.print("1A,");
    dataFile.println("1B");
    dataFile.print("2A,");
    dataFile.println("2B");
    dataFile.print("2A,");
    dataFile.println("2B");
    dataFile.close();
    Serial.println("Los datos se enviaron al archivo");
  }
  else{
    Serial.println("Error al intentar accesar al archivo!");
  }
  while(true){
  }
}
