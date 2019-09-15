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

//�ѹ����������
class AbstractFruitFactory{
public:
	virtual AbstractFruit* CreateFruit() = 0;

};
//ƻ������
class AppleFactiry :public AbstractFruitFactory{
public:
	virtual AbstractFruit *CreateFruit(){
		return new Apple;
	}
};
//�㽶����
class BananaFactory :public AbstractFruitFactory{
public:
	virtual AbstractFruit * CreateFruit(){
		return new Banana;
	}
};

//���ӹ���
class PearFactory :public AbstractFruitFactory{
public:
	virtual AbstractFruit * CreateFruit(){
		return new Pear;
	}
};


void test01(){
	AbstractFruitFactory *factory = NULL;
	AbstractFruit *fruit = NULL;
	//����ƻ������
	factory = new AppleFactiry;
	fruit = factory->CreateFruit();
	fruit->ShowName();

	delete fruit;
	delete factory;

	//����һ���㽶����
	factory = new BananaFactory;
	fruit = factory->CreateFruit();
	fruit->ShowName();
	delete fruit;
	delete factory;

	//����һ�����ӹ���
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