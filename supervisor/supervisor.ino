
// code to transmit data 
// #include <SoftwareSerial.h>
// #define rxPin 2
// #define txPin 3

// SoftwareSerial xbee =  SoftwareSerial(rxPin, txPin);
// void setup(){
//  Serial.begin(9600);
//  pinMode(rxPin, INPUT);
//  pinMode(txPin, OUTPUT);
//  xbee.begin(9600);
// }

// void loop(){
//  xbee.print('A');
//  Serial.println('B'); 
//  delay(1000);
// }

// //code to receive data 
// #include <SoftwareSerial.h>
// #define rxPin 13
// #define txPin 12

// SoftwareSerial xbee =  SoftwareSerial(rxPin, txPin);

// void setup(){
//  pinMode(rxPin, INPUT);
//  pinMode(txPin, OUTPUT);
 
//  xbee.begin(9600);
//  Serial.begin(9600);
//  Serial.println("Starting XBee Comunication");
// }


// void loop(){
//   if(xbee.available()){
//    char someChar = xbee.read();
//   Serial.println(someChar);
//   }
//  delay(1000);
// }

// code to check the joystick 
// #include <ezButton.h>

// #define VRX_PIN A4
// #define VRY_PIN A3
// #define SW_PIN A2
// #define LEFT_BUTTON 6
// #define RIGHT_BUTTON 7

// #define LEFT 400
// #define RIGHT 800
// #define UP 400
// #define DOWN 800

// ezButton button(SW_PIN);
// ezButton buttonL(LEFT_BUTTON);
// ezButton buttonR(RIGHT_BUTTON);

// int xValue = 0;
// int yValue = 0;
// int bValue = 0;
// int lbValue = 0;
// int rbValue = 0;

// void setup(){
//     Serial.begin(9600);
//     button.setDebounceTime(50);
//     buttonL.setDebounceTime(50);
//     buttonR.setDebounceTime(50);
// }

// void loop(){

//     button.loop();
//     buttonL.loop();
//     buttonR.loop();

//     xValue = analogRead(VRX_PIN);
//     yValue = analogRead(VRY_PIN);
//     bValue = button.getState();
//     lbValue = buttonL.getState();
//     rbValue = buttonR.getState();

//     if(button.isPressed()){
//       Serial.println("pressed");
//     }

//     if(buttonL.isPressed()){
//       Serial.println("left pressed");
//     }

//     if(buttonR.isPressed()){
//       Serial.println("right pressed");
//     }

//     if(xValue < LEFT)
//       Serial.println("left");
//     else if(xValue > RIGHT)
//       Serial.println("right");
    
//     if(yValue < UP)
//       Serial.println("up");
//     else if(yValue > DOWN)
//       Serial.println("down");

//     delay(1000);
// }

#include "alphabot_drivers.h"
#include "line_follower.h"


#define NUM_SENSORS 5


int sensorValues[NUM_SENSORS];
Line_follower__main_out _res;
Line_follower__main_mem self;


bool switch_line = false;
int count = 0;

//setting region number
int arena = 1;
unsigned long initialTime = 0;

//variables to store ir values
long rightSensor = 0;
long leftSensor = 0;

//flag to start parking
int parking = 0;

//to store front ir sensor for object detection
int value ;

int t_speed = 0;

unsigned long startTime = millis();
bool threshold = false;


//black node rotations of all regions
char turn[4][5] = {
  "RRLLS",
  "LRLLS",
  "LLRRS",
  "RLRRS"
};

void setup() {
  init_devices();
  pinMode(4, INPUT);  // right pin
  pinMode(8, INPUT);  // left pin
  forward();
  Serial.begin(9600);
  
}

