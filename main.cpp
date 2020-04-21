#include <iostream>




class Adder{
public:
	Adder(int value = 0) : itsValue(value){}
	virtual ~Adder(){}
	int value(){
		return itsValue;
	}
	int add(int value){
		itsValue += value;
	}
private:
	int itsValue;

	Adder(const Adder&);
	Adder& operator =(const Adder&);

};



class Console{
public:
	Console(Adder* model) : thisModel(model){
	}
	virtual ~Console(void){

	}
	void init(void){
		render();
	}

	bool edit(void){
		int input = 0;
	looper:
		std::cin >> input;
		if (input != 0){
			render();
			goto looper;
		}
	}
private:
	Adder* thisModel;

	void render(void){
		std::cout << "" << thisModel->add(input) << std::endl;
	}

	Console(const Console&);
	Console& operator =(const Console&);


};

class AdderApplication{
public:
	AdderApplication(void){
		model = new Adder();
		interactor = new Console(model);
	}

	virtual ~AdderApplication(void){
		delete interactor;
		delete model;
	}
	void init(void){
		interactor->init();

	}
	void run(void){
		interactor->edit();
	}
private:
	Adder* model;
	Console* interactor;

	AdderApplication(const AdderApplication&);
	AdderApplication& operator=(const AdderApplication&);
};

int main (){

	AdderApplication* application = new AdderApplication();
	try{
		application->init();
		application->run();
	} catch(...){
		;
	}
	delete application;

	return 0;
}