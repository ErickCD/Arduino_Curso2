void setup() {
  pinMode(9, OUTPUT);

}

void loop() {
  tone(9, 6500);
  delay(1000);
  noTone(9);
  digitalWrite(9, HIGH);
  delay(1000);
}
