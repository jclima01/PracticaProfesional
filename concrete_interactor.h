

#ifndef concrete_interactorH
#define concrete_interactorH

#include <iostream>
#include "concrete_adder.h"

class Interactor{
public:
	Interactor(Adder* model) : myModel(model){

	}
	virtual ~Interactor(void){
		if (TEST_DESTRUCTOR) std::cout << "Interactor::~Interactor(void)" << std::endl;	
	}
	void edit(void){
		int input = 0;
		std::cout << "Adder value: "<< myModel->value() << std::endl;
	looper:
		std::cin >> input;
		if (input != 0){
			std::cout << "Adder value: " << myModel->add(input)<< std::endl;
		goto looper;
		}
	}
private:
	Adder* myModel;

	Interactor(const Interactor&);
	Interactor& operator = (const Interactor&);
};

#endif