

#include "concrete_interactor.h"


int main(){

	Adder* adder = new Adder(10);
	Interactor* interactor = new Interactor(adder);

	interactor->edit();

	delete interactor;
	delete adder;

	

	return 0;
}