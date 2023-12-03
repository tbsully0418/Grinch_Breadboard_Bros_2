/*
Project: Grinch, Once Upon an Ardunio

Team: Breadboard Bros 2
Members: Hunter Weiland & Theodore Sullenberger

Description: The code for our Grinch Project including buttons that allow the Grinch to steal from houses and a button that returns the stolen goods.
*/

#include <Servo.h>

// Declaration Zone

// Variabels Representing Each Servo one for each house and oone for the tree.

Servo houseW;  // W stands for west or left if looking at project.        
Servo houseE;  // E stands for east or right if looking at project
Servo houseC;  // C Stands for center or middle house
Servo tree;

// Bools to tell if the Grinch has stolen from a certain area or not
bool notStolenW=true;
bool notStolenE=true;
bool notStolenC=true;
bool notStolenT=true;  // T stands for Tree

// Assigning each button & the LED a pin on the arduino (small numbers)
const int buttonPinW = 2; 
const int buttonPinE = 3; 
const int buttonPinC = 4; 
const int buttonPinT = 5; 
const int buttonPinR=6;    // R stands for return or reverse
const int ledPin=7;

// the int that tells if a button is pressed or not
int buttonStateW = 0;
int buttonStateE = 0;
int buttonStateC = 0;
int buttonStateT = 0;
int buttonStateR=0;

// code ran instantly at start
void setup() 
{
  // attaching each servo to a pin on ardunio (large numbers)
  houseW.attach(13);
  houseE.attach(12);
  houseC.attach(11);
  tree.attach(10);

  //telling ardunio whether each pin is an input or output
  pinMode(buttonPinW, INPUT);
  pinMode(buttonPinE, INPUT);
  pinMode(buttonPinC, INPUT);
  pinMode(buttonPinT, INPUT);
  pinMode(buttonPinR,INPUT);
  pinMode(ledPin,OUTPUT);

  // start off by making sure each house is on xmas side
  houseW.write(0);
  houseE.write(0);
  houseC.write(0);
  tree.write(0);
}

//run at all times
void loop() 
{
  // read the state of the pushbutton value:
  buttonStateW = digitalRead(buttonPinW);
  buttonStateE = digitalRead(buttonPinE);
  buttonStateC = digitalRead(buttonPinC);
  buttonStateT = digitalRead(buttonPinT);
  buttonStateR = digitalRead(buttonPinR);

  // whos always happy so light the who happiness meter at all times
  digitalWrite(ledPin,HIGH);

  // the code for the buttons that turns a house around to stolen side and sets the stolen to bool to match
  
  //House W
  if ((buttonStateW == HIGH)&&notStolenW) 
  {
    houseW.write(180);
    notStolenW=false;
  } 
  // House E
  if ((buttonStateE == HIGH)&&notStolenE) 
  {
    houseE.write(180);
    notStolenE=false;
  } 
  // House C
  if ((buttonStateC == HIGH)&&notStolenC) 
  {
    houseC.write(180);
    notStolenC=false;
  } 
  // Tree
  if ((buttonStateT == HIGH)&&notStolenT) 
  {
    tree.write(180);
    notStolenT=false;
  } 

  // the   code for the return button. makes sure house is stolen from before turing it.
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
