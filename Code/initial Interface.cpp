#include"Initial Interface.h"
#include"Constant.h"
#include<iostream>
using namespace std;

void choose_identity() {
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
			return;
			break;
		case 4:
			
			break;
		default:
			cout << "输入错误！！！请重新输入。" << endl;
			choose_identity();
			break;
		}
		choose_identity();
	}
}