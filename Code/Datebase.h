#pragma once
#include<map>
#include<vector>
#include"User.h"
#include"Order.h"
#include"Commodity.h"

typedef map<string, User> User_map;
typedef map<string, Commodity> Commodity_map;
typedef map<string, Order> Order_map;

class Datebase
{
public:
	Datebase();
	~Datebase();

	bool is_repeat_name(string a_name);
	void id_increase(string id);

	void initial_user_imformation();//��ʼ���û��ļ�Ϊ����
	void initial_commodity_imformation();//��ʼ����Ʒ�ļ�Ϊ����
	void initial_order_imformation();//��ʼ�������ļ�Ϊ����

	void final_user_imformation();//���û�����д���ļ���
	void final_commodity_imformation();//����Ʒ����д���ļ���
	void final_order_imformation();//����������д���ļ���

private:
	User_map user;
	Commodity_map commodity;
	Order_map order;
};

