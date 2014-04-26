// Coachia
// by Team Francis

#include <Servo.h> 
 
Servo left;
Servo right;
 
void setup() 
{ 
  left.attach(8);  // attaches the servo on pin 9 to the servo object 
  right.attach(9);  // attaches the servo on pin 9 to the servo object 
} 
 
 
void loop() 
{ 
  goLeft(100);
  goRight(100);
  goStraight(200);
  goBack(1000);
  delay(5000);
}

void goLeft(int duration)
{
  left.write(180);
  
  delay(duration);
  
  // Slow down !
  for(int pos = 180; pos > 90; pos-=1)
  {
    left.write(pos);
    delay(15);
  }
}

void goRight(int duration)
{
  right.write(180);
  
  delay(duration);
  
  // Slow down !
  for(int pos = 180; pos > 90; pos-=1)
  {
    right.write(pos);
    delay(15);
  }
}

void goStraight(int duration)
{
  left.write(180);
  right.write(180);
  
  delay(duration);
  
  // Slow down !
  for(int pos = 180; pos > 90; pos-=1)
  {
    left.write(pos);
    right.write(pos);
    delay(15);
  }
}

void goBack(int duration)
{
  left.write(1);
  right.write(1);
  
  delay(duration);
  
  // Slow down !
  for(int pos = 1; pos < 90; pos += 1)
  {
    left.write(pos);
    right.write(pos);
    delay(15);
  }
}
