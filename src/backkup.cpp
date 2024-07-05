// #include <Arduino.h>
// #include <Servo.h>
// #include <Ultrasonic.h>


// int PIN_SERVO = 6;
// int PIN_GREEN_LED = 4;
// int PIN_BLUE_LED = 2;
// int PIN_BUTTON = 8;
// int ULTRASONIC_PIN_ECHO = 13;
// int ULTRASONIC_PIN_TRIG = 12;

// Servo servo;
// Ultrasonic ultrasonic(ULTRASONIC_PIN_TRIG, ULTRASONIC_PIN_ECHO);

// int distance; //variável inteira

// void setupLeds() {
//   pinMode(PIN_GREEN_LED, OUTPUT);
//   pinMode(PIN_BLUE_LED, OUTPUT);
//   // digitalWrite(PIN_GREEN_LED, HIGH);
//   // digitalWrite(PIN_BLUE_LED, HIGH);
// }

// void setupServo() {
//   servo.attach(PIN_SERVO);
// }

// void setupUltraSonic() {
//   pinMode(ULTRASONIC_PIN_TRIG, OUTPUT);
//   pinMode(ULTRASONIC_PIN_ECHO, INPUT);
// }

// void setup() {
//   Serial.begin(9600); 
//   pinMode(PIN_BUTTON, INPUT_PULLUP);

//   setupLeds();
//   setupUltraSonic();
//   setupServo();
// }

// void hcsr04() {
//   digitalWrite(ULTRASONIC_PIN_TRIG, LOW); //seta o pino 12 com um pulso baixo "low"
//   delayMicroseconds(2); //intervalo de 2 microssegundos
//   digitalWrite(ULTRASONIC_PIN_TRIG, HIGH); //seta o pino 12 com pulso alto "high"
//   delayMicroseconds(10); //intervalo de 10 microssegundos
//   digitalWrite(ULTRASONIC_PIN_TRIG, LOW); //seta o pino 12 com pulso baixo "low" novamente
//   distance = (ultrasonic.read()); //função ranging, faz a conversão para centimetros, e armazena na variavel "distance"
//   // delay(500); //intervalo de 500 milissegundos
// }

// void loop() {
//   hcsr04();
//   int pinButtonValue = digitalRead(PIN_BUTTON);
//   digitalWrite(PIN_GREEN_LED, pinButtonValue == LOW ? HIGH : LOW);
//   // digitalWrite(PIN_BLUE_LED, pinButtonValue == LOW ? HIGH : LOW);

//   if (distance < 10) {
//     Serial.write("Distancia menor que 10cm");
//     digitalWrite(PIN_BLUE_LED, HIGH);
//   } else {
//     digitalWrite(PIN_BLUE_LED, LOW);
//   }


//   if (pinButtonValue == LOW) {
//     servo.write(0);
//   } else {
//     servo.write(90);
//   }

//   delay(100);

// }
