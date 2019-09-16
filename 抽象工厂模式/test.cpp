#include<iostream>
using namespace std;

//����ƻ��
class AbstractApple{
public:
	virtual void ShowName() = 0;
};

//�й�ƻ��
class ChinaApple :public AbstractApple{
public:
	virtual void ShowName(){
		cout << "�й�ƻ��" << endl;
	}
};

class USAApple :public AbstractApple{
public:
	virtual void ShowName(){
		cout << "����ƻ��" << endl;
	}
};
class JapanApple :public AbstractApple{
public:
	virtual void ShowName(){
		cout << "�ձ�ƻ��" << endl;
	}
};
//�����㽶
class AbsrtactBanana{
public:
	virtual void ShowName() = 0;
};

//�й��㽶
class ChinaBanana :public AbsrtactBanana{
public:
	virtual void ShowName(){
		cout << "�й��㽶" << endl;
	}
};
class USABanana :public AbsrtactBanana{
public:
	virtual void ShowName(){
		cout << "�����㽶" << endl;
	}
};
class JapanBanana :public AbsrtactBanana{
public:
	virtual void ShowName(){
		cout << "�ձ��㽶" << endl;
	}
};

//���������
class AbsrtactPear{
public:
	virtual void ShowName() = 0;
};

//�й�����
class ChinaPear :public AbsrtactPear{
public:
	virtual void ShowName(){
		cout << "�й�����" << endl;
	}
};
//��������
class USAPear :public AbsrtactPear{
public:
	virtual void ShowName(){
		cout << "��������" << endl;
	}
};
//�ձ�����
class JapanPear :public AbsrtactPear{
public:
	virtual void ShowName(){
		cout << "�ձ�����" << endl;
	}
};


//���󹤳�   ��Բ�Ʒ��
class AbstractFactoty{
public:
	virtual AbstractApple *CreateApple() = 0;
	virtual AbsrtactBanana *CreateBanana() = 0;
	virtual AbsrtactPear* CreatePear() = 0;
};

//�й�����
class ChinaFactory :public AbstractFactoty{
public:
	virtual AbstractApple *CreateApple(){
		return new ChinaApple;
	}
	virtual AbsrtactBanana *CreateBanana(){
		return new ChinaBanana;
	}
	virtual AbsrtactPear* CreatePear() {
		return new ChinaPear;
	}
};
//��������
class USAFactory :public AbstractFactoty{
public:
	virtual AbstractApple *CreateApple(){
		return new USAApple;
	}
	virtual AbsrtactBanana *CreateBanana(){
		return new USABanana;
	}
	virtual AbsrtactPear* CreatePear() {
		return new USAPear;
	}
};
//�ձ�����
class JapanFactory :public AbstractFactoty{
public:
	virtual AbstractApple *CreateApple(){
		return new JapanApple;
	}
	virtual AbsrtactBanana *CreateBanana(){
		return new JapanBanana;
	}
	virtual AbsrtactPear* CreatePear() {
		return new JapanPear;
	}
};

void test01(){
	AbstractFactoty *factory = NULL;
	AbstractApple *apple = NULL;
	AbsrtactBanana *banana = NULL;
	AbsrtactPear *pear = NULL;

	//�й�����
	factory = new ChinaFactory; 
	apple = factory->CreateApple();
	banana = factory->CreateBanana();
	pear = factory->CreatePear();

	apple->ShowName();
	banana->ShowName();
	pear->ShowName();
	
	delete apple;
	delete banana;
	delete pear;
}

int main(void){
	test01();
	system("pause");
	return 0;
}