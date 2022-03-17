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

	void Choice();//用户的选择
	void My_imformation();//用户信息
	void Change_my_imformation();//改变用户信息
	void Look_up_my_imformation();//查看用户信息
	void Top_up();//充值

	string get_ID();
	string get_name();
	string get_password();
	string get_phoneNumber();
	string get_address();
	string get_userState();
	double get_balance();
	void add_balance(double b);
	void minus_balance(double b);

	friend void admin_instruction(string instruction);
	friend Administrator;

protected:
	string userID, userName, password, phoneNumber, address, userState;
	double balance;
};
