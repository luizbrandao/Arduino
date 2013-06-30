// Comunicacao Serial
// Leio o sensor de temperatura e imprimo a temperatura
// no console, usando 5v

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
  
  float voltage = val * 5.0;
  voltage /= 1024.0;
 
  Serial.print(voltage); Serial.println(" volts"); // imprimo via porta serial
  
  float temp = (voltage - 0.5) * 100;
  Serial.print(temp); Serial.println(" graus");
  
  delay(500); // delay para a proxima leitura
  digitalWrite(LED,LOW); // desligo o led
  delay(500); // delay para a proxima leitura
}
