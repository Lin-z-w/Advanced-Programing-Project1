#include<iostream>
#include<iomanip>
#include<fstream>
#include"Constant.h"
#include"Datebase.h"
#include"iSQL.h"
using namespace std;

extern Datebase mydate;
void get_time(char* p) {
    time_t t = time(0);
    char temp[11];
    strftime(temp, sizeof(temp), "%Y-%m-%d", localtime(&t));
    strcpy(p, temp);
}
void commond_in_file(string instruction) {
	char now_time[11];
	get_time(now_time);
	ofstream out_file("commands.txt", ios::app);
	if (!out_file) {
		cout << "文件打开失败！！！" << endl;
	}
	out_file << now_time << ': ';
	out_file << instruction << endl;
}

void admin_instruction(string instruction) {
	commond_in_file(instruction);
	switch (instruction[0])
	{
	case 'S':
	{
		if (instruction == "SELECT * FROM commodity") {
			cout << "**********************************************************************************************" << endl;
			//printf("%-10s %-20s %-6s %-15s %-10s %-10s\n", "ID", "名称", "价格", "上架时间", "卖家ID","商品状态");
			cout << left << setw(ID_len + 6) << "商品ID" << setw(commodityName_len + 4) << "名称"
				<< setw(10) << "价格" << setw(14) << "上架时间" << setw(ID_len + 6) << "卖家ID"
				<< setw(10) << "数量" << setw(10) << "商品状态" << endl;
			for (Commodity_map::iterator it = mydate.commodity.begin(); it != mydate.commodity.end(); it++) {
				cout << left << setw(ID_len + 6) << it->second.commodityID << setw(commodityName_len + 4) << it->second.commedityName
					<< setw(10) << it->second.price << setw(14) << it->second.addedDate << setw(ID_len + 6) << it->second.sellerID
					<< setw(10) << it->second.number << setw(10) << it->second.state << endl;
			}
			cout << "**********************************************************************************************" << endl;
		}
		else if (instruction == "SELECT * FROM order") {

		}
		else if (instruction == "SELECT * FROM user") {

		}
		else {
			string a_name = instruction.substr(53);
			int a_name_len = a_name.length();
			bool is_find = false;
			cout << "****************************************************************************************" << endl;
			for (Commodity_map::iterator it = mydate.commodity.begin(); it != mydate.commodity.end(); it++) {
				////长度为1完全匹配
				//if (a_name_len == 1) {
				//	if (a_name == it->second.commedityName) {
				//		if (!is_find) {
				//			cout << "**********************************************************************************************" << endl;
				//			cout << left << setw(ID_len + 6) << "商品ID" << setw(commodityName_len + 4) << "名称"
				//				<< setw(10) << "价格" << setw(14) << "上架时间"
				//				<< setw(10) << "数量" << setw(10) << "商品状态" << endl;
				//		}
				//		is_find = true;
				//		cout << left << setw(ID_len + 6) << it->second.commodityID << setw(commodityName_len + 4) << it->second.commedityName
				//			<< setw(10) << it->second.price << setw(14) << it->second.addedDate
				//			<< setw(10) << it->second.number << setw(10) << it->second.state << endl;
				//	}
				//}
				////长度大于1模糊匹配
				//else {
				if (!(it->second.commedityName.find(a_name) == string::npos)) {
					if (!is_find) {
						cout << left << setw(ID_len + 6) << "商品ID" << setw(commodityName_len + 4) << "名称"
							<< setw(10) << "价格" << setw(14) << "上架时间"
							<< setw(10) << "数量" << setw(10) << "商品状态" << endl;
					}
					is_find = true;
					cout << left << setw(ID_len + 6) << it->second.commodityID << setw(commodityName_len + 4) << it->second.commedityName
						<< setw(10) << it->second.price << setw(14) << it->second.addedDate
						<< setw(10) << it->second.number << setw(10) << it->second.state << endl;
				}
				//}
			}
			if (!is_find) cout << "没有找到想要的商品！！！" << endl;
			cout << "****************************************************************************************" << endl;
		}
	}
		break;
	case 'U':
		
		break;
	case 'I':
		
		break;
	default:
		cout << "指令有误！！！" << endl;
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
			//printf("%-10s %-20s %-6s %-15s %-10s %-10s\n", "ID", "名称", "价格", "上架时间", "卖家ID","商品状态");
			cout << left << setw(ID_len + 6) << "商品ID" << setw(commodityName_len + 4) << "名称"
				<< setw(10) << "价格" << setw(14) << "上架时间"
				<< setw(10) << "数量" << setw(10) << "商品状态" << endl;
			for (Commodity_map::iterator it = mydate.commodity.begin(); it != mydate.commodity.end(); it++) {
				if (sellerid == it->second.sellerID) {
					cout << left << setw(ID_len + 6) << it->second.commodityID << setw(commodityName_len + 4) << it->second.commedityName
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
		//		////长度为1完全匹配
		//		//if (a_name_len == 1) {
		//		//	if (a_name == it->second.commedityName) {
		//		//		if (!is_find) {
		//		//			cout << "**********************************************************************************************" << endl;
		//		//			cout << left << setw(ID_len + 6) << "商品ID" << setw(commodityName_len + 4) << "名称"
		//		//				<< setw(10) << "价格" << setw(14) << "上架时间"
		//		//				<< setw(10) << "数量" << setw(10) << "商品状态" << endl;
		//		//		}
		//		//		is_find = true;
		//		//		cout << left << setw(ID_len + 6) << it->second.commodityID << setw(commodityName_len + 4) << it->second.commedityName
		//		//			<< setw(10) << it->second.price << setw(14) << it->second.addedDate
		//		//			<< setw(10) << it->second.number << setw(10) << it->second.state << endl;
		//		//	}
		//		//}
		//		////长度大于1模糊匹配
		//		//else {
		//			if (it->second.commedityName.find(a_name)) {
		//				if (!is_find) {
		//					cout << left << setw(ID_len + 6) << "商品ID" << setw(commodityName_len + 4) << "名称"
		//						<< setw(10) << "价格" << setw(14) << "上架时间"
		//						<< setw(10) << "数量" << setw(10) << "商品状态" << endl;
		//				}
		//				is_find = true;
		//				cout << left << setw(ID_len + 6) << it->second.commodityID << setw(commodityName_len + 4) << it->second.commedityName
		//					<< setw(10) << it->second.price << setw(14) << it->second.addedDate
		//					<< setw(10) << it->second.number << setw(10) << it->second.state << endl;
		//			}
		//		//}
		//	}
		//	if (!is_find) cout << "没有找到想要的商品！！！" << endl;
		//	cout << "**********************************************************************************************" << endl;
		}
	}
	break;
	case 'U':

		break;
	case 'I':

		break;
	default:
		cout << "指令有误！！！" << endl;
		break;
	}
}
void buyer_instruction(string instruction) {
	commond_in_file(instruction);

}
