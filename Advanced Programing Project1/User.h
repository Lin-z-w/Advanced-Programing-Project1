#pragma once
#include<iostream>
#include<string>
using namespace std;

class User
{
public:
	User();
	~User();

	void U_choice();
	void U_my_imformation();
	void U_change_my_imformation();
	void U_look_up_my_imformation();
	void U_top_up();

	void B_choice();
	void B_look_up_commodity();
	void B_buy_commodity();
	void B_search_commodity();
	void B_look_up_iorder();
	void B_look_up_detail();

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
