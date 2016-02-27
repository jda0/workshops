/*
 * Dual stepper motor control for 2 wheeled robots example arduino progam.
 * 
 * This program takes in 8 inputs, 4 for each stepper motor and sets the speed of the stepper motor rotation.
 * The stepper motor rotational speed cannot be changed using the dualStepper library.
 * 
 * All avaible library functions are here in this progarm.
 * 
 * 
 * 
 */

#include <dualStepper.h>
#define leftmotor1 2
#define leftmotor2 3
#define leftmotor3 4
#define leftmotor4 5
#define rightmotor1 6
#define rightmotor2 7
#define rightmotor3 8
#define rightmotor4 9

void setup() {
  dualStepperMotors.dualEnable(leftmotor1,leftmotor2,leftmotor3,leftmotor4,rightmotor1,rightmotor2,rightmotor3,rightmotor4);
}

void loop() {
  dualStepperMotors.stopMotors(); //both motors stop
  delay(1000);
  dualStepperMotors.forwards();   //both motors move the robot forwards
  delay(1000);
  dualStepperMotors.reverse();    //both motors move the robot backwards
  delay(1000);
  dualStepperMotors.rotateRight();//robots rotates right on the spot
  delay(1000);
  dualStepperMotors.rotateLeft(); //robots rotates left on the spot
  delay(1000);
  dualStepperMotors.pitchRight(); //right motor turns off and the left motor rotates the robot
  delay(1000);
  dualStepperMotors.pitchLeft();  //left motor turns off and the right motor rotates the robot
  delay(1000);

}
