
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

//建立一个工厂
class FruitFactory{
public:
	static AbstractFruit *CreateFruit(string flag){
		if (flag == "apple"){
			return new Apple;
		}
		else if (flag == "pear"){
			return new Pear;
		}
		else if (flag == "banana"){
			return new Banana;
		}
	}
};

void test01(){
	FruitFactory *factory = new FruitFactory;
	AbstractFruit *fruit = factory->CreateFruit("apple");
	fruit->ShowName();
	delete fruit;

	fruit = factory->CreateFruit("banana");
	fruit->ShowName();
	delete fruit;

	fruit = factory->CreateFruit("pear");
	fruit->ShowName();
	delete fruit;
}

int main(void)
{
	test01();
	system("pause");
	return 0;
}