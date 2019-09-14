
#include<iostream>
using namespace std;

//����ˮ��
class AbstractFruit{
public:
	virtual void ShowName() = 0;

};

//ƻ��
class Apple :public AbstractFruit{
	virtual void ShowName(){
		cout << "����ƻ��" << endl;
	}
};

//�㽶
class Banana :public AbstractFruit{
public:
	virtual void ShowName(){
		cout << "�����㽶" << endl;
	}
};

//����
class Pear :public AbstractFruit{
public:
	virtual void ShowName(){
		cout << "��������" << endl;
	}
};

//����һ������
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