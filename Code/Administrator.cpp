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
		cout << "1.�鿴������Ʒ 2.������Ʒ 3.�鿴���ж��� 4.�鿴�����û� 5.����û� 6.�¼���Ʒ 7.ע��" << endl;
		cout << "====================================================================================" << endl;
		cout << endl;
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
			instruction = "SELECT * FROM order";
			admin_instruction(instruction);
			break;
		case 4:
			instruction = "SELECT * FROM user";
			admin_instruction(instruction);
			break;
		case 5: {
			cout << "����Ҫ������û�ID��";
			cin >> userID;
			User_map::iterator u_it = mydate.user.find(userID);
			if (u_it == mydate.user.end()) {
				cout << "���û������ڣ�����" << endl;
				break;
			}
			cout << "ȷ��Ҫ������û���" << endl;
			cout << "====================================================================================================================" << endl;
			cout << left << setw(10) << "�û�ID" << setw(userName_len + 4) << "�û���" 
				<< setw(phoneNumber_len + 4) << "��ϵ��ʽ" << setw(address_len + 4) << "��ַ"
				<< setw(10) << "Ǯ�����" << endl;
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
				cout << "�û�������" << endl;
			}
			else {
				cout << "�ѷ����޸ģ�����������һ����......" << endl;
			}
			break;
		}
		case 6: {
			cout << "����Ҫ�¼ܵ���ƷID��";
			cin >> commodityID;
			Commodity_map::iterator c_it = mydate.commodity.find(commodityID);
			if (c_it == mydate.commodity.end()) {
				cout << "�����ڸ���Ʒ������" << endl;
				break;
			}
			cout << "ȷ��Ҫ�¼ܸ���Ʒ��" << endl;
			cout << "****************************************************************************************************" << endl;
			cout << left << setw(ID_len + 6) << "��ƷID" << setw(commodityName_len + 4) << "����"
				<< setw(10) << "�۸�" << setw(14) << "�ϼ�ʱ��" << setw(ID_len + 6) << "����ID"
				<< setw(10) << "����" << setw(10) << "��Ʒ״̬" << endl;
			cout << left << setw(ID_len + 6) << c_it->second.commodityID << setw(commodityName_len + 4) << c_it->second.commodityName
				<< setw(10) << c_it->second.price << setw(14) << c_it->second.addedDate << setw(ID_len + 6) << c_it->second.sellerID
				<< setw(10) << c_it->second.sellerID << setw(10) << c_it->second.state << endl;
			cout << "****************************************************************************************************" << endl;
			cout << "(y/n):";
			cin >> y_or_n;
			if (y_or_n == "y") {
				instruction = "UPDATE commodity SET commodityState = remove WHERE commodityID = M001";
				admin_instruction(instruction);
				cout << "��Ʒ�¼����" << endl;
			}
			else {
				cout << "�ѷ����¼ܸ���Ʒ,����������һ����......" << endl;
			}
			break;
		}
		case 7:
			return;
		default:
			cout << "������󣡣�������������." << endl;
			break;
		}
	}
}