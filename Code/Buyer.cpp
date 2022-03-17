#include"Buyer.h"
#include"Datebase.h"
#include"Constant.h"
#include"iSQL.h"
#include<iostream>
using namespace std;

extern Datebase mydate;

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
	string instruction;
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
		case 1://Done
			instruction = "SELECT * FROM commodity";
			buyer_instruction(instruction, userID);
			break;
		case 2:
		{
			int number, restnumber;
			string commodityID, orderID, price, y_or_n;
			cout << "������Ҫ�������ƷID��";
			cin >> commodityID;
			Commodity_map::iterator a_commodity = mydate.commodity.find(commodityID);
			if (a_commodity == mydate.commodity.end() || a_commodity->second.get_state() == commodityState_r) {
				cout << "���۵���Ʒ���Ҳ�������Ʒ������" << endl;
				break;
			}
			cout << "������Ҫ�������Ʒ������";
			cin >> number;
			if (number <= 0) {
				cout << "�������Ʒ��������Ϊ������������" << endl;
				break;
			}
			else if (number > a_commodity->second.get_number()) {
				cout << "�������Ʒ����������Ʒ����������" << endl;
				break;
			}
			if (balance < a_commodity->second.get_price() * number) {
				cout << "���㣡����" << endl;
				break;
			}
			cout << "ȷ��Ҫ�������Ʒ�𣿣���(y/n):";
			cin >> y_or_n;
			if (y_or_n != "y") {
				cout << "�ѷ������򣡣���" << endl;
				break;
			}
			orderID = mydate.new_orderID();
			price = to_string(a_commodity->second.get_price());
			for (unsigned int i = 0; i < price.length(); i++) {
				if (price[i] == '.') {
					price = price.substr(0, i + 2);
				}
			}
			char now_time[11];
			iget_time(now_time);
			string buydate(now_time);
			instruction = "INSERT INTO order VALUES (" + orderID + "," + a_commodity->second.get_commodityID()
				+ "," + price + "," + to_string(number) + "," + buydate + "," + a_commodity->second.get_sellerID() + "," + userID + ")";
			buyer_instruction(instruction, userID);
			restnumber = a_commodity->second.get_number() - number;
			instruction = "UPDATE commodity SET number = " + to_string(restnumber) + "WHERE commodityID = " + commodityID;
			buyer_instruction(instruction, userID);
			if (restnumber == 0) {
				instruction = "UPDATE commodity SET commodityState = remove WHERE commodityID = " + commodityID;
				seller_instruction(instruction, a_commodity->second.get_sellerID());
			}
			mydate.user[userID].minus_balance(a_commodity->second.get_price() * number);
			mydate.user[a_commodity->second.get_sellerID()].add_balance(a_commodity->second.get_price() * number);
			break;
		}
		case 3://Done
		{
			string commodityName;
			cout << "������Ҫ���ҵ���Ʒ���ƣ�";
			cin >> commodityName;
			instruction = "SELECT * FROM commodity WHERE commodityName CONTAINS " +commodityName;
			buyer_instruction(instruction, userID);
			break;
		}
		case 4://Done
			instruction = "SELECT * FROM order";
			buyer_instruction(instruction, userID);
			break;
		case 5://Done
		{
			string commodityID;
			cout << "��������Ѱ�ҵ���Ʒ��ID��";
			cin >> commodityID;
			instruction = "SELECT * FROM commodity WHERE commodityID CONTAINS " + commodityID;
			buyer_instruction(instruction, userID);
			break;
		}
		case 6:
			return;
		default:
			cout << "������󣡣������������룡����" << endl;
			break;
		}
	}
}