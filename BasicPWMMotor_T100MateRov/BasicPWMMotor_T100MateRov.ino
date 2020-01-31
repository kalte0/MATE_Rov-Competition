#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40, Wire);


#define SERVO_FREQ 60 // Analog servos run at ~60 Hz updates

long timeThis, timeLast; 
int pot;
int sec; 

void setup() {
  Serial.begin(9600);
  Serial.println("Let's get iiiit! ~ ");

  pwm.begin(); // p sure this is very much necessary.
  pwm.setOscillatorFrequency(27000000);  // The int.osc. is closer to 27MHz
  pwm.setPWMFreq(SERVO_FREQ); // I wonder if this is completely necessary for this to run, prb keep in juts to make sure. 

pwm.writeMicroseconds(0, 1500);
   delay(6000);
}

void loop() {
  timeThis = millis();
  pot = analogRead(0);
  sec = map(pot, 0, 1023, 1100, 1900);

  if (timeThis - timeLast > 1000) {
    Serial.print(pot); Serial.print('\t'); Serial.println(sec);
  }
  pwm.writeMicroseconds(0 , sec); 

}
