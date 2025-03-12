// Atribui nomes aos pinos de I/O
#define BT1 8
#define BT2 9
#define ledR 2
#define ledW 3
#define ledB 4

bool statusBT1;
int contador;

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
/*
Exemplo 1
Botão BT1:
LOW -----> desligado ----> ledW piscará em intervalos de 300ms.
HIGH ---->    ligado ----> ledR e ledB piscarão alternadamente a cada 500ms.
*/
void loop() {

  statusBT1 = digitalRead(BT1);
  delay(100);

  if(statusBT1 == HIGH){
    contador++;
    Serial.print("Valor do contador:");
    Serial.println(contador);
    piscaRB();
  }
  else{
    digitalWrite(ledR, LOW);
    digitalWrite(ledW, HIGH);
    delay(300);
    digitalWrite(ledW, LOW);
    delay(300);    
  }
}
void piscaRB(){
    digitalWrite(ledB, HIGH);
    digitalWrite(ledR, LOW);
    delay(250);
    digitalWrite(ledR, HIGH);
    digitalWrite(ledB, LOW);
    delay(250);
  }

