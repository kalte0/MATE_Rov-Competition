#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  300 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX 450  // This is the 'maximum' pulse length count (out of 4096)
#define USMIN  1200 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  1800 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 60 

uint8_t servonum = 0;
void setup() {
  Serial.begin(9600);
  Serial.println("8 channel Servo test!");

  pwm.begin();
