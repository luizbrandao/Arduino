// Exemplo 05: Ligar o led quando o botao e pressionado
// e mantem o led ligado quando o botao e solto
// incluindo o efeito de de-bouncing

#define LED 9 // pin para o led
#define BUTTON 7 // pin para o botao

int val = 0; // guarda o valor do estado do botao
int old_val = 0; // guarda o valoar anterior do botao

int state = 0; // 0 = LED desligado e 1 = LED ligado

int brightness = 128; // Valor do brilho do led
unsigned long startTime = 0; // horario em que o led foi pressionado

void setup(){
  pinMode(LED, OUTPUT); // avisa o arduino sobre o output
  pinMode(BUTTON, INPUT); // avisa o arduino sobre o input
}

void loop(){
  val = digitalRead(BUTTON); // le o valor do botao
  
  // verifica se e uma transicao
  if((val == HIGH) && (old_val == LOW)){
    // muda o estado de on para off ou vice-versa
    state = 1 - state;
    // millis() retorna o valor de tempo de 
    // quando o arduino foi resetado
    startTime = millis();
    // aplica um delay de 10 ms
    delay(10);
  }
  // verifica se o botao foi pressionado
  if((val == HIGH) && (old_val == HIGH)){
    // verifica se foi mais de 500 ms
    if(state == 1 && (millis() - startTime) > 500){
      // incrementa o brilho em mais um
      brightness++;
      // aplica um delay de 10 ms
      delay(10);
      // verifica se o brilho e maior que 255
      if(brightness > 255){
        // caso verdadeiro zera o brilho
        brightness = 0;
      }
    }
  }
  // guarda o valor antigo de val
  old_val = val;
  // verifica o estado
  if(state == 1){
    // caso verdadeiro liga o led
    analogWrite(LED, brightness);
  } else {
    // caso falso desliga o led
    analogWrite(LED,0);
  }
}
