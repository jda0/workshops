#ifndef drawFace_h
#define drawFace_h

#include "Arduino.h"
#include "U8glib.h"

class drawFace {
public:
	void Smile();
	void Frown();
	void Wink();
	void Wifi1();
	void Wifi2();
	void Wifi3();

private:
};

extern drawFace draw;

#endif