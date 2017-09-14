void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
}

void loop() {
  relevadorOn();
  delay(1000);
  relevadorOff();
  delay(1000);
}

void relevadorOn(void){
  digitalWrite(2, HIGH);
  return;
}

void relevadorOff(void){
  digitalWrite(2, LOW);
  return;
}

