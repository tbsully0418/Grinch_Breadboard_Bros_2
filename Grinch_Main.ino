#include <Servo.h>


Servo houseW;
Servo houseE;
Servo houseC;
Servo tree;
bool notStolenW=true;
bool notStolenE=true;
bool notStolenC=true;
bool notStolenT=true;
const int buttonPinW = 2; 
const int buttonPinE = 3; 
const int buttonPinC = 4; 
const int buttonPinT = 5; 
const int buttonPinR=6;



int buttonStateW = 0;
int buttonStateE = 0;
int buttonStateC = 0;
int buttonStateT = 0;
int buttonStateR=0;

void setup() 
{
  houseW.attach(13);
  houseE.attach(12);
  houseC.attach(11);
  tree.attach(10);
  pinMode(buttonPinW, INPUT);
  pinMode(buttonPinE, INPUT);
  pinMode(buttonPinC, INPUT);
  pinMode(buttonPinT, INPUT);
  pinMode(buttonPinR,INPUT);
  houseW.write(0);
  houseE.write(0);
  houseC.write(0);
  tree.write(0);
}

void loop() {
  // read the state of the pushbutton value:
  buttonStateW = digitalRead(buttonPinW);
  buttonStateE = digitalRead(buttonPinE);
  buttonStateC = digitalRead(buttonPinC);
  buttonStateT = digitalRead(buttonPinT);
  buttonStateR = digitalRead(buttonPinR);
 

  
  if ((buttonStateW == HIGH)&&notStolenW) 
  {
    houseW.write(180);
    notStolenW=false;
  } 

  if ((buttonStateE == HIGH)&&notStolenE) 
  {
    houseE.write(180);
    notStolenE=false;
  } 

  if ((buttonStateC == HIGH)&&notStolenC) 
  {
    houseC.write(180);
    notStolenC=false;
  } 

  if ((buttonStateT == HIGH)&&notStolenT) 
  {
    tree.write(180);
    notStolenT=false;
  } 

  if(buttonStateR==HIGH)
  {
    if(!notStolenW)
    {
      houseW.write(0);
      notStolenW=true;
    }
    if(!notStolenE)
    {
      houseE.write(0);
      notStolenE=true;
    }
    if(!notStolenC)
    {
      houseC.write(0);
      notStolenC=true;
    }
    if(!notStolenT)
    {
      tree.write(0);
      notStolenT=true;
    }
    
  }
}
