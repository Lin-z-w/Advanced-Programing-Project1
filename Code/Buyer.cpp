#include"Buyer.h"
#include"Datebase.h"
#include"Constant.h"
#include"iSQL.h"
#include<iostream>
using namespace std;

extern Datebase mydate;

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
	string instruction;
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
		case 1://Done
			instruction = "SELECT * FROM commodity";
			buyer_instruction(instruction, userID);
			break;
		case 2:
		{
			int number, restnumber;
			string commodityID, orderID, price, y_or_n;
			cout << "请输入要购买的商品ID：";
			cin >> commodityID;
			Commodity_map::iterator a_commodity = mydate.commodity.find(commodityID);
			if (a_commodity == mydate.commodity.end() || a_commodity->second.get_state() == commodityState_r) {
				cout << "出售的商品中找不到该商品！！！" << endl;
				break;
			}
			cout << "请输入要购买的商品数量：";
			cin >> number;
			if (number <= 0) {
				cout << "购买的商品数量必须为正整数！！！" << endl;
				break;
			}
			else if (number > a_commodity->second.get_number()) {
				cout << "购买的商品数量超过商品总数！！！" << endl;
				break;
			}
			if (balance < a_commodity->second.get_price() * number) {
				cout << "余额不足！！！" << endl;
				break;
			}
			cout << "确定要购买该商品吗？？？(y/n):";
			cin >> y_or_n;
			if (y_or_n != "y") {
				cout << "已放弃购买！！！" << endl;
				break;
			}
			orderID = mydate.new_orderID();
			price = to_string(a_commodity->second.get_price());
			for (unsigned int i = 0; i < price.length(); i++) {
				if (price[i] == '.') {
					price = price.substr(0, i + 2);
				}
			}
			char now_time[11];
			iget_time(now_time);
			string buydate(now_time);
			instruction = "INSERT INTO order VALUES (" + orderID + "," + a_commodity->second.get_commodityID()
				+ "," + price + "," + to_string(number) + "," + buydate + "," + a_commodity->second.get_sellerID() + "," + userID + ")";
			buyer_instruction(instruction, userID);
			restnumber = a_commodity->second.get_number() - number;
			instruction = "UPDATE commodity SET number = " + to_string(restnumber) + "WHERE commodityID = " + commodityID;
			buyer_instruction(instruction, userID);
			if (restnumber == 0) {
				instruction = "UPDATE commodity SET commodityState = remove WHERE commodityID = " + commodityID;
				seller_instruction(instruction, a_commodity->second.get_sellerID());
			}
			mydate.user[userID].minus_balance(a_commodity->second.get_price() * number);
			mydate.user[a_commodity->second.get_sellerID()].add_balance(a_commodity->second.get_price() * number);
			break;
		}
		case 3://Done
		{
			string commodityName;
			cout << "请输入要查找的商品名称：";
			cin >> commodityName;
			instruction = "SELECT * FROM commodity WHERE commodityName CONTAINS " +commodityName;
			buyer_instruction(instruction, userID);
			break;
		}
		case 4://Done
			instruction = "SELECT * FROM order";
			buyer_instruction(instruction, userID);
			break;
		case 5://Done
		{
			string commodityID;
			cout << "请输入想寻找的商品的ID：";
			cin >> commodityID;
			instruction = "SELECT * FROM commodity WHERE commodityID CONTAINS " + commodityID;
			buyer_instruction(instruction, userID);
			break;
		}
		case 6:
			return;
		default:
			cout << "输入错误！！！请重新输入！！！" << endl;
			break;
		}
	}
}