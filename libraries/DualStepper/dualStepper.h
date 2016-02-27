#ifndef dualStepper_h
#define dualStepper_h

#include "Arduino.h"

class dualStepper {
  public:
	void Enable (int leftmotor1,int leftmotor2 ,int leftmotor3 ,int leftmotor4 ,int rightmotor1 ,int rightmotor2 ,int rightmotor3 ,int rightmotor4);
	void motorISR();

	void Stop();
	void Forward();
	void Reverse();
	void Left();
	void Right();
	void pitchLeft();
	void pitchRight();
	
	
  private:
	
	int _lhMotorDir = -1;//1=clockwise -1=counterclockwise
	int _rhMotorDir = 1;//1=clockwise -1=counterclockwise
	int _leftmotor1;
	int _leftmotor2;
	int _leftmotor3;
	int _leftmotor4;
	int _rightmotor1;
	int _rightmotor2;
	int _rightmotor3;
	int _rightmotor4;
	
	char _state[32] = {1, 0, 0, 0,
                      1, 1, 0, 0,
                      0, 1, 0, 0,
                      0, 1, 1, 0,
                      0, 0, 1, 0,
                      0, 0, 1, 1,
                      0, 0, 0, 1,
                      1, 0, 0, 1
                      };
int _leftMotorStateIndex = 4; //index increments through state for the lefthand motor
int _rightMotorStateIndex = 4; //index increments through state for the righthand motor
};

extern dualStepper motor;

#endif