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
		cout << endl;
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
			cout << "������󣡣������������롣" << endl;
			break;
		}
	}
}

void User_login() {
	bool is_find_name = false;
	string userName, password;
	cout << "�������û�����";
	cin >> userName;
	cout << "�������û����룺";
	cin >> password;
	for (User_map::iterator it = mydate.user.begin(); it != mydate.user.end(); it++) {
		if (it->second.get_name() == userName) {
			is_find_name = true;
			if (it->second.get_password() == password) {
				it->second.Choice();
				return;
			}
			else {
				cout << "������󣡣���" << endl;
				return;
			}
			break;
		}
	}
	if (!is_find_name) cout << "���û��������ڣ�����" << endl;
}
void User_register() {
	string userID, userName, password, phoneNumber, address, userState = userState_a, y_or_n;
	double balance = 0;
	cout << "�������û�����";
	cin >> userName;
	userID = mydate.new_userID();
	if (userID == "�û���������������") {
		cout << userID << endl;
		return;
	}
	while (mydate.is_repeat_name(userName)) {
		cout << "�û����ظ����������������룡����" << endl;
		cout << "�������û�����";
		cin >> userName;
	}
	cout << "���������룺";
	cin >> password;
	cout << "������绰���룺";
	cin >> phoneNumber;
	cout << "�������ַ��";
	cin >> address;
	cout << "ȷ��ע����û���" << endl;
	cout << "(y/n):";
	cin >> y_or_n;
	if (y_or_n == "n") {
		cout << "�ѷ���ע�ᣡ����" << endl;
		return;
	}
	User new_user(userID, userName, password, phoneNumber, address, balance, userState);
	mydate.user.insert(pair<string, User>(userID, new_user));
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
			mydate.admin.Choice();
		}
		else {
			cout << "����Ա������������󣡣�������������һ����......" << endl;
		}
		break;
	}
}