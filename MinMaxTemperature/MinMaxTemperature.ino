#include <LiquidCrystal.h> // Importo a biblioteca que usaremos
#define SENSOR 0 // Defino o pino de entrada para o sensor

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // registro os pinos do LCD

int val = 0; // valor de leitura do sensor
int button = 7;
float min = 0;
float max = 0;
int botao = 0;
int old_botao = 0;
int state = 0;

void setup(){
  lcd.begin(16,2); // Numero de colunas e linhas que iremos usar
  lcd.print("Temperatura"); // Mensagem da primeira Linha
  pinMode(button, INPUT);
}

void loop(){
  val = analogRead(SENSOR); // Leio o valor do sensor
  botao = digitalRead(botao);
  
  float voltage = val * 0.00488; // calculo para saber o valor da temperatura
  voltage = voltage * 100; // Ajuste de temperatura
  
  if(voltage <= min || min == 0){
    min = voltage;
  } else {
    max = voltage;
  }
  
  if((botao == HIGH) && (old_botao == LOW)){
    state = 1 - state;
    delay(10);    
  }
  
  old_botao = botao;
  
  if(state == 1){
    lcd.setCursor(0,0); // Coloco o cursor na segunda linha, coluna 0
    lcd.print("Minima Temp"); // Escrevo a segunda parte da mensagem
    lcd.setCursor(0,1); // Coloco o cursor na segunda linha, coluna 0
    lcd.print(min); // Escrevo o valor da temperatura no Curso
    lcd.setCursor(6,1); // Coloco o cursor na segunda linha, coluna 6
    lcd.print("graus"); // Escrevo a segunda parte da mensagem
  } else {
    lcd.setCursor(0,0); // Coloco o cursor na segunda linha, coluna 0
    lcd.print("Temperatura"); // Escrevo a segunda parte da mensagem
    lcd.setCursor(0,1); // Coloco o cursor na segunda linha, coluna 0
    lcd.print(voltage); // Escrevo o valor da temperatura no Curso
    lcd.setCursor(6,1); // Coloco o cursor na segunda linha, coluna 6
    lcd.print("graus"); // Escrevo a segunda parte da mensagem 
  }
}
