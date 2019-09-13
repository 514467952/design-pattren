#include<iostream>
#include<string>
#include<vector>
using namespace std;
//迪米特原则，又叫最小知识原则，不要暴露内部结构，只提供接口

class AbstractBuiding
{
public:
	virtual void sale() = 0;
	virtual string getQuality() = 0;
};

//楼盘A
class BuildingA :public AbstractBuiding
{
public:
	BuildingA()
	{
		mQuity = "高品质";
	}
	virtual void sale(){
		cout << "楼盘A" << mQuity << "被售卖";
	}
	virtual string getQuality()
	{
		return mQuity;
	}
public:
	string mQuity;
};

//楼盘B
class BuildingB :public AbstractBuiding
{
public:
	BuildingB()
	{
		mQuity = "低品质";
	}
	virtual void sale(){
		cout << "楼盘B" << mQuity << "被售卖";
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
	if (ba->mQuity == "低品质"){
		ba->sale();
	}
	BuildingB *bb = new BuildingB;
	if (bb->mQuity == "低品质"){
		bb->sale();
	}
}
#endif

//中介类
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

	//对外提供接口
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
	AbstractBuiding*building = mediator->findMyBuilding("高品质");
	if (building != NULL){
		building->sale();
	}
	else{
		cout << "没有符合您条件的楼盘！" << endl;
	}
}

int main(void)
{
	//test01();
	test02();
	system("pause");
	return 0;
}
