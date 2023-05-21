#include <Servo.h> 
//inclui a bilbioteca Servo para que suas funções possam ser usadas para controlar um servomotor

long readUltrasonicDistance(int triggerPin, int echoPin)//função do sensor
{
  pinMode(triggerPin, OUTPUT); // configura o pino Trig do sensor como saída 
  digitalWrite(triggerPin, LOW); // define o pino trigger do sensor para 0
  delayMicroseconds(2); // tempo em segundo para ativar a função 
  
  digitalWrite(triggerPin, HIGH);// define o pino trigger do sensor para 1
  delayMicroseconds(2); // tempo em segundo para ativar 
  
  digitalWrite(triggerPin, LOW); // define o pino trigger do sensor para 0
  pinMode(echoPin, INPUT); //define o pino Echo do sensor como entrada
  
  return pulseIn(echoPin, HIGH); // define o pino Echo do sensor para 1
}

Servo servo_5; //Cria uma variavel para o servo motor

void setup()
{
  pinMode(11, OUTPUT); // define o pino 11 de saida
  pinMode(9, OUTPUT); // define o pino 9 de saida
  servo_5.attach(5);//Define que servo sera ligado no pino entre parenteses da placa arduino

}

void loop()
{
  if (0.01723 * readUltrasonicDistance(7, 6) <= 70) { //condição para acionar os leds
    digitalWrite(11, HIGH);// se a distancia estiver dentro do especificado liga os leds
    
  } else {
    digitalWrite(11, LOW); // se nao mantem os leds apagados
  }
  if (0.01723 * readUltrasonicDistance(4, 3) <= 50) { //condição para acionar o Servo Motor
    servo_5.write(90); // aciona o servo motor a 90 graus se estiver dentro da distancia especificada
  } else {
    servo_5.write(0); // se nao mantem o servo na posição zero, ou retorna a posição 0
  }
  delay(2); // tempo de delay para realizar apos a condição
}
