#pragma once
#include<string>
using namespace std;

class User
{
public:
	User();
	User(string userID_in, string userName_in, string password_in, string phoneNumber_in, string adress_in, double balance_in, string userState_in);
	~User();

	void U_add_user();//向链表尾部增加用户
	void U_choice();//用户的选择
	void U_my_imformation();//用户信息
	void U_change_my_imformation();//改变用户信息
	void U_look_up_my_imformation();//查看用户信息
	void U_top_up();//充值

protected:
	string userID, userName, password, phoneNumber, adress, userState;
	double balance;
};
