#include<iostream>

using namespace std;

class A{
private:
	A(){
		a = new A;
	}
public:
	//静态成员函数直接通过类名调用，不用创建对象
	static A* getInstace(){
		return a;
	}
private:
	static A*a;
};
A *A::a = NULL;

//实现单利步骤
//1.构造函数私有化
//2.增加静态私有的当前类的指针变量
//3.提供静态对外接口，可以让用户获得单例对象


//单例 分为懒汉式  饿汉式

//懒汉式，需要才创建
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
//类外初始化
Singleton_lazy * Singleton_lazy::pSingleton = NULL;

//饿汉式,比较着急
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
		cout << "两个指针指向同一块内存空间，是单例模式" << endl;
	}
	else
	{
		cout << "不是单例模式" << endl;
	}


	Singleton_hungry *p3 = Singleton_hungry::getInstace();
	Singleton_hungry *p4 = Singleton_hungry::getInstace();
	if (p3 == p4){
		cout << "两个指针指向同一块内存空间，是单例模式" << endl;
	}
	else
	{
		cout << "不是单例模式" << endl;
	}
}
//不需要考虑释放，程序结束就释放


int main(void)
{
	//test01();

	system("pause");
	return 0;
}