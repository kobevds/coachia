// Coachia
// by Team Francis

#include <IRremote.h>
#include <Servo.h>

int RECV_PIN = 2;

IRrecv irrecv(RECV_PIN);

decode_results results;

#define IR_CODE_FORWARD 3932339327
#define IR_CODE_BACKWARDS 4125814396
#define IR_CODE_TURN_LEFT 4165481122
#define IR_CODE_TURN_RIGHT 2553118498
#define IR_CODE_STOP 1053095749

Servo servoLeft;
Servo servoRight;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  
  servoLeft.attach(8);
  servoRight.attach(9);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    switch(results.value){
      case IR_CODE_FORWARD:
        doForwards();
        break;
      case IR_CODE_BACKWARDS:
        doBackwards();
        break;
      case IR_CODE_TURN_LEFT:
        doLeft();
        break;
      case IR_CODE_TURN_RIGHT:
        doRight();
        break;
      case IR_CODE_STOP:
        doStop();
        break;
    }
    irrecv.resume(); // Receive the next value
  }
}

void doForwards()
{
  servoLeft.writeMicroseconds(1300);
  delay(15);
  servoRight.writeMicroseconds(1700);
  delay(15);
}

void doBackwards()
{
  servoLeft.writeMicroseconds(1700);
  delay(15);
  servoRight.writeMicroseconds(1300);
  delay(15);
}

void doLeft()
{
  servoLeft.writeMicroseconds(1700);
  delay(15);
  servoRight.writeMicroseconds(1700);
  delay(15);
}

void doRight()
{
  servoLeft.writeMicroseconds(1300);
  delay(15);
  servoRight.writeMicroseconds(1300);
  delay(15);
}

void doStop()
{
  servoLeft.writeMicroseconds(1500);
  delay(15);
  servoRight.writeMicroseconds(1500);
  delay(15);
}
