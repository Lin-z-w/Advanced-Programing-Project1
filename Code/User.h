#pragma once
#include<iostream>
#include<string>
using namespace std;

class User
{
public:
	User();
	~User();

	void U_add_user();//向链表尾部增加用户
	void U_choice();//用户的选择
	void U_my_imformation();//用户信息
	void U_change_my_imformation();//改变用户信息
	void U_look_up_my_imformation();//查看用户信息
	void U_top_up();//充值

	void B_choice();//买家选择
	void B_look_up_commodity();//查看正在出售的商品
	void B_buy_commodity();//购买商品
	void B_search_commodity();//搜索商品
	void B_look_up_iorder();//查看自己的订单
	void B_look_up_detail();//查看商品详情

	void S_choice();
	void S_issue_commodity();
	void S_look_up_icommodity();
	void S_change_icommodity_attribute();
	void S_pull_icommodity();
	void S_look_up_iorder();

private:
	struct Node {
		string userID, username, password, phoneNumber, adress, userState;
		int balance;
		Node* next;
	};
	Node* userhead, * usertail;
};
