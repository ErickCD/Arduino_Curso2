//int numA = 10;
//int numB = 11;
//int numC;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Dentro del loop...");
  delay(1000);
  int x;
  //x = suma();
  x = suma(6, 9);
  Serial.print("valor de X: ");
  Serial.println(x);
  //suma();
  Serial.println("De regreso en el loop");
}

int suma(int num1, int num2){
  int a;
  Serial.println("Entrando a la funcion suma");
  //numC = numA + numB;
  //a = numA + numB;
  a = num1 + num2;
  Serial.print("La suma es: ");
  //Serial.println(numC);
  delay(1000);
  Serial.println("Saliendo de la funcion suma");
  return a;
}
