#pragma once
#include<string>
using namespace std;

class Administrator
{
public:
	Administrator();
	~Administrator();

	void Choice();//����Ա��ѡ��
	string get_name();
	string get_password();


private:
	string name, password;//�ֱ�Ϊadmin��123456��������Constant.h�ļ��У�
};
