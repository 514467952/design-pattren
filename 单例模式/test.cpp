#include<iostream>

using namespace std;

class A{
private:
	A(){
		a = new A;
	}
public:
	//��̬��Ա����ֱ��ͨ���������ã����ô�������
	static A* getInstace(){
		return a;
	}
private:
	static A*a;
};
A *A::a = NULL;

//ʵ�ֵ�������
//1.���캯��˽�л�
//2.���Ӿ�̬˽�еĵ�ǰ���ָ�����
//3.�ṩ��̬����ӿڣ��������û���õ�������


//���� ��Ϊ����ʽ  ����ʽ

//����ʽ����Ҫ�Ŵ���
class Singleton_lazy{
private:
	Singleton_lazy(){}
public:
	static Singleton_lazy *getInstace()
	{
		if (pSingleton == NULL){
			pSingleton = new Singleton_lazy;
		}
		return pSingleton;
	}
private:
	static Singleton_lazy * pSingleton;
};
//�����ʼ��
Singleton_lazy * Singleton_lazy::pSingleton = NULL;

//����ʽ,�Ƚ��ż�
class Singleton_hungry{
private:
	Singleton_hungry(){
	}
public:
	static Singleton_hungry *getInstace()
	{
		return 	pSingleton;
	}
#if 0
	class Garbo{
		~Garbo(){
			if (pSingleton != NULL){
				delete pSingleton;
			}
		}
	};
#endif
private:
	static Singleton_hungry * pSingleton;
};
Singleton_hungry * Singleton_hungry::pSingleton = new Singleton_hungry;


void test01()
{
	Singleton_lazy *p1 = Singleton_lazy::getInstace();
	Singleton_lazy *p2 = Singleton_lazy::getInstace();
	if (p1 == p2){
		cout << "����ָ��ָ��ͬһ���ڴ�ռ䣬�ǵ���ģʽ" << endl;
	}
	else
	{
		cout << "���ǵ���ģʽ" << endl;
	}


	Singleton_hungry *p3 = Singleton_hungry::getInstace();
	Singleton_hungry *p4 = Singleton_hungry::getInstace();
	if (p3 == p4){
		cout << "����ָ��ָ��ͬһ���ڴ�ռ䣬�ǵ���ģʽ" << endl;
	}
	else
	{
		cout << "���ǵ���ģʽ" << endl;
	}
}
//����Ҫ�����ͷţ�����������ͷ�


int main(void)
{
	//test01();

	system("pause");
	return 0;
}