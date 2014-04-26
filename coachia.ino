// Coachia
// by Team Francis

#include <Servo.h>

Servo servoLeft;
Servo servoRight;

void setup()
{
  servoLeft.attach(8);
  servoRight.attach(9);
}

void loop()
{
  goLeft(1000);
  delay(1000);
  goRight(1000);
  delay(1000);
  goStraight(2000);
  delay(1000);
  goBack(2000);
  delay(1000);
}

void goLeft(int duration)
{
  servoLeft.writeMicroseconds(1700);
  servoRight.writeMicroseconds(1700);
  delay(duration);
  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);
}

void goRight(int duration)
{
  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1300);
  delay(duration);
  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);
}

void goStraight(int duration)
{
  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1700);
  delay(duration);
  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);
}

void goBack(int duration)
{
  servoLeft.writeMicroseconds(1700);
  servoRight.writeMicroseconds(1300);
  delay(duration);
  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);
}
