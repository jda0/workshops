/*
*	dualStepper.h - Library for controlling 228BYJ-48 stepper motors
*	Created by The Makron, August 1st, 2015
*
*/

#include "Arduino.h"
#include "dualStepper.h"

dualStepper motor;

//this sets up the left and right motor outputs and timer1 for the pulse duration of the stepper motors
void dualStepper::Enable(int leftmotor1,int leftmotor2 ,int leftmotor3 ,int leftmotor4 ,int rightmotor1 ,int rightmotor2 ,int rightmotor3 ,int rightmotor4){
	//Sets user defined left motor pins as outputs
	pinMode(leftmotor1,OUTPUT);
	pinMode(leftmotor2,OUTPUT);
	pinMode(leftmotor3,OUTPUT);
	pinMode(leftmotor4,OUTPUT);
	//Sets user defined right motor pins as outputs
	pinMode(rightmotor1,OUTPUT);
	pinMode(rightmotor2,OUTPUT);
	pinMode(rightmotor3,OUTPUT);
	pinMode(rightmotor4,OUTPUT);
	
	//passes motor pin numbers to private
	_leftmotor1=leftmotor1;
	_leftmotor2=leftmotor2;
	_leftmotor3=leftmotor3;
	_leftmotor4=leftmotor4;
	_rightmotor1=rightmotor1;
	_rightmotor2=rightmotor2;
	_rightmotor3=rightmotor3;
	_rightmotor4=rightmotor4;
	
	digitalWrite(_leftmotor1, LOW);
	digitalWrite(_leftmotor2, LOW);
	digitalWrite(_leftmotor3, LOW);
	digitalWrite(_leftmotor4, LOW);
	digitalWrite(_rightmotor1, LOW);
	digitalWrite(_rightmotor2, LOW);
	digitalWrite(_rightmotor3, LOW);
	digitalWrite(_rightmotor4, LOW);
	
	cli();//stop interrupts
	  //set timer1 interrupt at 1Hz
	TCCR1A = 0;// set entire TCCR1A register to 0
	TCCR1B = 0;// same for TCCR1B
	TCNT1  = 0;//initialize counter value to 0
	// set compare match register for 1hz increments
	OCR1A = 15; //  = 16MHz/(64prescale*1ms^-1)-1 				----- sets timer1 interrupt frequency to 1kHz
	//OCR1A = 15624;// = (16*10^6) / (1*1024) - 1 (must be <65536)	----- sets timer1 interrupt frequency to 1Hz
	// turn on CTC mode
	TCCR1B |= (1 << WGM12);
	  // Set CS10 and CS12 bits for 1024 prescaler
	TCCR1B |= (1 << CS12) | (1 << CS10);  
	// enable timer compare interrupt
	TIMSK1 |= (1 << OCIE1A);

	sei();//allow interrupts
	
}


void dualStepper::motorISR(){
	
	if ((_leftMotorStateIndex <= 3) && (_lhMotorDir == -1)) {		//if the left motor spins counter clockwise this resets the left motor indexer (_leftMotorStateIndex) to 31
		_leftMotorStateIndex = 31;
	}
	else if ((_leftMotorStateIndex > 3) && (_lhMotorDir == -1)) {	//_leftMotorStateIndex decrments through state in steps of 4 so that the left stepper motor can use the correct output sequence
		_leftMotorStateIndex -= 4;
	}
	else if ((_leftMotorStateIndex >= 31) && (_lhMotorDir == 1)) {	//if the left motor spins  clockwise this resets the left motor indexer (_leftMotorStateIndex) to 3
		_leftMotorStateIndex = 3;
	}
	else if ((_leftMotorStateIndex < 31) && (_lhMotorDir == 1)) {
		_leftMotorStateIndex += 4;
	}
	
	 if ((_rightMotorStateIndex <= 3) && (_rhMotorDir == -1)) {
		_rightMotorStateIndex = 31;
	}
	else if ((_rightMotorStateIndex > 3) && (_rhMotorDir == -1)) {
		_rightMotorStateIndex -= 4;
	}
	else if ((_rightMotorStateIndex >= 31) && (_rhMotorDir == 1)) {
		_rightMotorStateIndex = 3;
	}
	else if ((_rightMotorStateIndex < 31) && (_rhMotorDir == 1)) {
		_rightMotorStateIndex += 4;
	} 
	
	if(_lhMotorDir != 0){
		digitalWrite(_leftmotor1, _state[_leftMotorStateIndex - 3]);
		digitalWrite(_leftmotor2, _state[_leftMotorStateIndex - 2]);
		digitalWrite(_leftmotor3, _state[_leftMotorStateIndex - 1]);
		digitalWrite(_leftmotor4, _state[_leftMotorStateIndex]);
	}
	else{
		digitalWrite(_leftmotor1, LOW);
		digitalWrite(_leftmotor2, LOW);
		digitalWrite(_leftmotor3, LOW);
		digitalWrite(_leftmotor4, LOW);
	}
	
 	if(_rhMotorDir != 0){
		digitalWrite(_rightmotor1, _state[_rightMotorStateIndex - 3]);
		digitalWrite(_rightmotor2, _state[_rightMotorStateIndex - 2]);
		digitalWrite(_rightmotor3, _state[_rightMotorStateIndex - 1]);
		digitalWrite(_rightmotor4, _state[_rightMotorStateIndex]);
	}
	else{
		digitalWrite(_rightmotor1, LOW);
		digitalWrite(_rightmotor2, LOW);
		digitalWrite(_rightmotor3, LOW);
		digitalWrite(_rightmotor4, LOW);
	} 
	
}

void dualStepper::Stop(){
	_lhMotorDir = 0;
	_rhMotorDir = 0;
}

void dualStepper::Forward(){
	_lhMotorDir = -1;
	_rhMotorDir = 1;
}

void dualStepper::Reverse(){
	_lhMotorDir = 1;
	_rhMotorDir = -1;
	
}
void dualStepper::Left(){
	_lhMotorDir=1;
	_rhMotorDir=1;
}
void dualStepper::Right(){
	_lhMotorDir=-1;
	_rhMotorDir=-1;
}
void dualStepper::pitchLeft(){
	_lhMotorDir=0;
	_rhMotorDir=1;
	
}
void dualStepper::pitchRight(){
	_lhMotorDir=-1;
	_rhMotorDir=0;
}

ISR(TIMER1_COMPA_vect) {
	//digitalWrite(13, !digitalRead(13)); // test blink to see if the isr is being triggered
	motor.motorISR();	//timer1 interrupt 1Hz toggles pin 13 (LED)
}