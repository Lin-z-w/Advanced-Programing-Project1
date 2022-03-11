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

	void initial_user_imformation();
	void initial_commodity_imformation();
	void initial_order_imformation();

	void final_user_imformation();
	void final_commodity_imformation();
	void final_order_imformation();

	string new_userID();
	string new_commodityID();
	string new_orderID();

	User_map user;
	Commodity_map commodity;
	Order_map order;
	Administrator admin;
private:
};

