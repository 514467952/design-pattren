#include<iostream>
using namespace std;

//�ṩһ�ִ��������ƶ���������ķ���
class  AbstractCommonInterface{
public:
	//��������ϵͳ
	virtual void run() = 0;
};


//ϵͳ��Ȩ����֤����Ҫ�ṩ�û���������
//ϵͳ��
class MySystem{
public:
	virtual void run() {
		cout << "ϵͳ����" << endl;
	}
};

//������
class MySystemProxy :public AbstractCommonInterface{
public:
	MySystemProxy(string username, string password){
		this->mUsername = username;
		this->mPassword = password;
		pSystem = new MySystem;
	}
	//�ж��û����������Ƿ�Ϊ��ȷ
	bool checkUsernameAndPassword(){
		if (mUsername == "admin" && mPassword == "admin"){
			return true;
		}
		return false;
	}
	virtual void run(){
		if (checkUsernameAndPassword()){
			cout << "�����ɹ�" << endl;
			this->pSystem->run();
		}
		else{
			cout << "�û�������������޷�����ϵͳ" << endl;
		}
	}
	~MySystemProxy(){
		if (pSystem != NULL){
			delete pSystem;
		}
	}

private:
	MySystem *  pSystem;
	string mUsername;  //�û���
	string mPassword; //����
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


