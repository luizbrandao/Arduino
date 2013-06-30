#include <LiquidCrystal.h> // Importo a biblioteca que usaremos
#define SENSOR 0 // Defino o pino de entrada para o sensor

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // registro os pinos do LCD

int val = 0; // valor de leitura do sensor

void setup(){
  lcd.begin(16,2); // Numero de colunas e linhas que iremos usar
  lcd.print("Temperatura"); // Mensagem da primeira Linha
}

void loop(){
  val = analogRead(SENSOR); // Leio o valor do sensor
  
  float voltage = val * 0.00488; // calculo para saber o valor da temperatura
  voltage = voltage * 100; // Ajuste de temperatura
  
  lcd.setCursor(0,1); // Coloco o cursor na segunda linha, coluna 0
  lcd.print(voltage); // Escrevo o valor da temperatura no Curso
  lcd.setCursor(6,1); // Coloco o cursor na segunda linha, coluna 6
  lcd.print("graus"); // Escrevo a segunda parte da mensagem 
}
