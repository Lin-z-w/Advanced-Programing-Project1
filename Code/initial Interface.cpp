#include"Initial Interface.h"
#include"Constant.h"
#include<iostream>
using namespace std;

extern Datebase mydate;

void Choose_identity() {
	int choice = 0;
	while (true) {
		cout << "=============================================" << endl;
		cout << "1.用户登录 2.用户注册 3.管理员登录 4.退出程序" << endl;
		cout << "=============================================" << endl;
		cout << endl;
		cout << "请选择：";
		cin >> choice;
		if (cin.fail()) {
			cin.clear();
			cout << "输入错误！！！请重新输入。" << endl;
			cin.ignore(10000, '\n');
			continue;
		}
		switch (choice)
		{
		case 1:
			User_login();
			break;
		case 2:
			User_register();
			break;
		case 3:
			Administrator_login();
			break;
		case 4:
			return;
			break;
		default:
			cout << "输入错误！！！请重新输入。" << endl;
			break;
		}
	}
}

void User_login() {
	bool is_find_name = false;
	string userName, password;
	cout << "请输入用户名：";
	cin >> userName;
	cout << "请输入用户密码：";
	cin >> password;
	for (User_map::iterator it = mydate.user.begin(); it != mydate.user.end(); it++) {
		if (it->second.get_name() == userName) {
			is_find_name = true;
			if (it->second.get_password() == password) {
				it->second.Choice();
				return;
			}
			else {
				cout << "密码错误！！！" << endl;
				return;
			}
			break;
		}
	}
	if (!is_find_name) cout << "该用户名不存在！！！" << endl;
}
void User_register() {
	string userID, userName, password, phoneNumber, address, userState = userState_a, y_or_n;
	double balance = 0;
	cout << "请输入用户名：";
	cin >> userName;
	userID = mydate.new_userID();
	if (userID == "用户人数已满！！！") {
		cout << userID << endl;
		return;
	}
	while (mydate.is_repeat_name(userName)) {
		cout << "用户名重复！！！请重新输入！！！" << endl;
		cout << "请输入用户名：";
		cin >> userName;
	}
	cout << "请输入密码：";
	cin >> password;
	cout << "请输入电话号码：";
	cin >> phoneNumber;
	cout << "请输入地址：";
	cin >> address;
	cout << "确定注册该用户吗？" << endl;
	cout << "(y/n):";
	cin >> y_or_n;
	if (y_or_n == "n") {
		cout << "已放弃注册！！！" << endl;
		return;
	}
	User new_user(userID, userName, password, phoneNumber, address, balance, userState);
	mydate.user.insert(pair<string, User>(userID, new_user));
}
void Administrator_login() {
	string name, password;
	while (true) {
		cout << "请输入管理员姓名：";
		cin >> name;
		if (cin.fail()) {
			cin.clear();
			cout << "输入错误！！！请重新输入。" << endl;
			cin.ignore(10000, '\n');
			continue;
		}
		cout << "请输入密码：";
		cin >> password;
		if (cin.fail()) {
			cin.clear();
			cout << "输入错误！！！请重新输入。" << endl;
			cin.ignore(10000, '\n');
			continue;
		}
		if (name == mydate.admin.get_name() && password == mydate.admin.get_password()) {
			mydate.admin.Choice();
		}
		else {
			cout << "管理员姓名或密码错误！！！即将返回上一界面......" << endl;
		}
		break;
	}
}