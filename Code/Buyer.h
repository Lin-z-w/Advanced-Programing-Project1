#pragma once
#include"User.h"

class Buyer: public User
{
public:
	Buyer();
	~Buyer();
	void choice();//买家选择
	void look_up_commodity();//查看正在出售的商品
	void buy_commodity();//购买商品
	void search_commodity();//搜索商品
	void look_up_iorder();//查看自己的订单
	void look_up_detail();//查看商品详情

private:

};