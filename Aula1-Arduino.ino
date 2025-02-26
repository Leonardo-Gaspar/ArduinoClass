// Atribui nomes aos pinos de I/O

#define BT1 8
#define BT2 9
#define LEDgrey 2
#define LEDgreen 3
#define LEDred 4

void setup() {
  //Habilitar comunicação serial (baud rate de 9600 bits/s)
  Serial.begin(9600);

  //Configurar os pinos de I/O
  pinMode(BT1, INPUT);
  pinMode(BT2, INPUT);
  pinMode(LEDgrey, OUTPUT);
  pinMode(LEDgreen, OUTPUT);
  pinMode(LEDred, OUTPUT);
}
/*
Exemplo 1:
Botão BT1:
LOW ----> DESLIGADO -----> LEDgreen piscara em intervalos de 300ms
HIGH ----> LIGADO -----> LEDgrey e LEDred piscarão alternadamente a cada 250ms

*/

void loop() {

  bool statusBT1 = digitalRead(BT1);
  bool statusBT2 = digitalRead(BT2);

  //if(digitalRead(BT1) == HIGH){
  if (statusBT1 == HIGH){
    Serial.println("Botao 1 apertado");
    digitalWrite(LEDgrey, HIGH);
    digitalWrite(LEDred, LOW);
    delay(250);
    digitalWrite(LEDgrey, LOW);
    digitalWrite(LEDred, HIGH);
    delay(250);
  }else{
    digitalWrite(LEDgrey, LOW);
    digitalWrite(LEDgreen, HIGH);
    delay(300);
    digitalWrite(LEDgreen, LOW);
    delay(300);
  }
  if (statusBT2 == HIGH){
    Serial.println("Botao 2 apertado");
    digitalWrite(LEDgreen, LOW);
    digitalWrite(LEDgrey, LOW);
    digitalWrite(LEDred, LOW);
    delay(500);
    digitalWrite(LEDgreen, HIGH);
    digitalWrite(LEDgrey, HIGH);
    digitalWrite(LEDred, HIGH);
    delay(500);
  }
}
