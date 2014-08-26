#include <LiquidCrystal.h> // Importo a biblioteca que usaremos
#define SENSOR 0 // Defino o pino de entrada para o sensor
#define BUZZER 8// Defino o pino do Buzzer
#define LED 9 // Led Vermelho
#define LED2 10 // Led Verde

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // registro os pinos do LCD

int val = 0; // valor de leitura do sensor

void setup(){
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(LED2, OUTPUT);
  lcd.begin(16,2); // Numero de colunas e linhas que iremos usar
  lcd.print("Temperatura"); // Mensagem da primeira Linha
}

void loop(){
  val = analogRead(SENSOR); // Leio o valor do sensor
  
  float voltage = val * 0.00488; // calculo para saber o valor da temperatura
  voltage = voltage * 100; // Ajuste de temperatura
  
  if(voltage < 22){
    tone(8,2093,4);
    delay(1000);
    noTone(10);
    delay(1000);
    digitalWrite(LED, HIGH); // Ligo o led Vermelho
  } else {
    digitalWrite(LED2, HIGH); // Ligo o led Verde
  }
  
  lcd.setCursor(0,1); // Coloco o cursor na segunda linha, coluna 0
  lcd.print(voltage); // Escrevo o valor da temperatura no Curso
  lcd.setCursor(6,1); // Coloco o cursor na segunda linha, coluna 6
  lcd.print("graus"); // Escrevo a segunda parte da mensagem
  delay(1000);        // Delay de um segundo, para melhor imprimir as informacoes
}
