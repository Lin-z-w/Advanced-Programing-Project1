#include"Buyer.h"
#include<iostream>
using namespace std;

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
	while (true) {
		cout << endl;
		cout << "=======================================================================================" << endl;
		cout << "1.�鿴��Ʒ�б� 2.������Ʒ 3.������Ʒ 4.�鿴��ʷ���� 5.�鿴��Ʒ��ϸ��Ϣ 6.�����û�������" << endl;
		cout << "=======================================================================================" << endl;
		cout << endl;
		cout << "��ѡ��";
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
			
			break;
		case 2:
			
			break;
		case 3:
			
			break;
		case 4:
			
			break;
		case 5:
			
			break;
		case 6:
			return;
		default:
			cout << "������󣡣������������룡����" << endl;
			break;
		}
	}
}