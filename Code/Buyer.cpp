#include"Buyer.h"
#include<iostream>
using namespace std;

Buyer::Buyer(string userID_in, string userName_in, string password_in, string phoneNumber_in, string address_in, double balance_in, string userState_in)
{
	userID = userID_in;
	userName = userName_in;
	password = password_in;
	phoneNumber = phoneNumber_in;
	address = address_in;
	userState = userState_in;
	balance = balance_in;
}

Buyer::~Buyer()
{
}

void Buyer::Choice() {
	int num;
	while (true) {
		cout << endl;
		cout << "=======================================================================================" << endl;
		cout << "1.查看商品列表 2.购买商品 3.搜索商品 4.查看历史订单 5.查看商品详细信息 6.返回用户主界面" << endl;
		cout << "=======================================================================================" << endl;
		cout << endl;
		cout << "请选择：";
		cin >> num;
		if (cin.fail()) {
			cin.clear();
			cout << "输入错误！！！请重新输入。" << endl;
			cin.ignore(10000, '\n');
			continue;
		}
		switch (num)
		{
		case 1:
			
			break;
		case 2:
			
			break;
		case 3:
			
			break;
		case 4:
			
			break;
		case 5:
			
			break;
		case 6:
			return;
		default:
			cout << "输入错误！！！请重新输入！！！" << endl;
			break;
		}
	}
}