#pragma once
#include"User.h"

class Buyer: public User
{
public:
	Buyer();
	~Buyer();
	void B_choice();//买家选择
	void B_look_up_commodity();//查看正在出售的商品
	void B_buy_commodity();//购买商品
	void B_search_commodity();//搜索商品
	void B_look_up_iorder();//查看自己的订单
	void B_look_up_detail();//查看商品详情

private:

};