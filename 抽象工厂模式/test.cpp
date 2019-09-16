#include<iostream>
using namespace std;

//抽象苹果
class AbstractApple{
public:
	virtual void ShowName() = 0;
};

//中国苹果
class ChinaApple :public AbstractApple{
public:
	virtual void ShowName(){
		cout << "中国苹果" << endl;
	}
};

class USAApple :public AbstractApple{
public:
	virtual void ShowName(){
		cout << "美国苹果" << endl;
	}
};
class JapanApple :public AbstractApple{
public:
	virtual void ShowName(){
		cout << "日本苹果" << endl;
	}
};
//抽象香蕉
class AbsrtactBanana{
public:
	virtual void ShowName() = 0;
};

//中国香蕉
class ChinaBanana :public AbsrtactBanana{
public:
	virtual void ShowName(){
		cout << "中国香蕉" << endl;
	}
};
class USABanana :public AbsrtactBanana{
public:
	virtual void ShowName(){
		cout << "美国香蕉" << endl;
	}
};
class JapanBanana :public AbsrtactBanana{
public:
	virtual void ShowName(){
		cout << "日本香蕉" << endl;
	}
};

//抽象的梨子
class AbsrtactPear{
public:
	virtual void ShowName() = 0;
};

//中国梨子
class ChinaPear :public AbsrtactPear{
public:
	virtual void ShowName(){
		cout << "中国梨子" << endl;
	}
};
//美国梨子
class USAPear :public AbsrtactPear{
public:
	virtual void ShowName(){
		cout << "美国梨子" << endl;
	}
};
//日本梨子
class JapanPear :public AbsrtactPear{
public:
	virtual void ShowName(){
		cout << "日本梨子" << endl;
	}
};


//抽象工厂   针对产品族
class AbstractFactoty{
public:
	virtual AbstractApple *CreateApple() = 0;
	virtual AbsrtactBanana *CreateBanana() = 0;
	virtual AbsrtactPear* CreatePear() = 0;
};

//中国工厂
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
//美国工厂
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
//日本工厂
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

	//中国工厂
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