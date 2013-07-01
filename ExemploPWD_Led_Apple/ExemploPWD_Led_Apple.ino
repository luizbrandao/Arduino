#define LED 9 // Defino o pino para qual iremos fornecer energia ao LED
int i = 0; // variavel auxiliar

void setup(){
  pinMode(LED, OUTPUT); // Registro o LED
}

void loop(){
  // for para ligar o LED
  for(i = 0; i < 255; i++){
    analogWrite(LED,i);
    delay(10);
  }
  // for para desligar o LED
  for(i = 255; i > 0; i--){
    analogWrite(LED,i);
    delay(10);
  }
}
