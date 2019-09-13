
#include<iostream>
using namespace std;

class AbstractCar{
public:
	virtual void run() = 0;
	
};

class Dazhong :public AbstractCar{
public:
	virtual void run()
	{
		cout << "大众车启动..." << endl;
	}
};

class Tuolaji :public AbstractCar{
public:
	virtual void run(){
		cout << "拖拉机启动.." << endl;
	}
};

//针对具体类，不使用继承
#if 0
class Person :public Tuolaji{
public:
	void Doufeng()
	{
		run();
	}
};

class PersonB :public Tuolaji{
public:
	void Doufeng()
	{
		run();
	}
};
#endif

//用组合
class Person{
public:
	/*~Person(){
		if (this->car != NULL){
			delete this->car;
		}
	}*/
	void setCar(AbstractCar *car){
		this->car = car;
	}
	void Doufeng(){
		this->car->run();
		if (this->car != NULL){
			delete this->car;
			this->car = NULL;
		}
	}

public:
	AbstractCar *car;
};

void test02(){
	Person* p = new Person;
	p->setCar(new Dazhong);
	p->Doufeng();
	
	p->setCar(new Tuolaji);
	p->Doufeng();

	delete p;
}

//继承和组合优先使用组合
int main()
{
	test02();
	system("pause");
	return 0;
}