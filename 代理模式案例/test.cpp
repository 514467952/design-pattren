
#include<iostream>
using namespace std;


//
class Subject
{
public:
	virtual void SaleBook() = 0;
};

class RealSubject :public Subject
{
public:
	virtual void SaleBook()
	{
		cout << "实体店买书.." << endl;
	}
};

////代理淘宝
//class ProxyTaoBao :public Subject
//{
//public:;
//	   virtual void Book()
//	   {
//		   //
//		   Double11();
//		   RealSubject rs;
//		   rs.SaleBook();
//		   Double11();
//	   }
//	   void Double11(){
//		   cout << "Double11 打折 半价" << endl;
//	   }
//};

//代理淘宝
class ProxyTaoBao2 :public Subject 
{ 
public: 
	ProxyTaoBao2(){
		 this->m_s = new RealSubject;
	}
	~ProxyTaoBao2(){
		delete m_s;
	}
	virtual void SaleBook() 
	{ 
		Double11(); 
		m_s->SaleBook(); 
	} 
	void Double11() 
	{ 
		cout << "Double11 打折 半价" << endl; 
	} 
 private: 
	 RealSubject* m_s;
};




int main(){

	ProxyTaoBao2 *ptb = new ProxyTaoBao2;
	ptb->SaleBook();
	delete ptb;
	system("pause");
	return 0;
}