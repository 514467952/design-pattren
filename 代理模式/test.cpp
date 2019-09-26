#include<iostream>
using namespace std;

//提供一种代理来控制对其他对象的访问
class  AbstractCommonInterface{
public:
	//用来启动系统
	virtual void run() = 0;
};


//系统有权限验证，需要提供用户名和密码
//系统类
class MySystem{
public:
	virtual void run() {
		cout << "系统启动" << endl;
	}
};

//代理类
class MySystemProxy :public AbstractCommonInterface{
public:
	MySystemProxy(string username, string password){
		this->mUsername = username;
		this->mPassword = password;
		pSystem = new MySystem;
	}
	//判断用户名和密码是否为正确
	bool checkUsernameAndPassword(){
		if (mUsername == "admin" && mPassword == "admin"){
			return true;
		}
		return false;
	}
	virtual void run(){
		if (checkUsernameAndPassword()){
			cout << "启动成功" << endl;
			this->pSystem->run();
		}
		else{
			cout << "用户名或密码错误，无法启动系统" << endl;
		}
	}
	~MySystemProxy(){
		if (pSystem != NULL){
			delete pSystem;
		}
	}

private:
	MySystem *  pSystem;
	string mUsername;  //用户名
	string mPassword; //密码
};


void test01(){
	MySystemProxy * proxy = new MySystemProxy("admin", "admin");
	proxy->run();
}


int main(void){
	test01();
	system("pause");
	return 0;
}


