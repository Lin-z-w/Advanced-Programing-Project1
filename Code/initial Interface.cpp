#include"Initial Interface.h"
#include"Constant.h"
#include<iostream>
using namespace std;

extern Datebase mydate;

void Choose_identity() {
	int choice = 0;
	while (true) {
		cout << "=============================================" << endl;
		cout << "1.�û���¼ 2.�û�ע�� 3.����Ա��¼ 4.�˳�����" << endl;
		cout << "=============================================" << endl;
		cout << "��ѡ��";
		cin >> choice;
		if (cin.fail()) {
			cin.clear();
			cout << "������󣡣������������롣" << endl;
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
			cout << "������󣡣������������롣" << endl;
			break;
		}
	}
}

void Administrator_login() {
	string name, password;
	while (true) {
		cout << "���������Ա������";
		cin >> name;
		if (cin.fail()) {
			cin.clear();
			cout << "������󣡣������������롣" << endl;
			cin.ignore(10000, '\n');
			continue;
		}
		cout << "���������룺";
		cin >> password;
		if (cin.fail()) {
			cin.clear();
			cout << "������󣡣������������롣" << endl;
			cin.ignore(10000, '\n');
			continue;
		}
		if (name == mydate.admin.get_name() && password == mydate.admin.get_password()) {
			mydate.admin.choice();
		}
		else {
			cout << "����Ա������������󣡣�������������һ����......" << endl;
		}
		break;
	}
}