#pragma once
#include"User.h"

class Buyer: public User
{
public:
	Buyer();
	~Buyer();
	void choice();//���ѡ��
	void look_up_commodity();//�鿴���ڳ��۵���Ʒ
	void buy_commodity();//������Ʒ
	void search_commodity();//������Ʒ
	void look_up_iorder();//�鿴�Լ��Ķ���
	void look_up_detail();//�鿴��Ʒ����

private:

};