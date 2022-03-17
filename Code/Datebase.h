#pragma once
#include<map>
#include<vector>
#include"User.h"
#include"Order.h"
#include"Commodity.h"
#include"Administrator.h"

struct Top_up_histroy {
	string topUpDate, ID, money;
};
typedef map<string, User> User_map;
typedef map<string, Commodity> Commodity_map;
typedef map<string, Order> Order_map;
typedef vector<Top_up_histroy> Topup_vector;

class Datebase
{
public:
	Datebase();
	~Datebase();

	bool is_repeat_name(string a_name);

	void initial_user_imformation();
	void initial_commodity_imformation();
	void initial_order_imformation();
	void initial_topuphistroy_imformation();

	void final_user_imformation();
	void final_commodity_imformation();
	void final_order_imformation();
	void final_topuphistroy_imformation();

	string new_userID();
	string new_commodityID();
	string new_orderID();

	User_map user;
	Commodity_map commodity;
	Order_map order;
	Topup_vector top_up_histroy;
	Administrator admin;

private:
};

