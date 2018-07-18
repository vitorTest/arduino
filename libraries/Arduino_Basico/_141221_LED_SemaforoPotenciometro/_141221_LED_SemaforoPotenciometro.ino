int tempoDeEspera; 
int sinalVermelho = 7;
int sinalAmarelo = 5;
int sinalVerde = 3;
int potenciometro = 2;
int contador = 1;
float constante = 0.0048875855327468;

void setup() {
  pinMode(sinalVermelho, OUTPUT);
  pinMode(sinalAmarelo, OUTPUT);
  pinMode(sinalVerde, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  tempoDeEspera = analogRead(potenciometro);//o tempo de espera é igual a leitura analogica do potenciometro
  Serial.println(potenciometro, DEC);
  float valor = constante*tempoDeEspera;
  Serial.println(valor, DEC);
  Serial.println(contador);
  contador++;
  /*Daqui para baixo é comportamento de um sinal de trânsito 
  em delay(tempoDeEspera), vai sempre pegar o valor do tempo de espera, que por sua vez pega os valores do potenciômetro*/
  
  digitalWrite(sinalVermelho, HIGH); //Acende sinal vermelho e espera um tempinho 
  delay(tempoDeEspera);   
  
  digitalWrite(sinalAmarelo, HIGH); // Acende sinal amarelo, enquanto o vermelho também está ligado e espera
  delay(tempoDeEspera); 
  
  //Nas quatro linhas a seguir: acende verde, apaga vermelho, apaga amarelo e espera
  digitalWrite(sinalVerde, HIGH); 
  digitalWrite(sinalVermelho, LOW);
  digitalWrite(sinalAmarelo, LOW); 
  delay(tempoDeEspera); 
  
  //Acende amarelo e apaga verde e espera
  digitalWrite(sinalAmarelo, HIGH);
  digitalWrite(sinalVerde, LOW); 
  delay(tempoDeEspera);
  
  //Apaga amarelo ao "mesmo tempo" que acende o vermelho no início do loop
  digitalWrite(sinalAmarelo, LOW); 
}

