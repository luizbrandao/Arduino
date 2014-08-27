#include <dht11.h>
#include <LiquidCrystal.h>
#include <Ultrasonic.h>

#define echoPin 13 //Pino 13 recebe o pulso do echo
#define trigPin 10 //Pino 10 envia o pulso para gerar o echo
#define DHT11PIN 7

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // registro os pinos do LCD
Ultrasonic ultrasonic(10,13);
dht11 DHT11;

void setup(){
  lcd.begin(16,2); // Numero de colunas e linhas que iremos usar
  
  pinMode(echoPin, INPUT); // define o pino 13 como entrada (recebe)
  pinMode(trigPin, OUTPUT); // define o pino 10 como saida (envia)
}


void loop(){
  digitalWrite(trigPin, LOW);
  // delay de 2 microssegundos
  delay(2);
  //seta o pino 12 com pulso alto "HIGH" ou ligado ou ainda 1
  digitalWrite(trigPin, HIGH);
  //delay de 10 microssegundos
  delayMicroseconds(10);
  //seta o pino 12 com pulso baixo novamente
  digitalWrite(trigPin, LOW);
  // função Ranging, faz a conversão do tempo de
  //resposta do echo em centimetros, e armazena
  //na variavel distancia
  int distancia = (ultrasonic.Ranging(CM));
  lcd.print("                ");
  lcd.setCursor(0,0); // Coloco o cursor na primeira linha, coluna 0
  lcd.print("Distancia em CM"); // Escrevo um texto qualquer
  
  lcd.setCursor(0,1); // Coloco o cursor na segunda linha, coluna 0
  lcd.print("                ");
  lcd.setCursor(0,1); // Coloco o cursor na segunda linha, coluna 0
  lcd.print(distancia); // Escrevo o valor da distancia no Curso*/
  
  delay(2000);
  
  int chk = DHT11.read(DHT11PIN);
  switch (chk)
  {
    case 0: Serial.println("OK"); break;
    case -1: Serial.println("Checksum error"); break;
    case -2: Serial.println("Time out error"); break;
    default: Serial.println("Unknown error"); break;
  }
  
  
  lcd.setCursor(0,0); // Coloco o cursor na primeira linha, coluna 0
  lcd.print("                ");
  lcd.setCursor(0,0); // Coloco o cursor na primeira linha, coluna 0
  lcd.print("Hum: "); // Escrevo um texto qualquer
  lcd.setCursor(6,0); // Coloco o cursor na primeira linha, coluna 6
  lcd.print((float)DHT11.humidity, 2);
  
  
  lcd.setCursor(0,1);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print("Temp: ");
  lcd.setCursor(6,1);
  lcd.print((float)DHT11.temperature,2);
  
  delay(2000);
}
