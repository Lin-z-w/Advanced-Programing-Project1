#pragma once
#include<map>
#include<vector>
#include"User.h"
#include"Order.h"
#include"Commodity.h"

struct commands_struct {
	string time, command;
};
typedef map<string, User> User_map;
typedef map<string, Commodity> Commodity_map;
typedef map<string, Order> Order_map;
typedef vector<commands_struct> Commands_vector;

class Datebase
{
public:
	Datebase();
	~Datebase();

	bool is_repeat_name(string a_name);
	void id_increase(string id);

	void initial_user_imformation();//初始化用户文件为链表
	void initial_commodity_imformation();//初始化商品文件为链表
	void initial_order_imformation();//初始化订单文件为链表
	void initial_SQL_instruction();//初始化SQL指令文件为链表

	void final_user_imformation();//将用户链表写入文件中
	void final_commodity_imformation();//将商品链表写入文件中
	void final_order_imformation();//将订单链表写入文件中
	void final_SQL_instruction();//将SQL指令链表写入文件中

private:
	User_map user;
	Commodity_map commodity;
	Order_map order;
	Commands_vector command;
};

