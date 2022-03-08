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
					<< setw(10) << it->second.price << setw(14) << it->second.addedDate << setw(ID_len + 6) << it->second.sellerID
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
				cout << left << setw(10) << it->second.orderID << setw(10) << it->second.commodityID << setw(10) << it->second.number 
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
						<< setw(10) << it->second.price << setw(14) << it->second.addedDate
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
void seller_instruction(string instruction, string sellerid) {
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
				if (sellerid == it->second.sellerID) {
					cout << left << setw(ID_len + 6) << it->second.commodityID << setw(commodityName_len + 4) << it->second.commodityName
						<< setw(10) << it->second.price << setw(14) << it->second.addedDate
						<< setw(10) << it->second.number << setw(10) << it->second.state << endl;
				}
			}
			cout << "**********************************************************************************************" << endl;
		}
		else if (instruction == "SELECT * FROM order") {

		}
		else if (instruction == "SELECT * FROM user") {

		}
		else {
		//	string a_name = instruction.substr(54);
		//	int a_name_len = a_name.length();
		//	bool is_find = false;
		//	cout << "**********************************************************************************************" << endl;
		//	for (Commodity_map::iterator it = mydate.commodity.begin(); it != mydate.commodity.end(); it++) {
		//		////����Ϊ1��ȫƥ��
		//		//if (a_name_len == 1) {
		//		//	if (a_name == it->second.commedityName) {
		//		//		if (!is_find) {
		//		//			cout << "**********************************************************************************************" << endl;
		//		//			cout << left << setw(ID_len + 6) << "��ƷID" << setw(commodityName_len + 4) << "����"
		//		//				<< setw(10) << "�۸�" << setw(14) << "�ϼ�ʱ��"
		//		//				<< setw(10) << "����" << setw(10) << "��Ʒ״̬" << endl;
		//		//		}
		//		//		is_find = true;
		//		//		cout << left << setw(ID_len + 6) << it->second.commodityID << setw(commodityName_len + 4) << it->second.commedityName
		//		//			<< setw(10) << it->second.price << setw(14) << it->second.addedDate
		//		//			<< setw(10) << it->second.number << setw(10) << it->second.state << endl;
		//		//	}
		//		//}
		//		////���ȴ���1ģ��ƥ��
		//		//else {
		//			if (it->second.commedityName.find(a_name)) {
		//				if (!is_find) {
		//					cout << left << setw(ID_len + 6) << "��ƷID" << setw(commodityName_len + 4) << "����"
		//						<< setw(10) << "�۸�" << setw(14) << "�ϼ�ʱ��"
		//						<< setw(10) << "����" << setw(10) << "��Ʒ״̬" << endl;
		//				}
		//				is_find = true;
		//				cout << left << setw(ID_len + 6) << it->second.commodityID << setw(commodityName_len + 4) << it->second.commedityName
		//					<< setw(10) << it->second.price << setw(14) << it->second.addedDate
		//					<< setw(10) << it->second.number << setw(10) << it->second.state << endl;
		//			}
		//		//}
		//	}
		//	if (!is_find) cout << "û���ҵ���Ҫ����Ʒ������" << endl;
		//	cout << "**********************************************************************************************" << endl;
		}
	}
	break;
	case 'U':

		break;
	case 'I':

		break;
	default:
		cout << "ָ�����󣡣���" << endl;
		break;
	}
}
void buyer_instruction(string instruction) {
	commond_in_file(instruction);

}
