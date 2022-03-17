#include"User.h"
#include"Buyer.h"
#include"Seller.h"
#include"Datebase.h"
#include<iostream>

extern Datebase mydate;
extern void iget_time(char* p);
extern double Calculator(string formula);

User::User() 
{
	balance = 0;
}

User::User(string userID_in, string userName_in, string password_in, string phoneNumber_in, string address_in, double balance_in, string userState_in)
{
	userID = userID_in;
	userName = userName_in;
	password = password_in;
	phoneNumber = phoneNumber_in;
	address = address_in; 
	userState = userState_in;
	balance = balance_in;
}

User::~User()
{
}

void one_double(string& num) {
	for (int i = 0; i < num.length(); i++) {
		if (num[i] == '.') {
			num = num.substr(0, i + 2);
			break;
		}
	}
}
void User::Choice() {
	string instruction;
	int num;
	while (true) {
		cout << endl;
		cout << "===============================================" << endl;
		cout << "1.注销登录 2.我是买家 3.我是卖家 4.个人信息管理" << endl;
		cout << "===============================================" << endl;
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
			return;
		case 2: {
			Buyer a_buyer(userID, userName, password, phoneNumber, address, balance, userState);
			a_buyer.Choice();
			break;
		}
		case 3: {
			Seller a_seller(userID, userName, password, phoneNumber, address, balance, userState);
			a_seller.Choice();
			break;
		}
		case 4:
			My_imformation();
			break;
		default:
			cout << "输入错误！！！请重新输入。" << endl;
			break;
		}
	}
}
void User::My_imformation() {
	int num;
	while (true) {
		cout << endl;
		cout << "=============================================" << endl;
		cout << "1.返回用户主界面 2.修改信息 3.查看信息 4.充值" << endl;
		cout << "=============================================" << endl;
		cout << endl;
		cout << "请选择：";
		cin >> num;
		if (cin.fail()) {
			cin.clear();
			cout << "输入有误！！！请重新输入！！！" << endl;
			cin.ignore(10000, '\n');
			continue;
		}
		switch (num)
		{
		case 1:
			return;
		case 2:
			Change_my_imformation();
			break;
		case 3:
			Look_up_my_imformation();
			break;
		case 4:
			Top_up();
			break;
		default:
			cout << "输入错误！！！请重新输入。" << endl;
			break;
		}
	}
}
void User::Change_my_imformation() {
	int num;
	string new_name, new_address, new_phone_number, y_or_n;
	while (true) {
		cout << endl;
		cout << "请选择需要修改的属性(1.用户名 2.联系方式 3.地址 4.退出)：";
		cin >> num;
		if (cin.fail()) {
			cin.clear();
			cout << "输入错误！！！请重新输入！！！" << endl;
			cin.ignore(10000, '\n');
			continue;
		}
		switch (num)
		{
		case 1:
			cout << "请输入修改后的用户名：";
			cin >> new_name;
			if (mydate.is_repeat_name(new_name)) {
				cout << "该名称重复！！！请重新修改。" << endl;
				continue;
			}
			else {
				cout << "确定要修改你的信息吗？（y/n）";
				cin >> y_or_n;
				if (y_or_n == "y") {
					userName = new_name;
					cout << "修改成功！！！" << endl;
				}
				else {
					cout << "已放弃修改，即将返回上一界面......" << endl;
				}
			}
			break;
		case 2:
			cout << "请输入修改后的联系方式：";
			cin >> new_phone_number;
			cout << "确定要修改你的信息吗？（y/n）";
			cin >> y_or_n;
			if (y_or_n == "y") {
				phoneNumber = new_phone_number;
				cout << "修改成功！！！" << endl;
			}
			else {
				cout << "已放弃修改，即将返回上一界面......" << endl;
			}
			break;
		case 3:
			cout << "请输入修改后的地址：";
			cin >> new_address;
			cout << "确定要修改你的信息吗？（y/n）";
			cin >> y_or_n;
			if (y_or_n == "y") {
				address = new_address;
				cout << "修改成功！！！" << endl;
			}
			else {
				cout << "已放弃修改，即将返回上一界面......" << endl;
			}
			break;
		case 4:
			return;
		default:
			cout << "输入错误！！！请重新输入！！！" << endl;
			break;
		}
	}
}
void User::Look_up_my_imformation() {
	string formula = "0";
	for (Topup_vector::iterator it = mydate.top_up_histroy.begin(); it != mydate.top_up_histroy.end(); it++) {
		if (it->ID == userID) {
			formula += " + " + it->money;
		}
	}
	map<string, string> my_order;
	for (Order_map::iterator it = mydate.order.begin(); it != mydate.order.end(); it++) {
		string number = to_string(it->second.get_number()), price = to_string(it->second.get_unitPrice());
		one_double(price);
		if (it->second.get_sellerID() == userID) {
			if (my_order.find(number) != my_order.end()) {
				my_order[number] += " + " + price;
			}
			else {
				my_order.insert(pair<string, string>(number, price));
			}
		}
		if (it->second.get_buyerID() == userID) {
			if (my_order.find(number) != my_order.end()) {
				my_order[number] += " - " + price;
			}
			else {
				my_order.insert(pair<string, string>(number, "-" + price));
			}
		}
	}
	for (map<string, string>::iterator it = my_order.begin(); it != my_order.end(); it++) {
		formula += " + " + it->first + " * (" + it->second + ")";
	}
	balance = Calculator(formula);
	cout << "*********************" << endl;
	cout << "用户ID：" << userID << endl;
	cout << "用户名：" << userName << endl;
	cout << "联系方式：" << phoneNumber << endl;
	cout << "地址：" << address << endl;
	cout << "余额：" << balance << endl;
	cout << "*********************" << endl;
}
void User::Top_up() {
	int num;
	cout << "请输入充值数目：";
	cin >> num;
	cout << "请扫描下方二维码（bushi" << endl;
	cout << endl;
	Top_up_histroy a_top;
	a_top.ID = userID;
	a_top.money = to_string(num);
	char a_date[11];
	iget_time(a_date);
	string date(a_date);
	a_top.topUpDate = date;
	mydate.top_up_histroy.push_back(a_top);
	cout << "充值成功！！！" << endl;
}


string User::get_ID() {
	return userID;
}
string User::get_name() {
	return userName;
}
string User::get_password() {
	return password;
}
string User::get_phoneNumber() {
	return phoneNumber;
}
string User::get_address() {
	return address;
}
string User::get_userState() {
	return userState;
}
double User::get_balance() {
	return balance;
}
void User::add_balance(double b) {
	balance += b;
}
void User::minus_balance(double b) {
	balance -= b;
}