#include <Arduino.h>
#define SLIDER0 0
#define SLIDER1 1
#define SLIDER2 2
#define SLIDER3 3
#define SLIDER4 4
#define SLIDER5 5

int slider0 = 0;
int slider1 = 0;
int slider2 = 0;
int slider3 = 0;
int slider4 = 0;
int slider5 = 0;
bool on = false;



void sendValues(){
  Joystick.sliderLeft(slider0);
  Joystick.sliderRight(slider1);
  Joystick.X(slider2);
  Joystick.Y(slider3);
  Joystick.Z(slider4);
  Joystick.Zrotate(slider5);
}

void readValues(){
  if(on){
  slider0 = analogRead(SLIDER0);
  }
  else{
  slider1 = analogRead(SLIDER0);
  }
  slider2 = analogRead(SLIDER2);
  slider3 = analogRead(SLIDER3);
  slider4 = analogRead(SLIDER4);
  slider5 = analogRead(SLIDER5);
}

void setup() {
  Serial1.begin(9600);
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(13,OUTPUT);
  digitalWrite(13,HIGH);
}

void loop() {

  readValues();
  sendValues();
  on = digitalRead(0);
  Joystick.button(1, digitalRead(0));
  Joystick.button(2, digitalRead(1));

  delay(50);
}
