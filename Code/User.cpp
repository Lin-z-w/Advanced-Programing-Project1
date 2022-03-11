#include"User.h"
#include"Buyer.h"
#include"Seller.h"
#include"Datebase.h"
#include<iostream>

extern Datebase mydate;

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

void User::Choice() {
	string instruction;
	int num;
	while (true) {
		cout << endl;
		cout << "===============================================" << endl;
		cout << "1.ע����¼ 2.������� 3.�������� 4.������Ϣ����" << endl;
		cout << "===============================================" << endl;
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
			cout << "������󣡣������������롣" << endl;
			break;
		}
	}
}
void User::My_imformation() {
	int num;
	while (true) {
		cout << endl;
		cout << "=============================================" << endl;
		cout << "1.�����û������� 2.�޸���Ϣ 3.�鿴��Ϣ 4.��ֵ" << endl;
		cout << "=============================================" << endl;
		cout << endl;
		cout << "��ѡ��";
		cin >> num;
		if (cin.fail()) {
			cin.clear();
			cout << "�������󣡣������������룡����" << endl;
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
			cout << "������󣡣������������롣" << endl;
			break;
		}
	}
}
void User::Change_my_imformation() {
	int num;
	string new_name, new_address, new_phone_number, y_or_n;
	while (true) {
		cout << endl;
		cout << "��ѡ����Ҫ�޸ĵ�����(1.�û��� 2.��ϵ��ʽ 3.��ַ 4.�˳�)��";
		cin >> num;
		if (cin.fail()) {
			cin.clear();
			cout << "������󣡣������������룡����" << endl;
			cin.ignore(10000, '\n');
			continue;
		}
		switch (num)
		{
		case 1:
			cout << "�������޸ĺ���û�����";
			cin >> new_name;
			if (mydate.is_repeat_name(new_name)) {
				cout << "�������ظ��������������޸ġ�" << endl;
				continue;
			}
			else {
				cout << "ȷ��Ҫ�޸������Ϣ�𣿣�y/n��";
				cin >> y_or_n;
				if (y_or_n == "y") {
					userName = new_name;
					cout << "�޸ĳɹ�������" << endl;
				}
				else {
					cout << "�ѷ����޸ģ�����������һ����......" << endl;
				}
			}
			break;
		case 2:
			cout << "�������޸ĺ����ϵ��ʽ��";
			cin >> new_phone_number;
			cout << "ȷ��Ҫ�޸������Ϣ�𣿣�y/n��";
			cin >> y_or_n;
			if (y_or_n == "y") {
				phoneNumber = new_phone_number;
				cout << "�޸ĳɹ�������" << endl;
			}
			else {
				cout << "�ѷ����޸ģ�����������һ����......" << endl;
			}
			break;
		case 3:
			cout << "�������޸ĺ�ĵ�ַ��";
			cin >> new_address;
			cout << "ȷ��Ҫ�޸������Ϣ�𣿣�y/n��";
			cin >> y_or_n;
			if (y_or_n == "y") {
				address = new_address;
				cout << "�޸ĳɹ�������" << endl;
			}
			else {
				cout << "�ѷ����޸ģ�����������һ����......" << endl;
			}
			break;
		case 4:
			return;
		default:
			cout << "������󣡣������������룡����" << endl;
			break;
		}
	}
}
void User::Look_up_my_imformation() {
	cout << "*********************" << endl;
	cout << "�û�ID��" << userID << endl;
	cout << "�û�����" << userName << endl;
	cout << "��ϵ��ʽ��" << phoneNumber << endl;
	cout << "��ַ��" << address << endl;
	cout << "��" << balance << endl;
	cout << "*********************" << endl;
}
void User::Top_up() {
	int num;
	cout << "�������ֵ��Ŀ��";
	cin >> num;
	cout << "��ɨ���·���ά�루bushi" << endl;
	balance += num;
	cout << "��ֵ�ɹ�������" << endl;
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