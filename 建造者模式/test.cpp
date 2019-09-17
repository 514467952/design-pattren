
#include<iostream>
#include<string>

using namespace std;

//һ�����Ӳ����ǹ�Ԣ���Ǳ������������������ԣ�ǽ���ذ壬��
//���칫Ԣ�ͱ���ʱ������Ҫ�������з��ӵ�ͼֽ

//������
class House
{
public:
	//�����ذ�
	void setFloor(string floor)
	{
		this->m_floor = floor;
	}
	//����ǽ
	void setWall(string wall)
	{
		this->m_wall = wall;
	}
	//������
	void setdoor(string door )
	{
		this->m_door = door;
	}
	//��ȡ�ذ�
	string getFloor()
	{
		return m_floor;
	}
	//��ȡǽ
	string getWall()
	{
		return m_wall;
	}
	//��ȡ��
	string getDoor()
	{
		return m_door;
	}
private:
	string m_floor;//�ذ�
	string m_wall;//ǽ
	string m_door;//��
};

//������
class Builder
{
public:
	virtual void makeFloor() = 0; //�����߽��ذ�
	virtual void makeWall() = 0;	//�����߽�ǽ
	virtual void makeDoor() = 0; //�����߽���
	virtual House *GetHouse() = 0; //�����߽�����
};

//�����߽��칫Ԣ �̳н�������
class FlatBuild : public Builder
{
public:
	FlatBuild()
	{
		phouse = new House;//����һ���µķ���
	}
	virtual void makeFloor()
	{
		//������ӵ�ǽ�ǹ�Ԣ�ĵذ�
		phouse->setFloor("��Ԣ�ĵذ�");
	}
	virtual void makeWall()
	{
		phouse->setWall("��Ԣ��ǽ");
	}

	virtual void makeDoor()
	{
		phouse->setdoor("��Ԣ����");
	}

	virtual House *GetHouse()
	{
		return phouse;
	}
private:
	House *phouse; //ά��һ���������ָ��
};

//�����߽������ 
class VillBuild :public Builder
{
public:
	VillBuild()
	{
		pHouse = new House;
	}
	virtual void makeFloor()
	{
		pHouse->setFloor("�����ĵذ�");
	}
	virtual void makeWall()
	{
		pHouse->setWall("������ǽ");
	}
	virtual void makeDoor()
	{
		pHouse->setdoor("��������");
	}
	virtual House *GetHouse()
	{
		return pHouse;
	}
private:
	House *pHouse;
};

//���ʦ�࣬����ָ�ӽ�����
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
	//�ͻ����췿�ӣ�����Ǯ�뽨���ߺ����ʦ
	House *phouse = new House;
	phouse->setdoor("�Լ������");
	phouse->setFloor("�Լ���ĵذ�");
	phouse->setWall("�Լ����ǽ");
	cout << phouse->getDoor() << endl;
	cout << phouse->getWall() << endl;
	cout << phouse->getFloor() << endl;
	/*
	//������ֱ���칫Ԣ������Ǯ�����ʦ
	Builder *builder = new FlatBuild;
	builder->makeFloor();
	builder->makeDoor();
	builder->makeWall();
	*/

	//���ʦָ��	������	������
	Director *director = new Director;

	//����Ԣ
	Builder *builder = new FlatBuild;
	director->Construct(builder);//���ʦָ�ӽ����߸ɻ�,ֱ��ȫ������
	House*house = builder->GetHouse();//��ȡ�Ѿ����÷��ӵ�Կ��
	cout << house->getFloor() << endl;//�鿴���÷��ӵĵذ�
	delete house;
	delete builder;
	
	//������
	builder = new VillBuild;
	director->Construct(builder);//���ʦ ָ�ӹ��̶�  ���ñ���
	house = builder->GetHouse();//�ӽ������ǿ��õ�������Կ��
	cout << house->getFloor() << endl;//�鿴���õı����ĵذ�

	delete house;
	delete builder;
	delete director;

	system("pause");
	return 0;
}