#pragma once
#include<iostream>
#include<string>
using namespace std;

class User
{
public:
	User();
	~User();

	void U_add_user();//������β�������û�
	void U_choice();//�û���ѡ��
	void U_my_imformation();//�û���Ϣ
	void U_change_my_imformation();//�ı��û���Ϣ
	void U_look_up_my_imformation();//�鿴�û���Ϣ
	void U_top_up();//��ֵ

	void B_choice();//���ѡ��
	void B_look_up_commodity();//�鿴���ڳ��۵���Ʒ
	void B_buy_commodity();//������Ʒ
	void B_search_commodity();//������Ʒ
	void B_look_up_iorder();//�鿴�Լ��Ķ���
	void B_look_up_detail();//�鿴��Ʒ����

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
