/*
  O circuito:
	- Vcc conectado em +5V
	- GND conectado ao Negativo (Terra)
	- Echo e Trigger conectados na porta digital 8

 */
 
// Define a porta 8 como entrada e saída de dados
const int porta = 8;

const int motor1 = 10; // motor traseiro da esquerda na perspectiva do motorista
const int motor2 = 11; // motor traseiro direto
const int motor3 = 12; // motor frontal esquerdo
const int motor4 = 13; // motor frontal direito

void setup() {
  // Ecoa a distância medida na porta serial
  Serial.begin(9600);
}

void loop() {
  // Definição das variáveis
  char direcao;
  long duracao, cm;

  direcao = 'f'; // front

  //          Opções
  //'front'
  //'stop'
  //'back'
  //'right'
  //'left'

  // O sensor vai emitir um pulso de 2 ou mais microsegundos.
  pinMode(porta, OUTPUT);
  digitalWrite(porta, LOW);
  delayMicroseconds(2);
  digitalWrite(porta, HIGH);
  delayMicroseconds(5);
  digitalWrite(porta, LOW);

  pinMode(porta, INPUT);
  duracao = pulseIn(porta, HIGH);

  // Converte o tempo em espaço
  cm = msPARAcm(duracao); // ms = microsegundos | cm = centìmetro

  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(100);
  /////////////////////////////

  // Faz desviar de obstáculos virando sempre a direita
  if (cm < 10)
  {
    direcao = 'r'; // right
  }

  // Controle dos motores
  if (direcao == 'f')
  {
    pinMode(motor1, OUTPUT);
    digitalWrite(motor1, HIGH);
    
    pinMode(motor2, OUTPUT);
    digitalWrite(motor2, HIGH);
    
    pinMode(motor3, OUTPUT);
    digitalWrite(motor3, HIGH);
    
    pinMode(motor4, OUTPUT);
    digitalWrite(motor4, HIGH);
  }
  if (direcao == 'b') // back
  {

  }
    if (direcao == 's') // stop
  {
    pinMode(motor1, OUTPUT);
    digitalWrite(motor1, LOW);
  
    pinMode(motor2, OUTPUT);
    digitalWrite(motor2, LOW);
  
    pinMode(motor3, OUTPUT);
    digitalWrite(motor3, LOW);
  
    pinMode(motor4, OUTPUT);
    digitalWrite(motor4, LOW);
  }
    if (direcao == 'r')
  {
    pinMode(motor1, OUTPUT);
    digitalWrite(motor1, HIGH);
  
    pinMode(motor2, OUTPUT);
    digitalWrite(motor2, LOW);
  
    pinMode(motor3, OUTPUT);
    digitalWrite(motor3, HIGH);
  
    pinMode(motor4, OUTPUT);
    digitalWrite(motor4, LOW);
  }
    if (direcao == 'l') // left
  {
    pinMode(motor1, OUTPUT);
    digitalWrite(motor1, LOW);
  
    pinMode(motor2, OUTPUT);
    digitalWrite(motor2, HIGH);
  
    pinMode(motor3, OUTPUT);
    digitalWrite(motor3, LOW);
  
    pinMode(motor4, OUTPUT);
    digitalWrite(motor4, HIGH);
  }
  ///////////////////////////////
}

long msPARAcm(long ms) {
  // A velicidade do som é 340 m/s ou 29 microsegundos por centímetro.
  // O pulso é enviado e volta, e então descobrimos a nossa distância a um objeto dividindo o sinal por 2.
  return ms / 29 / 2;
}
