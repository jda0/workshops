#ifndef drawFace_h
#define drawFace_h

class drawFace {
public:
	void start();
	void clear();
	void smile();
	void frown();
	void wink();
	void print(const char* text);
	void println(const char* text);
	
private:
};

extern drawFace Draw;

#endif
