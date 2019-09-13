#include<iostream>
#include<string>
#include<vector>
using namespace std;
//������ԭ���ֽ���С֪ʶԭ�򣬲�Ҫ��¶�ڲ��ṹ��ֻ�ṩ�ӿ�

class AbstractBuiding
{
public:
	virtual void sale() = 0;
	virtual string getQuality() = 0;
};

//¥��A
class BuildingA :public AbstractBuiding
{
public:
	BuildingA()
	{
		mQuity = "��Ʒ��";
	}
	virtual void sale(){
		cout << "¥��A" << mQuity << "������";
	}
	virtual string getQuality()
	{
		return mQuity;
	}
public:
	string mQuity;
};

//¥��B
class BuildingB :public AbstractBuiding
{
public:
	BuildingB()
	{
		mQuity = "��Ʒ��";
	}
	virtual void sale(){
		cout << "¥��B" << mQuity << "������";
	}
	virtual string getQuality()
	{
		return mQuity;
	}
public:
	string mQuity;
};
#if 0
void test01()
{
	BuildingA * ba = new BuildingA;
	if (ba->mQuity == "��Ʒ��"){
		ba->sale();
	}
	BuildingB *bb = new BuildingB;
	if (bb->mQuity == "��Ʒ��"){
		bb->sale();
	}
}
#endif

//�н���
class Mediator{
public:
	Mediator(){
		AbstractBuiding * building = new BuildingA;
		vBuilding.push_back(building);
		building = new BuildingB;
		vBuilding.push_back(building);
	}
	~Mediator()
	{
		for (vector<AbstractBuiding*>::iterator it = vBuilding.begin(); it != vBuilding.end(); it++)
		{
			if (*it != NULL){
				delete *it;
			}
		}
	}

	//�����ṩ�ӿ�
	AbstractBuiding *findMyBuilding(string qulity){
		for (vector<AbstractBuiding *>::iterator it = vBuilding.begin(); it != vBuilding.end(); it++)
		{
			if ((*it)->getQuality() == qulity){
				return *it;
			}
		}
		return NULL;
	}
public:
	vector<AbstractBuiding*>vBuilding;
};

void test02()
{
	Mediator *mediator = new Mediator;
	AbstractBuiding*building = mediator->findMyBuilding("��Ʒ��");
	if (building != NULL){
		building->sale();
	}
	else{
		cout << "û�з�����������¥�̣�" << endl;
	}
}

int main(void)
{
	//test01();
	test02();
	system("pause");
	return 0;
}