void loop(){
  AnalogRead(sensorValues);
  Line_follower__main_step(sensorValues[0], sensorValues[1], sensorValues[2], sensorValues[3], sensorValues[4],switch_line,threshold, &_res, &self);
  SetSpeed(_res.v_l, _res.v_r);


        //dynamic object detection
        value = ir_read();
          while(value == 'r' or value == 'l' or value == 'b'){
            SetSpeed(0,0);
            forward();
            value = ir_read();
          }

        //dynamic object detection with ultra sonic sensor
        // value = Distance_test();
        // while(value < 15){ //distance in cm
        //   SetSpeed(0,0);
        //   forward();
        //   value = Distance_test();
        // }
               

        //flag for smooth transition
        if(millis() - startTime > 12000)
            threshold = true;

          
          
        //non parking code
        if(parking == 0){
          
          //left rotating bot on axis
          if(_res.dir == 2){
            SetSpeed(100, 100);
            left();
            delay(30);
          }

          //right rotating bot on axis
          else if(_res.dir == 3){
            SetSpeed(100, 100);
            right();
            delay(30);
          }

          //condition to check if bot reached line switching area
          else if(_res.dir == 4){
            switch_line = true;

            //transition logic for region 2
            if(arena == 1 ){
              SetSpeed(65, 45);
              forward();
              delay(100);

              SetSpeed(0,0);
              forward();
              delay(500);
              t_speed = 45;
            }
            
            //transition logic for region 3
            else if(arena == 2){

              SetSpeed(65, 45);
              forward();
              delay(100);

              SetSpeed(0,0);
              forward();
              delay(500);
              t_speed = 50;
            }
            
            //transition logic for region 1 and 4
              else if(arena == 0 or arena == 3){
              SetSpeed(45, 0);
              backward();
              delay(350);

              SetSpeed(40, 30);
              forward();
              delay(1000);
            }
          }

          //checking if bot is in black line
          else if(_res.dir == 5){

          //logic for node detection
          if(sensorValues[1] < 750 && sensorValues[3] < 750){
            char node = turn[arena][count];

            //code to take left rotation at node
            if(node == 'L'){
              count++;
              
              SetSpeed(40, 40);
              if(count == 4)
                SetSpeed(50, 50);
              forward();
              delay(170);
              if(count==4)
                delay(80);
              
              
              SetSpeed(70, 70); 
              left();
              delay(200);
              if(count==4)
                delay(200);
              

              SetSpeed(40, 40);
              forward();
              delay(300);

              
            }
            
            //code to take right rotation at node
            else if(node == 'R'){
              count++;
              SetSpeed(40, 40);
              forward();
              delay(250);

              SetSpeed(70, 70); 
              right();
              delay(200);

              SetSpeed(40, 40);
              forward();
              delay(200);
              
            }
            //code to set parking flag
            else if(node == 'S'){
              count++;
              parking = 1;
              SetSpeed(30, 30);
              beep_on();
              forward();
              beep_off();
              delay(100);
              initialTime = millis();
            }
            
          }
          forward();
          }
        else {
                  forward();
            }
  }


        //logic for parking
          if(parking == 1){

              //time to cover one parking slot
              if (millis() - initialTime <= (1800)) {

                //reading ir sensor data
                if (digitalRead(4) == LOW)
                    rightSensor = rightSensor + 1;
                if (digitalRead(8) == LOW)
                      leftSensor = leftSensor + 1;

            } else {
              SetSpeed(0, 0);
              forward();
              delay(500);

              //parking right side, if slot is free
              if (rightSensor == 0) {
                SetSpeed(29, 52);
                backward();
                delay(1100);
                SetSpeed(0, 0);
                forward();
                exit(0);
              } 
              //parking left side , if slot is free
              else if (leftSensor == 0) {

                SetSpeed(52, 29);
                backward();
                delay(1100);
                SetSpeed(0, 0);
                forward();
                exit(0);
              } 
              //if both slots are not empty, restart timer
              else {
                initialTime = millis();
                rightSensor = 0;
                leftSensor = 0;
                
              }
            }

      }
  
}

