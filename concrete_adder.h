#ifndef concrete_adderH
#define concrete_adderH

#include <iostream>

#define TEST_DESTRUCTOR 1

class Adder {

public:
	Adder(int value = 0) : adderValue(value){
	}

	virtual ~Adder(void){
		if(TEST_DESTRUCTOR) std::cout << "Adder::~Adder(void)" << std::endl;
	}

	int add(int value){
		adderValue += value;
		return adderValue;
	}

	int value(void){
		return adderValue;
	}
private:
	int adderValue;

	Adder(const Adder&);
	Adder& operator = (const Adder&);

};

#endif