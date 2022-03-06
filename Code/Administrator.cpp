#include<iostream>
#include"Administrator.h"
#include"Constant.h"
#include"iSQL.h"
using namespace std;

Administrator::Administrator()
{
	name = administratorName;
	password = administratorPassword;
}

Administrator::~Administrator()
{
}

string Administrator::get_name() {
	return name;
}
string Administrator::get_password() {
	return password;
}

void Administrator::choice() {
	int num = 0;
	string instruction, commodityName;
	while (true) {
		cout << "====================================================================================" << endl;
		cout << "1.查看所有商品 2.搜索商品 3.查看所有订单 4.查看所有用户 5.删除用户 6.下架商品 7.注销" << endl;
		cout << "====================================================================================" << endl;
		cout << "请输入操作：";
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
			instruction = "SELECT * FROM commodity";
			admin_instruction(instruction);
			break;
		case 2:
			cout << "请输入商品名称：";
			cin >> commodityName;
			instruction = "SELECT * FROM commodity WHERE commodityName CONTAINS " + commodityName;
			admin_instruction(instruction);
			break;
		case 3:
			
			break;
		case 4:
			
			break;
		case 5:
			
			break;
		case 6:

			break;
		case 7:
			return;
		default:
			cout << "输入错误！！！请重新输入." << endl;
			break;
		}
	}
}