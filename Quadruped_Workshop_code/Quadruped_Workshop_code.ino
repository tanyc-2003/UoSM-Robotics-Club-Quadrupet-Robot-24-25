#include <Adafruit_PWMServoDriver.h>
#include <Wire.h>
#include "Quadruped_parameters.h"

// create an instance of the 'Adafruit_PWMServoDriver' class named pwm.
// default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();


// declaring global variables for later use
// calibration settings for the servo when using the Adafruit_PWMServoDriver library
#define MIN_PULSE_WIDTH 110
#define MAX_PULSE_WIDTH 625
#define FREQUENCY 60
#define interval 100

// servos name
#define FL1 0
#define FL2 1
#define FR1 2
#define FR2 3
#define BL1 4
#define BL2 5
#define BR1 6
#define BR2 7

//HC06 name and password
String btName = "QuadrupedPrototype";
String btPin = "1111";


// the setup loop will run once
void setup() {
  //set up data rate in bit per second for serial data communication
  Serial.begin(9600);

  // setup PCA8650 16 channel servo controller
  pwm.begin(); //initialise pwm
  pwm.setPWMFreq(FREQUENCY); // Analog servos run at ~60 Hz updates

  // setup hc06 bluetooth module
  // change name & pin of hc06 bluetooth module
  Serial.print("AT+NAME" + btName);
  delay(1000);

  Serial.print("AT+PIN" + btPin);
  delay(1000);

  // go to resting position
  rest();
}


//the void loop will run forever until it is stoped intentionally
void loop() {
  // A non-blocking approach to read from the serial buffer
  if (Serial.available() > 0) {
    // Read incoming serial data until a newline is received
    String inputString = Serial.readStringUntil('\n');

    // Check if the string is not empty
    if (inputString.length() > 0) {
      // Parse the input string into an integer
      int inputMovement = inputString.toInt();

      // execute respective function according to the input command
      switch (inputMovement) {
        case 0:
          rest();
          break;
        case 1:
          moveForward();
          break;
        case 2:
          moveBackward();
          break;
        case 3:
          turnLeft();
          break;
        case 4:
          turnRight();
          break;
        default:
          // Consider adding a response for an unrecognized command
          break;
      }

      // After processing the command, flush the serial to clear any pending data
      Serial.flush();
    }

    // Command acknowledgment feedback to the sender
    // to synchronize command sending and robot action - prevent the command overflow
    Serial.println("ok");
  }

}


// map angle to min & max pw for pwm.setPWM function
void setServo(int servo, int angle) {
  int duty;
  duty = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  pwm.setPWM(servo, 0, duty);
}



/////////////////////////////////// MOVEMENTS OF QUADRUPED /////////////////////////////////////////////////


// function for quadruped to be in resting position
void rest() {

  setServo(FL2, FL2_up);
  setServo(BR2, BR2_up);
  setServo(FL1, FL1_center);
  setServo(BR1, BR1_center);
  delay(interval);
  setServo(FL2, FL2_center);
  setServo(BR2, BR2_center);
  delay(interval);
  setServo(FR2, FR2_up);
  setServo(BL2, BL2_up);
  setServo(FR1, FR1_center);
  setServo(BL1, BL1_center);
  delay(interval);
  setServo(FR2, FR2_center);
  setServo(BL2, BL2_center);

}

// function for quadruped to move foward
void moveForward() {

  setServo(FL2, FL2_up);
  setServo(BR2, BR2_up);
  delay(interval);
  setServo(FR1, FR1_CW);
  setServo(BL1, BL1_CCW);
  delay(interval);
  setServo(FL2, FL2_center);
  setServo(BR2, BR2_center);
  delay(interval);
  setServo(FR2, FR2_up);
  setServo(BL2, BL2_up);
  setServo(FR1, FR1_center);
  setServo(BL1, BL1_center);
  delay(interval);
  setServo(FL1, FL1_CCW);
  setServo(BR1, BR1_CW);
  delay(interval);
  setServo(FR2, FR2_center);
  setServo(BL2, BL2_center);
  delay(interval);
  setServo(FL2, FL2_up);
  setServo(BR2, BR2_up);
  setServo(FL1, FL1_center);
  setServo(BR1, BR1_center);
  delay(interval);
  setServo(FL2, FL2_center);
  setServo(BR2, BR2_center);

}

// function for quadruped to move backward
void moveBackward() {

  setServo(FL2, FL2_up);
  setServo(BR2, BR2_up);
  delay(interval);
  setServo(FR1, FR1_CCW);
  setServo(BL1, BL1_CW);
  delay(interval);
  setServo(FL2, FL2_center);
  setServo(BR2, BR2_center);
  delay(interval);
  setServo(FR2, FR2_up);
  setServo(BL2, BL2_up);
  setServo(FR1, FR1_center);
  setServo(BL1, BL1_center);
  delay(interval);
  setServo(FL1, FL1_CW);
  setServo(BR1, BR1_CCW);
  delay(interval);
  setServo(FR2, FR2_center);
  setServo(BL2, BL2_center);
  delay(interval);
  setServo(FL2, FL2_up);
  setServo(BR2, BR2_up);
  setServo(FL1, FL1_center);
  setServo(BR1, BR1_center);
  delay(interval);
  setServo(FL2, FL2_center);
  setServo(BR2, BR2_center);

}

// function for quadruped to turn left
void turnLeft() {

  setServo(FL2, FL2_up);
  setServo(BR2, BR2_up);
  delay(interval);
  setServo(FR1, FR1_CW);
  setServo(BL1, BL1_CW);
  delay(interval);
  setServo(FL2, FL2_center);
  setServo(BR2, BR2_center);
  delay(interval);
  setServo(FR2, FR2_up);
  setServo(BL2, BL2_up);
  setServo(FR1, FR1_center);
  setServo(BL1, BL1_center);
  delay(interval);
  setServo(FR2, FR2_center);
  setServo(BL2, BL2_center);

}

// function for quadruped to turn right
void turnRight() {

  setServo(FR2, FR2_up);
  setServo(BL2, BL2_up);
  delay(interval);
  setServo(FL1, FL1_CCW);
  setServo(BR1, BR1_CCW);
  delay(interval);
  setServo(FR2, FR2_center);
  setServo(BL2, BL2_center);
  delay(interval);
  setServo(FL2, FL2_up);
  setServo(BR2, BR2_up);
  setServo(FL1, FL1_center);
  setServo(BR1, BR1_center);
  delay(interval);
  setServo(FL2, FL2_center);
  setServo(BR2, BR2_center);

}
