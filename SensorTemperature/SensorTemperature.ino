// Comunicacao Serial
// Leio o sensor de temperatura e imprimo a temperatura
// no console

#define SENSOR 0 // define o pin leitura, analogico
#define LED 9 // define o pin de acendimento do LED

int val = 0; // definindo valor de leitura

void setup(){
  pinMode(LED, OUTPUT); // registro o valor do pin do led
  Serial.begin(9600); // registro a velocidade de comunicacao com a porta serial
}

void loop(){
  val = analogRead(SENSOR); // leio o sensor
  digitalWrite(LED,HIGH); // ligo o led
  
  // Calculo para conversao de volts para a temperatura
  float voltage = val * 0.00488;
  // Ajuste da temperatura
  voltage = voltage * 100;
  
  // Envio para a serial o valor da temperatura mais a palavra graus
  Serial.print(voltage); Serial.println(" graus");
  
  delay(500); // delay para a proxima leitura
  digitalWrite(LED,LOW); // desligo o led
  delay(500); // delay para a proxima leitura
}
