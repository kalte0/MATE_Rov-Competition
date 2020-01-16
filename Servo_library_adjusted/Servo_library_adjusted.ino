#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVO_FREQ 60 // Analog servos run at ~60 Hz updates

int pot;
int sec; 

long timeThis, timeLast;

void setup() {
  Serial.begin(9600);
 
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);  // The int.osc. is closer to 27MHz
  pwm.setPWMFreq(SERVO_FREQ);
  delay(2000);
}

void loop() {
  timeThis = millis();
  pot = analogRead(3);
  sec = map(pot, 0, 1023, 600, 2200); 
if (timeThis - timeLast > 1000) {
  Serial.print(pot); Serial.print('\t'); Serial.println(sec); 
}
  pwm.writeMicroseconds(0, sec); 
}
