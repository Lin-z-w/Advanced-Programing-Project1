#include<iostream>
#include<iomanip>
#include<fstream>
#include"Constant.h"
#include"Datebase.h"
#include"iSQL.h"
using namespace std;

extern Datebase mydate;
void get_accurate_time(char* p) {
    time_t t = time(0);
    char temp[22];
    strftime(temp, sizeof(temp), "%Y-%m-%d %H:%M:%S: ", localtime(&t));
    strcpy(p, temp);
}
void iget_time(char* p) {
	time_t t = time(0);
	char temp[11];
	strftime(temp, sizeof(temp), "%Y-%m-%d", localtime(&t));
	strcpy(p, temp);
}
void commond_in_file(string instruction) {
	char now_time[22];
	get_accurate_time(now_time);
	ofstream out_file("commands.txt", ios::app);
	if (!out_file) {
		cout << "�ļ���ʧ�ܣ�����" << endl;
	}
	out_file << now_time;
	out_file << instruction << endl;
	out_file.close();
}

void admin_instruction(string instruction) {
	commond_in_file(instruction);
	string commodityID, userID;
	bool is_find = false;
	switch (instruction[0])
	{
	case 'S':
	{
		if (instruction == "SELECT * FROM commodity") {
			cout << "**********************************************************************************************" << endl;
			//printf("%-10s %-20s %-6s %-15s %-10s %-10s\n", "ID", "����", "�۸�", "�ϼ�ʱ��", "����ID","��Ʒ״̬");
			cout << left << setw(ID_len + 6) << "��ƷID" << setw(commodityName_len + 4) << "����"
				<< setw(10) << "�۸�" << setw(14) << "�ϼ�ʱ��" << setw(ID_len + 6) << "����ID"
				<< setw(10) << "����" << setw(10) << "��Ʒ״̬" << endl;
			for (Commodity_map::iterator it = mydate.commodity.begin(); it != mydate.commodity.end(); it++) {
				cout << left << setw(ID_len + 6) << it->second.commodityID << setw(commodityName_len + 4) << it->second.commodityName
					<< setw(10) << fixed << setprecision(1) << it->second.price << setw(14) << it->second.addedDate << setw(ID_len + 6) << it->second.sellerID
					<< setw(10) << it->second.number << setw(10) << it->second.state << endl;
			}
			cout << "**********************************************************************************************" << endl;
		}
		else if (instruction == "SELECT * FROM order") {
			cout << "*************************************************************************" << endl;
			cout << left << setw(10) << "����ID" << setw(10) << "��ƷID" << setw(10) << "��Ʒ����" 
				<< setw(10) << "��Ʒ����"
				<< setw(14) << "����ʱ��" << setw(10) << "����ID" << setw(10) << "���ID" << endl;
			for (Order_map::iterator it = mydate.order.begin(); it != mydate.order.end(); it++) {
				cout << left << setw(10) << it->second.orderID << setw(10) << it->second.commodityID << setw(10) << fixed << setprecision(1) << it->second.unitPrice
					<< setw(10) << it->second.number 
					<< setw(14) << it->second.date << setw(10) << it->second.sellerID << setw(10) << it->second.buyerID << endl;
			}
			cout << "*************************************************************************" << endl;
		}
		else if (instruction == "SELECT * FROM user") {
			cout << "********************************************************************************************************************************************" << endl;
			//�û�ID,�û���,����,��ϵ��ʽ,��ַ,Ǯ�����,�û�״̬
			cout << left << setw(10) << "�û�ID" << setw(userName_len + 4) << "�û���" << setw(password_len + 4) << "����"
				<< setw(phoneNumber_len + 4) << "��ϵ��ʽ" << setw(address_len + 4) << "��ַ"
				<< setw(10) << "Ǯ�����" << setw(10) << "�û�״̬" << endl;
			for (User_map::iterator it = mydate.user.begin(); it != mydate.user.end(); it++) {
				cout << left << setw(10) << it->second.userID << setw(userName_len + 4) << it->second.userName << setw(password_len + 4) << it->second.password
					<< setw(phoneNumber_len + 4) << it->second.phoneNumber << setw(address_len + 4) << it->second.address
					<< setw(10) << it->second.balance << setw(10) << it->second.userState << endl;
			}
			cout << "********************************************************************************************************************************************" << endl;
		}
		else {
			string a_name = instruction.substr(53);
			int a_name_len = a_name.length();
			bool is_find = false;
			cout << "****************************************************************************************" << endl;
			for (Commodity_map::iterator it = mydate.commodity.begin(); it != mydate.commodity.end(); it++) {
				////����Ϊ1��ȫƥ��
				//if (a_name_len == 1) {
				//	if (a_name == it->second.commedityName) {
				//		if (!is_find) {
				//			cout << "**********************************************************************************************" << endl;
				//			cout << left << setw(ID_len + 6) << "��ƷID" << setw(commodityName_len + 4) << "����"
				//				<< setw(10) << "�۸�" << setw(14) << "�ϼ�ʱ��"
				//				<< setw(10) << "����" << setw(10) << "��Ʒ״̬" << endl;
				//		}
				//		is_find = true;
				//		cout << left << setw(ID_len + 6) << it->second.commodityID << setw(commodityName_len + 4) << it->second.commedityName
				//			<< setw(10) << it->second.price << setw(14) << it->second.addedDate
				//			<< setw(10) << it->second.number << setw(10) << it->second.state << endl;
				//	}
				//}
				////���ȴ���1ģ��ƥ��
				//else {
				if (!(it->second.commodityName.find(a_name) == string::npos)) {
					if (!is_find) {
						cout << left << setw(ID_len + 6) << "��ƷID" << setw(commodityName_len + 4) << "����"
							<< setw(10) << "�۸�" << setw(14) << "�ϼ�ʱ��"
							<< setw(10) << "����" << setw(10) << "��Ʒ״̬" << endl;
					}
					is_find = true;
					cout << left << setw(ID_len + 6) << it->second.commodityID << setw(commodityName_len + 4) << it->second.commodityName
						<< setw(10) << fixed << setprecision(1) << it->second.price << setw(14) << it->second.addedDate
						<< setw(10) << it->second.number << setw(10) << it->second.state << endl;
				}
				//}
			}
			if (!is_find) cout << "û���ҵ���Ҫ����Ʒ������" << endl;
			cout << "****************************************************************************************" << endl;
		}
	}
		break;
	case 'U':
		if (instruction[7] == 'c') {
			if (instruction[51] == 'c') {
				commodityID = instruction.substr(instruction.length() - 4);
				mydate.commodity[commodityID].state = "remove";
			}
			else {
				userID = instruction.substr(instruction.length() - 4);
				for (Commodity_map::iterator it = mydate.commodity.begin(); it != mydate.commodity.end(); it++) {
					if (it->second.sellerID == userID) {
						it->second.state = "remove";
					}
				}
			}
		}
		else if (instruction[7] == 'u') {
			userID = instruction.substr(instruction.length() - 4);
			mydate.user[userID].userState = "inactive";
		}
		break;
	default:
		cout << "ָ�����󣡣���" << endl;
		break;
	}
}
void seller_instruction(string instruction, string sellerID) {
	string y_or_n;
	commond_in_file(instruction);
	switch (instruction[0])
	{
	case 'S':
	{
		if (instruction == "SELECT * FROM commodity") {
			cout << "**********************************************************************************************" << endl;
			//printf("%-10s %-20s %-6s %-15s %-10s %-10s\n", "ID", "����", "�۸�", "�ϼ�ʱ��", "����ID","��Ʒ״̬");
			cout << left << setw(ID_len + 6) << "��ƷID" << setw(commodityName_len + 4) << "����"
				<< setw(10) << "�۸�" << setw(14) << "�ϼ�ʱ��"
				<< setw(10) << "����" << setw(10) << "��Ʒ״̬" << endl;
			for (Commodity_map::iterator it = mydate.commodity.begin(); it != mydate.commodity.end(); it++) {
				if (sellerID == it->second.sellerID) {
					cout << left << setw(ID_len + 6) << it->second.commodityID << setw(commodityName_len + 4) << it->second.commodityName
						<< setw(10) << fixed << setprecision(1) << it->second.price << setw(14) << it->second.addedDate
						<< setw(10) << it->second.number << setw(10) << it->second.state << endl;
				}
			}
			cout << "**********************************************************************************************" << endl;
		}
		else if (instruction == "SELECT * FROM order") {
			cout << "*************************************************************************" << endl;
			cout << left << setw(10) << "����ID" << setw(10) << "��ƷID"
				<< setw(10) << "��Ʒ����"
				<< setw(10) << "��Ʒ����"
				<< setw(14) << "����ʱ��" << setw(10) << "����ID" << endl;
			for (Order_map::iterator it = mydate.order.begin(); it != mydate.order.end(); it++) {
				if (sellerID == it->second.get_sellerID()) {
					cout << left << setw(10) << it->second.get_orderID() << setw(10) << it->second.get_commodityID()
						<< setw(10) << fixed << setprecision(1) << it->second.get_unitPrice()
						<< setw(10) << it->second.get_number()
						<< setw(14) << it->second.get_date() << setw(10) << it->second.get_sellerID() << endl;
				}
			}
			cout << "*************************************************************************" << endl;
		}
	}
	break;
	case 'U': 
	{
		if (instruction[21] == 'c') {
			string commodityID = instruction.substr(instruction.length() - 4, 4);
			Commodity_map::iterator a_commodity = mydate.commodity.find(commodityID);
			if (a_commodity == mydate.commodity.end() || a_commodity->second.get_sellerID() != sellerID) {
				cout << "����������Ʒ��δ�ҵ�����Ʒ������" << endl;
				return;
			}
			cout << "��Ʒ��Ϣ���£�" << endl;
			cout << "************************" << endl;
			cout << "��Ʒ���ƣ�" << a_commodity->second.get_commodityName() << endl;
			cout << "��Ʒ�۸�" << fixed << setprecision(1) << a_commodity->second.get_price() << endl;
			cout << "��Ʒ������" << a_commodity->second.get_number() << endl;
			cout << "��Ʒ������" << a_commodity->second.get_description() << endl;
			cout << "************************" << endl;
			cout << "��ȷ��Ҫ�¼ܸ���Ʒ�𣿣�����y/n��";
			cin >> y_or_n;
			if (y_or_n == "n") {
				cout << "�ѷ����¼ܸ���Ʒ������";
				return;
			}
			cout << "��Ʒ�¼ܳɹ�������" << endl;
			a_commodity->second.remove_it();
		}
		break;
	}
	case 'I': 
	{
		string commodityName, description;
		double price = 0;
		int cnt = 0, past = 30, number = 0;
		for (unsigned int cur = 30; cur < instruction.length(); cur++) {
			if (instruction[cur] == ',') {
				switch (cnt)
				{
				case 0:
					commodityName = instruction.substr(past, cur - past);
					break;
				case 1:
					price = atof(instruction.substr(past, cur - past).c_str());
					break;
				case 2:
					number = atoi(instruction.substr(past, cur - past).c_str());
					description = instruction.substr(cur + 1, instruction.length() - cur - 2);
					break;
				default:
					break;
				}
				cnt++;
				past = cur + 1;
			}
		}
		cout << "��ȷ�Ϸ�������Ʒ��Ϣ���󣡣���" << endl;
		cout << "**************************************" << endl;
		cout << "��Ʒ���ƣ�" << commodityName << endl;
		cout << "��Ʒ�۸�" << price << endl;
		cout << "��Ʒ������" << number << endl;
		cout << "��Ʒ������" << description << endl;
		cout << "**************************************" << endl;
		cout << "ȷ��Ҫ��������Ʒ�𣿣���(y/n)";
		while (true) {
			cin >> y_or_n;
			if (y_or_n == "n") {
				cout << "�ѷ�����������Ʒ������" << endl;
				return;
			}
			else if (y_or_n != "y") {
				cout << "������y����n��������" << endl;
				continue;
			}
			break;
		}
		char now_time[11] = {};
		iget_time(now_time);
		string commodityID = mydate.new_commodityID(), addDate(now_time);
		Commodity new_commodity(commodityID, commodityName, price, number, description, sellerID, addDate, commodityState_o);
		mydate.commodity.insert(pair<string, Commodity>(commodityID, new_commodity));
	}
	break;
	default:
		cout << "ָ�����󣡣���" << endl;
		break;
	}
}
void buyer_instruction(string instruction, string buyerID) {
	commond_in_file(instruction);
	switch (instruction[0])
	{
	case 'S':
	{
		if (instruction == "SELECT * FROM commodity") {
			cout << "**********************************************************************************************" << endl;
			//printf("%-10s %-20s %-6s %-15s %-10s %-10s\n", "ID", "����", "�۸�", "�ϼ�ʱ��", "����ID","��Ʒ״̬");
			cout << left << setw(ID_len + 6) << "��ƷID" << setw(commodityName_len + 4) << "����"
				<< setw(10) << "�۸�" << setw(14) << "�ϼ�ʱ��"
				<< setw(10) << "����" << setw(10) << "����ID" << endl;
			for (Commodity_map::iterator it = mydate.commodity.begin(); it != mydate.commodity.end(); it++) {
				if (it->second.get_state() == commodityState_o) {
					cout << left << setw(ID_len + 6) << it->second.get_commodityID() << setw(commodityName_len + 4) << it->second.get_commodityName()
						<< setw(10) << fixed << setprecision(1) << it->second.get_price() << setw(14) << it->second.get_addedDate()
						<< setw(10) << it->second.get_number() << setw(10) << it->second.get_sellerID() << endl;
				}
			}
			cout << "**********************************************************************************************" << endl;
		}
		else if (instruction == "SELECT * FROM order") {
			cout << "*************************************************************************" << endl;
			cout << left << setw(10) << "����ID" << setw(10) << "��ƷID"
				<< setw(10) << "��Ʒ����"
				<< setw(10) << "��Ʒ����"
				<< setw(14) << "����ʱ��" << setw(10) << "����ID" << endl;
			for (Order_map::iterator it = mydate.order.begin(); it != mydate.order.end(); it++) {
				if (buyerID == it->second.get_buyerID()) {
					cout << left << setw(10) << it->second.get_orderID() << setw(10) << it->second.get_commodityID()
						<< setw(10) << fixed << setprecision(1) << it->second.get_unitPrice()
						<< setw(10) << it->second.get_number()
						<< setw(14) << it->second.get_date() << setw(10) << it->second.get_sellerID() << endl;
				}
			}
			cout << "*************************************************************************" << endl;
		}
		else {
			if (instruction[39] == 'I') {
				Commodity_map::iterator a_commodity = mydate.commodity.find(instruction.substr(instruction.length() - 4, 4));
				if (a_commodity != mydate.commodity.end() && a_commodity->second.get_state() != commodityState_r) {
					cout << "*********************************" << endl;
					cout << "��Ʒ���ƣ�" << a_commodity->second.get_commodityName() << endl;
					cout << "��Ʒ�۸�" << a_commodity->second.get_price() << endl;
					cout << "��Ʒ������" << a_commodity->second.get_description() << endl;
					cout << "�ϼ�ʱ�䣺" << a_commodity->second.get_addedDate() << endl;
					cout << "����ID��" << a_commodity->second.get_sellerID() << endl;
					cout << "*********************************" << endl;
				}
				else {
					cout << "�����е���Ʒû���ҵ�����Ҫ����Ʒ����������������һ���棡����" << endl;
				}
			}
			else {
				string commodityName = instruction.substr(53, instruction.length() - 53);
				bool is_find = false;
				cout << "****************************************************************************************" << endl;
				for (Commodity_map::iterator it = mydate.commodity.begin(); it != mydate.commodity.end(); it++) {
					if (it->second.get_commodityName().find(commodityName) != string::npos && it->second.get_state() != commodityState_r) {
						if (!is_find) {
							cout << left << setw(ID_len + 6) << "��ƷID" << setw(commodityName_len + 4) << "����"
								<< setw(10) << "�۸�" << setw(14) << "�ϼ�ʱ��"
								<< setw(10) << "����" << setw(10) << "��Ʒ״̬" << endl;
						}
						is_find = true;
						cout << left << setw(ID_len + 6) << it->second.get_commodityID() << setw(commodityName_len + 4) << it->second.get_commodityName()
							<< setw(10) << fixed << setprecision(1) << it->second.get_price() << setw(14) << it->second.get_addedDate()
							<< setw(10) << it->second.get_number() << setw(10) << it->second.get_state() << endl;
					}
				}
				if (!is_find) cout << "û���ҵ���Ҫ����Ʒ������" << endl;
				cout << "****************************************************************************************" << endl;
			}
		}
		break;
	}
	case 'I':
	{
		//instruction = "INSERT INTO order VALUES (" + orderID + "," + a_commodity->second.get_commodityID()
			//+ "," + price + "," + to_string(number) + "," + buydate + "," + a_commodity->second.get_sellerID() + "," + userID + ")";
		string orderID, commodityID, date, sellerID, buyerID, information = instruction.substr(26, instruction.length() - 27);
		double unitPrice = 0;
		int cnt = 0, past = 0, number = 0;
		for (int cur = 0; cur < information.length(); cur++) {
			if (information[cur] == ',') {
				switch (cnt)
				{
				case 0:
					orderID = information.substr(past, cur - past);
					break;
				case 1:
					commodityID = information.substr(past, cur - past);
					break;
				case 2:
					unitPrice = atof(information.substr(past, cur - past).c_str());
					break;
				case 3:
					number = atoi(information.substr(past, cur - past).c_str());
					break;
				case 4:
					date = information.substr(past, cur - past);
					break;
				case 5:
					sellerID = information.substr(past, cur - past);
					buyerID = information.substr(cur + 1);
					break;
				default:
					break;
				}
				cnt++;
				past = cur + 1;
			}
		}
		Order a_order(orderID, commodityID, unitPrice, number, date, sellerID, buyerID);
		mydate.order.insert(pair<string, Order>(orderID, a_order));
		break;
	}
	case 'U':
	{
		//instruction = "UPDATE commodity SET number = " + to_string(restnumber) + "WHERE commodityID = " + commodityID;
		string commodityID = instruction.substr(instruction.length() - 4, 4);
		int cnt = 30, number = 0;
		while (instruction[cnt] != ' ') {
			cnt++;
		}
		number = atoi(instruction.substr(30, cnt - 30).c_str());
		mydate.commodity[commodityID].set_number(number);
		break;
	}
	default:
		break;
	}
}
