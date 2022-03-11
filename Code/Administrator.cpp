#include<iostream>
#include<iomanip>
#include"Administrator.h"
#include"Constant.h"
#include"iSQL.h"
#include"Datebase.h"
using namespace std;

extern Datebase mydate;

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
void Administrator::Choice() {
	int num = 0;
	string instruction, commodityName, userID, y_or_n, commodityID;
	while (true) {
		cout << endl;
		cout << "====================================================================================" << endl;
		cout << "1.查看所有商品 2.搜索商品 3.查看所有订单 4.查看所有用户 5.封禁用户 6.下架商品 7.注销" << endl;
		cout << "====================================================================================" << endl;
		cout << endl;
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
			instruction = "SELECT * FROM order";
			admin_instruction(instruction);
			break;
		case 4:
			instruction = "SELECT * FROM user";
			admin_instruction(instruction);
			break;
		case 5: {
			cout << "输入要封禁的用户ID：";
			cin >> userID;
			User_map::iterator u_it = mydate.user.find(userID);
			if (u_it == mydate.user.end()) {
				cout << "该用户不存在！！！" << endl;
				break;
			}
			cout << "确定要封禁该用户吗？" << endl;
			cout << "====================================================================================================================" << endl;
			cout << left << setw(10) << "用户ID" << setw(userName_len + 4) << "用户名" 
				<< setw(phoneNumber_len + 4) << "联系方式" << setw(address_len + 4) << "地址"
				<< setw(10) << "钱包余额" << endl;
			cout << left << setw(10) << u_it->second.userID << setw(userName_len + 4) << u_it->second.userName
				<< setw(phoneNumber_len + 4) << u_it->second.phoneNumber << setw(address_len + 4) << u_it->second.address
				<< setw(10) << u_it->second.balance << endl;
			cout << "====================================================================================================================" << endl;
			cout << "(y/n):";
			cin >> y_or_n;
			if (y_or_n == "y") {
				instruction = "UPDATE commodity SET commodityState = remove WHERE sellerID = " + userID;
				admin_instruction(instruction);
				instruction = "UPDATE user SET userState = inactive WHERE userID = " + userID;
				admin_instruction(instruction);
				cout << "用户封禁完成" << endl;
			}
			else {
				cout << "已放弃修改，即将返回上一界面......" << endl;
			}
			break;
		}
		case 6: {
			cout << "输入要下架的商品ID：";
			cin >> commodityID;
			Commodity_map::iterator c_it = mydate.commodity.find(commodityID);
			if (c_it == mydate.commodity.end()) {
				cout << "不存在该商品！！！" << endl;
				break;
			}
			cout << "确定要下架该商品吗？" << endl;
			cout << "****************************************************************************************************" << endl;
			cout << left << setw(ID_len + 6) << "商品ID" << setw(commodityName_len + 4) << "名称"
				<< setw(10) << "价格" << setw(14) << "上架时间" << setw(ID_len + 6) << "卖家ID"
				<< setw(10) << "数量" << setw(10) << "商品状态" << endl;
			cout << left << setw(ID_len + 6) << c_it->second.commodityID << setw(commodityName_len + 4) << c_it->second.commodityName
				<< setw(10) << c_it->second.price << setw(14) << c_it->second.addedDate << setw(ID_len + 6) << c_it->second.sellerID
				<< setw(10) << c_it->second.sellerID << setw(10) << c_it->second.state << endl;
			cout << "****************************************************************************************************" << endl;
			cout << "(y/n):";
			cin >> y_or_n;
			if (y_or_n == "y") {
				instruction = "UPDATE commodity SET commodityState = remove WHERE commodityID = M001";
				admin_instruction(instruction);
				cout << "商品下架完成" << endl;
			}
			else {
				cout << "已放弃下架该商品,即将返回上一界面......" << endl;
			}
			break;
		}
		case 7:
			return;
		default:
			cout << "输入错误！！！请重新输入." << endl;
			break;
		}
	}
}