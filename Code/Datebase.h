#pragma once
#include<map>
#include<vector>
#include"User.h"
#include"Order.h"
#include"Commodity.h"
#include"Administrator.h"

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

	void initial_user_imformation();//初始化用户文件为链表
	void initial_commodity_imformation();//初始化商品文件为链表
	void initial_order_imformation();//初始化订单文件为链表

	void final_user_imformation();//将用户链表写入文件中
	void final_commodity_imformation();//将商品链表写入文件中
	void final_order_imformation();//将订单链表写入文件中

	bool is_repeat_name();

	string new_userID();
	string new_commodityID();
	string new_orderID();

	/*User_map get_user();
	Commodity_map get_commodity();
	Order_map get_order();
	Administrator get_admin();*/

	User_map user;
	Commodity_map commodity;
	Order_map order;
	Administrator admin;
private:
};

