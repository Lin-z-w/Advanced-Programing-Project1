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
			
			break;
		case 2:
		
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
			mydate.admin.choice();
		}
		else {
			cout << "管理员姓名或密码错误！！！即将返回上一界面......" << endl;
		}
		break;
	}
}