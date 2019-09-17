
#include<iostream>
#include<string>

using namespace std;

//一个房子不管是公寓还是别墅，他都有三种属性，墙，地板，门
//建造公寓和别墅时，都需要建造者有房子的图纸

//房子类
class House
{
public:
	//创建地板
	void setFloor(string floor)
	{
		this->m_floor = floor;
	}
	//创建墙
	void setWall(string wall)
	{
		this->m_wall = wall;
	}
	//创建门
	void setdoor(string door )
	{
		this->m_door = door;
	}
	//获取地板
	string getFloor()
	{
		return m_floor;
	}
	//获取墙
	string getWall()
	{
		return m_wall;
	}
	//获取门
	string getDoor()
	{
		return m_door;
	}
private:
	string m_floor;//地板
	string m_wall;//墙
	string m_door;//门
};

//建造者
class Builder
{
public:
	virtual void makeFloor() = 0; //建造者建地板
	virtual void makeWall() = 0;	//建造者建墙
	virtual void makeDoor() = 0; //建造者建门
	virtual House *GetHouse() = 0; //建造者建房子
};

//建造者建造公寓 继承建造者类
class FlatBuild : public Builder
{
public:
	FlatBuild()
	{
		phouse = new House;//创建一个新的房子
	}
	virtual void makeFloor()
	{
		//这个房子的墙是公寓的地板
		phouse->setFloor("公寓的地板");
	}
	virtual void makeWall()
	{
		phouse->setWall("公寓的墙");
	}

	virtual void makeDoor()
	{
		phouse->setdoor("公寓的门");
	}

	virtual House *GetHouse()
	{
		return phouse;
	}
private:
	House *phouse; //维护一个房子类的指针
};

//建造者建造别墅 
class VillBuild :public Builder
{
public:
	VillBuild()
	{
		pHouse = new House;
	}
	virtual void makeFloor()
	{
		pHouse->setFloor("别墅的地板");
	}
	virtual void makeWall()
	{
		pHouse->setWall("别墅的墙");
	}
	virtual void makeDoor()
	{
		pHouse->setdoor("别墅的门");
	}
	virtual House *GetHouse()
	{
		return pHouse;
	}
private:
	House *pHouse;
};

//设计师类，用来指挥建造者
class Director
{
public:
	void Construct(Builder *builder)
	{
		builder->makeFloor();
		builder->makeWall();
		builder->makeDoor();
	}
};

int main(void)
{
	//客户自造房子，不花钱请建造者和设计师
	House *phouse = new House;
	phouse->setdoor("自己造的门");
	phouse->setFloor("自己造的地板");
	phouse->setWall("自己造的墙");
	cout << phouse->getDoor() << endl;
	cout << phouse->getWall() << endl;
	cout << phouse->getFloor() << endl;
	/*
	//建造者直接造公寓，不花钱请设计师
	Builder *builder = new FlatBuild;
	builder->makeFloor();
	builder->makeDoor();
	builder->makeWall();
	*/

	//设计师指挥	建造者	建房子
	Director *director = new Director;

	//建公寓
	Builder *builder = new FlatBuild;
	director->Construct(builder);//设计师指挥建造者干活,直接全部建好
	House*house = builder->GetHouse();//获取已经建好房子的钥匙
	cout << house->getFloor() << endl;//查看建好房子的地板
	delete house;
	delete builder;
	
	//建别墅
	builder = new VillBuild;
	director->Construct(builder);//设计师 指挥工程队  建好别墅
	house = builder->GetHouse();//从建造者那块拿到别墅的钥匙
	cout << house->getFloor() << endl;//查看建好的别墅的地板

	delete house;
	delete builder;
	delete director;

	system("pause");
	return 0;
}