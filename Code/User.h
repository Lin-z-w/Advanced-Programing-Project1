#pragma once
#include<string>
using namespace std;

class User
{
public:
	User();
	User(string userID_in, string userName_in, string password_in, string phoneNumber_in, string adress_in, double balance_in, string userState_in);
	~User();

	void U_add_user();//������β�������û�
	void U_choice();//�û���ѡ��
	void U_my_imformation();//�û���Ϣ
	void U_change_my_imformation();//�ı��û���Ϣ
	void U_look_up_my_imformation();//�鿴�û���Ϣ
	void U_top_up();//��ֵ

protected:
	string userID, userName, password, phoneNumber, adress, userState;
	double balance;
};
