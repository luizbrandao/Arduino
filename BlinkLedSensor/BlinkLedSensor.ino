// Pisca Led apartir de uma taxa especifica
// lida atraves do entrada analogica
#define LED 9 // defino o valor da saida de energia para o led

int val = 0; // valor do pin onde sera feita a leitura do sensor

void setup(){
  pinMode(LED,OUTPUT); // registro o pin de saida de energia
}

void loop(){
  val = analogRead(0); // Leio o valor do sensor no pin 0
  
  digitalWrite(LED, HIGH); // Ligo o led
  
  delay(val); // delay por tempo igual ao lido no sensor
  
  digitalWrite(LED, LOW); // Desligo o led
  
  delay(val); // delay por tempo igual ao lido no sensor
}
