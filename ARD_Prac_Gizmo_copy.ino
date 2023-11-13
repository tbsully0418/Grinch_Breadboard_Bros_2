#include <Servo.h>

const int buttonPin = 2;  // the number of the pushbutton pin
Servo test;
bool isStolen1=true;

int buttonState = 0;  // variable for reading the pushbutton status

void setup() 
{
  test.attach(10);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if ((buttonState == LOW)&&isStolen1) 
  {
    test.write(180);
    isStolen1=false;
  } 
  else 
  {
    test.write(0);
  }
}
