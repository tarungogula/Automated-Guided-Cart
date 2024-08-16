


1 : R R L L
2 : L R L L
3 : L L R R
4 : R L R R

//code to transmit data 
#include <SoftwareSerial.h>
#define rxPin 2
#define txPin 3

SoftwareSerial xbee =  SoftwareSerial(rxPin, txPin);
void setup(){
 Serial.begin(9600);
 pinMode(rxPin, INPUT);
 pinMode(txPin, OUTPUT);
 xbee.begin(9600);
}

void loop(){
 xbee.print('A');
 Serial.println('B'); //
 delay(1000);
}

//code to receive data 
#include <SoftwareSerial.h>
#define rxPin 13
#define txPin 12

SoftwareSerial xbee =  SoftwareSerial(rxPin, txPin);

void setup(){
 pinMode(rxPin, INPUT);
 pinMode(txPin, OUTPUT);
 
 xbee.begin(9600);
 Serial.begin(9600);
 Serial.println("Starting XBee Comunication");
}


void loop(){
  if(xbee.available()){
   char someChar = xbee.read();
  Serial.println(someChar);
  }
 delay(1000);
}

//code to check the joystick 
#include <ezButton.h>

#define VRX_PIN A4
#define VRY_PIN A3
#define SW_PIN A2
#define LEFT_BUTTON 6
#define RIGHT_BUTTON 7

#define LEFT 400
#define RIGHT 800
#define UP 400
#define DOWN 800

ezButton button(SW_PIN);
ezButton buttonL(LEFT_BUTTON);
ezButton buttonR(RIGHT_BUTTON);

int xValue = 0;
int yValue = 0;
int bValue = 0;
int lbValue = 0;
int rbValue = 0;

void setup(){
    Serial.begin(9600);
    button.setDebounceTime(50);
    buttonL.setDebounceTime(50);
    buttonR.setDebounceTime(50);
}

void loop(){

    button.loop();
    buttonL.loop();
    buttonR.loop();

    xValue = analogRead(VRX_PIN);
    yValue = analogRead(VRY_PIN);
    bValue = button.getState();
    lbValue = buttonL.getState();
    rbValue = buttonR.getState();

    if(button.isPressed()){
      Serial.println("pressed");
    }

    if(buttonL.isPressed()){
      Serial.println("left pressed");
    }

    if(buttonR.isPressed()){
      Serial.println("right pressed");
    }

    if(xValue < LEFT)
      Serial.println("left");
    else if(xValue > RIGHT)
      Serial.println("right");
    
    if(yValue < UP)
      Serial.println("up");
    else if(yValue > DOWN)
      Serial.println("down");

    delay(1000);
}

//dynamic object detection with ultra sonic sensor


#include "alphabot_drivers.h"


int value;

void setup() {

  // forward();
  Serial.begin(9600);
}

void loop() {
   value = Distance_test();
   while(value < 15){ //distance in cm
    SetSpeed(0,0);
    forward();
    value = Distance_test();
   }
   
   SetSpeed(20,20);
   forward();
   delay(100);
  
}

//dynamic object detection with ir sensor 

#include "alphabot_drivers.h"


char value;

void setup() {
  init_devices();
  forward();
  Serial.begin(9600);
}

void loop() {
   value = ir_read();
  while(value == 'r' or value == 'l' or value == 'b'){
    SetSpeed(0,0);
    forward();
    value = ir_read();
   }
  
  SetSpeed(70,70);
  forward();
  delay(200);
  
}
