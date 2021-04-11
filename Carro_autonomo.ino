/*
  O circuito:
	- Vcc conectado em +5V
	- GND conectado ao Negativo (Terra)
	- Echo e Trigger conectados na porta digital 8

 */
 
// Define a porta 8 como entrada e saída de dados
const int porta = 8;

void setup() {
  // Ecoa a distância medida na porta serial
  Serial.begin(9600);
}

void loop() {
  // Definição das variáveis
  long duracao, cm;

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
}

long msPARAcm(long ms) {
  // A velicidade do som é 340 m/s ou 29 microsegundos por centímetro.
  // O pulso é enviado e volta, e então descobrimos a nossa distância a um objeto dividindo o sinal por 2.
  return ms / 29 / 2;
}
