#pragma once
#include<string>
using namespace std;

class Administrator
{
public:
	Administrator();
	~Administrator();

	void choice();//����Ա��ѡ��
	void look_up_commodity();//�鿴������Ʒ
	void search_commodity();//������Ʒ
	void look_up_order();//�鿴����
	void look_up_users();//�鿴�û�
	void ban_user();//����û�
	void pull_commodity();//�¼���Ʒ

private:
	string name, password;//�ֱ�Ϊadmin��123456��������Constant.h�ļ��У�
};
