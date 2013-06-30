int button = 7; // pin para leitura de quando o botao esta pressionado
int led = 13; // pin de saida de energia
int val = 0; // Estado do botao no caso desligado
int state = 0;
int old_val = 0;

void setup(){
  pinMode(led, OUTPUT); // Setando valores do led
  pinMode(button, INPUT); // Setando valores do botao
}

void loop(){
  val = digitalRead(button); // lendo os valores do botao
  
  if((val == HIGH) && (old_val == LOW)){
    state = 1 - state;
    delay(10);
  }
  
  old_val = val;
  
  // Verifico se esta precionado
  if(state == 1){
    // caso sim liga o led
    digitalWrite(led, HIGH);
  } else {
    // caso nao desliga o led
    digitalWrite(led, LOW);
  }
}
