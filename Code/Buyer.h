#pragma once
#include"User.h"

class Buyer: public User
{
public:
	Buyer();
	~Buyer();
	void B_choice();//���ѡ��
	void B_look_up_commodity();//�鿴���ڳ��۵���Ʒ
	void B_buy_commodity();//������Ʒ
	void B_search_commodity();//������Ʒ
	void B_look_up_iorder();//�鿴�Լ��Ķ���
	void B_look_up_detail();//�鿴��Ʒ����

private:

};