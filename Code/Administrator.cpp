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
		cout << "1.�鿴������Ʒ 2.������Ʒ 3.�鿴���ж��� 4.�鿴�����û� 5.ɾ���û� 6.�¼���Ʒ 7.ע��" << endl;
		cout << "====================================================================================" << endl;
		cout << "�����������";
		cin >> num;
		if (cin.fail()) {
			cin.clear();
			cout << "������󣡣������������롣" << endl;
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
			cout << "��������Ʒ���ƣ�";
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
			cout << "������󣡣�������������." << endl;
			break;
		}
	}
}