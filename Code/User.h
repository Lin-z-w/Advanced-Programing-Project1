#pragma once
#include<string>
#include"Administrator.h"
using namespace std;

class User
{
public:
	User();
	User(string userID_in, string userName_in, string password_in, string phoneNumber_in, string address_in, double balance_in, string userState_in);
	~User();

	void U_add_user();//������β�������û�
	void U_choice();//�û���ѡ��
	void U_my_imformation();//�û���Ϣ
	void U_change_my_imformation();//�ı��û���Ϣ
	void U_look_up_my_imformation();//�鿴�û���Ϣ
	void U_top_up();//��ֵ

	string get_ID();
	string get_name();
	string get_password();
	string get_phoneNumber();
	string get_address();
	string get_userState();
	double get_balance();

	friend void admin_instruction(string instruction);
	friend Administrator;

protected:
	string userID, userName, password, phoneNumber, address, userState;
	double balance;
};
