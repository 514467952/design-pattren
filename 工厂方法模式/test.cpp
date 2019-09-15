#include<iostream>
using namespace std;

//抽象水果
class AbstractFruit{
public:
	virtual void ShowName() = 0;

};

//苹果
class Apple :public AbstractFruit{
	virtual void ShowName(){
		cout << "我是苹果" << endl;
	}
};

//香蕉
class Banana :public AbstractFruit{
public:
	virtual void ShowName(){
		cout << "我是香蕉" << endl;
	}
};

//梨子
class Pear :public AbstractFruit{
public:
	virtual void ShowName(){
		cout << "我是梨子" << endl;
	}
};

//把工厂抽象出来
class AbstractFruitFactory{
public:
	virtual AbstractFruit* CreateFruit() = 0;

};
//苹果工厂
class AppleFactiry :public AbstractFruitFactory{
public:
	virtual AbstractFruit *CreateFruit(){
		return new Apple;
	}
};
//香蕉工厂
class BananaFactory :public AbstractFruitFactory{
public:
	virtual AbstractFruit * CreateFruit(){
		return new Banana;
	}
};

//梨子工厂
class PearFactory :public AbstractFruitFactory{
public:
	virtual AbstractFruit * CreateFruit(){
		return new Pear;
	}
};


void test01(){
	AbstractFruitFactory *factory = NULL;
	AbstractFruit *fruit = NULL;
	//创建苹果工厂
	factory = new AppleFactiry;
	fruit = factory->CreateFruit();
	fruit->ShowName();

	delete fruit;
	delete factory;

	//创建一个香蕉工厂
	factory = new BananaFactory;
	fruit = factory->CreateFruit();
	fruit->ShowName();
	delete fruit;
	delete factory;

	//创建一个梨子工厂
	factory = new PearFactory;
	fruit = factory->CreateFruit();
	fruit->ShowName();
	delete fruit;
	delete factory;
}



int main(void)
{
	test01();
	system("pause");
	return 0;
}