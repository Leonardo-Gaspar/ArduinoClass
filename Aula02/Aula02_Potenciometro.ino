// Atribui nomes aos pinos de I/O
#define BT1 8
#define BT2 9
#define ledR 2
#define ledW 3
#define ledB 4

int  valor; // 2^16

void setup() {
  // Habilitar comunicação serial (baud rate de 9600 bits/s)
  Serial.begin(9600);  
  // Configurar os pinos de I/O:
  pinMode(BT1, INPUT);
  pinMode(BT2, INPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledW, OUTPUT);
  pinMode(ledB, OUTPUT);
}
void loop() {
    // Conversor analógco Digital (Analog-To-Digital converter)

    valor = analogRead(A2);
    Serial.println(valor);

}