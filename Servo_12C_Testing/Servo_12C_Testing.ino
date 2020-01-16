#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40, Wire);

#define SERVOMIN  300 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX 450  // This is the 'maximum' pulse length count (out of 4096)
#define USMIN  1200 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  1800 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 60 // Analog servos run at ~60 Hz updates

uint8_t servonum = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("8 channel Servo test!");

  pwm.begin();
  pwm.setOscillatorFrequency(27000000);  // The int.osc. is closer to 27MHz
  pwm.setPWMFreq(SERVO_FREQ);

pwm.writeMicroseconds(0, 1500); 
   delay(3000);
}

void loop() {
  pwm.writeMicroseconds(0, 1900); 
  delay(3000); 
  pwm.writeMicroseconds(0 ,1100); 
  delay(3000); 
}

