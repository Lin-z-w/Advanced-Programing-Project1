#pragma once
#include<string>
using namespace std;

class Administrator
{
public:
	Administrator();
	~Administrator();

	void choice();//管理员的选择
	void look_up_commodity();//查看所有商品
	void search_commodity();//搜索商品
	void look_up_order();//查看订单
	void look_up_users();//查看用户
	void ban_user();//封禁用户
	void pull_commodity();//下架商品

private:
	string name, password;//分别为admin，123456（保存在Constant.h文件中）
};
