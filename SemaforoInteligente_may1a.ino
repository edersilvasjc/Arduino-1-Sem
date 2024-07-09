//Declarando a variáveis
const int redCar = 5;
const int ylwCar = 7;
const int grnCar = 9;
const int redPed = 11;
const int grnPed = 13;
int botao01 = 2;
int botao02 = 3;
long tempoLed = 0;
const int buzina = 4;
long tpAnterior=0; //temporizador amarelo piscante
long tp=100000;  //temporizador amarelo piscante


// Definindo os led's com saida e botão como entrada
void setup()
{
  pinMode(redCar, OUTPUT);
  pinMode(ylwCar, OUTPUT);
  pinMode(grnCar, OUTPUT);
  pinMode(redPed, OUTPUT);
  pinMode(grnPed, OUTPUT);
  pinMode(botao01,INPUT);
  pinMode(botao02,INPUT);
  pinMode(buzina, OUTPUT);
}

void loop()
{
  //chamado função ligar semáforo
  ligaSemaforo();
  
  //Semáforo após 23h
  if(millis()>= tpAnterior + tp){
    tpAnterior = millis();
    
    //Piscar Semáforo
    for (int x=0; x<30; x++){
      digitalWrite(grnCar, LOW);
      digitalWrite(ylwCar, HIGH);
      digitalWrite(redPed, HIGH);
      delay(300);
      digitalWrite(ylwCar, LOW);
      digitalWrite(redPed, LOW);
      delay(300); 
    }
  }
  else{
    
    if (digitalRead(botao01) == 0) //var contadora de acionamento
  {
   	acendeLed(3000);
   
  } else if (digitalRead(botao02) == 0)
  {
   	acendeLed(7000);
  }
   //tempo 40 s + incremento dessa var contadora
}
}

// Função acende led verde carro e led vermelho para pedestre
void ligaSemaforo()
{
  digitalWrite(redCar, LOW);
  digitalWrite(ylwCar,LOW);
  digitalWrite(grnCar, HIGH);
  digitalWrite(redPed, HIGH);
  digitalWrite(grnPed, LOW);
}

// Função com um argumento para controlar o semáforo
void acendeLed(int tempo){
  
 // Semaforo carro amarelo acesso pedestre vermelho
  delay(2000);
  	digitalWrite(redCar, LOW);
  	digitalWrite(ylwCar,HIGH);
  	digitalWrite(grnCar, LOW);
  	digitalWrite(redPed, HIGH);
  	digitalWrite(grnPed, LOW);
  	delay(3000);
  
  // Semaforo carro vermelho pedestre verde
  digitalWrite(redCar, HIGH);
  digitalWrite(ylwCar, LOW);
  digitalWrite(grnCar, LOW);
  digitalWrite(redPed, LOW);
  digitalWrite(grnPed, HIGH);
  delay(tempo);
  
   // Pisca a luz verde dos PEDESTRES
  for (int x=0; x<15; x++) {
    digitalWrite(grnPed, LOW);
    digitalWrite(redPed, HIGH);
    digitalWrite(buzina, HIGH);
    delay(300);
    digitalWrite(redPed, LOW);
    digitalWrite(buzina, LOW);
    delay(300);
  }
}
