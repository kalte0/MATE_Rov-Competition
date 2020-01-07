#define MOTOR 9
#include <Servo.h>

Servo myservo;
int pot;
int sec; 

long timeThis, timeLast;

void setup() {
  myservo.attach(9);
  pinMode(3, INPUT);
  Serial.begin(9600);
  //  myservo.writeMicroseconds(1500); //neutral signal, shows the motor controller that allesgut.
  delay(2000);
}

void loop() {
  timeThis = millis();
  pot = analogRead(3);
  sec = map(pot, 0, 1023, 1100, 1900); 
if (timeThis - timeLast > 1000) {
  Serial.print(pot); Serial.print('\t'); Serial.println(sec); 
}
myservo.writeMicroseconds(sec); 

}
