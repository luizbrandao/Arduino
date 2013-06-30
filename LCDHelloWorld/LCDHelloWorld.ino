#include <LiquidCrystal.h> // Importo a biblioteca que usaremos

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // registro os pinos do LCD

void setup(){
  lcd.begin(16, 2); // Numero de colunas e linhas que usaremos
  lcd.print("Hello World"); // Mensagem da primeira linha
}

void loop(){
  lcd.setCursor(0, 1); // Modifico o cursor para a segunda linha
  lcd.print(millis()/1000); // Imprimo a quantidade de segundos que esta ligado
}
