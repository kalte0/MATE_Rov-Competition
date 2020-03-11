#include <Adafruit_LEDBackpack.h>

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40, Wire);

#define SERVO_FREQ 60 // Analog servos run at ~60 Hz updates


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
  pwm.writeMicroseconds(0, 1900);
  delay(3000); 
  pwm.writeMicroseconds(0 ,1100); 
  delay(3000); 
}

