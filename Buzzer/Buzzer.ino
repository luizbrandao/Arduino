void setup(){
  // Seto qual pin ira sair o son
  pinMode(8,OUTPUT);
}

void loop(){
  // Entonacao do som
  tone(8,2093,4);
  // Pausa
  delay(1000);
  // Corto a entonacao
  noTone(10);
  // Pausa
  delay(1000);
}
