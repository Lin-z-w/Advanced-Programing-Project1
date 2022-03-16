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
		cout << "文件打开失败！！！" << endl;
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
			//printf("%-10s %-20s %-6s %-15s %-10s %-10s\n", "ID", "名称", "价格", "上架时间", "卖家ID","商品状态");
			cout << left << setw(ID_len + 6) << "商品ID" << setw(commodityName_len + 4) << "名称"
				<< setw(10) << "价格" << setw(14) << "上架时间" << setw(ID_len + 6) << "卖家ID"
				<< setw(10) << "数量" << setw(10) << "商品状态" << endl;
			for (Commodity_map::iterator it = mydate.commodity.begin(); it != mydate.commodity.end(); it++) {
				cout << left << setw(ID_len + 6) << it->second.commodityID << setw(commodityName_len + 4) << it->second.commodityName
					<< setw(10) << fixed << setprecision(1) << it->second.price << setw(14) << it->second.addedDate << setw(ID_len + 6) << it->second.sellerID
					<< setw(10) << it->second.number << setw(10) << it->second.state << endl;
			}
			cout << "**********************************************************************************************" << endl;
		}
		else if (instruction == "SELECT * FROM order") {
			cout << "*************************************************************************" << endl;
			cout << left << setw(10) << "订单ID" << setw(10) << "商品ID" << setw(10) << "商品单价" 
				<< setw(10) << "商品数量"
				<< setw(14) << "交易时间" << setw(10) << "卖家ID" << setw(10) << "买家ID" << endl;
			for (Order_map::iterator it = mydate.order.begin(); it != mydate.order.end(); it++) {
				cout << left << setw(10) << it->second.orderID << setw(10) << it->second.commodityID << setw(10) << fixed << setprecision(1) << it->second.unitPrice
					<< setw(10) << it->second.number 
					<< setw(14) << it->second.date << setw(10) << it->second.sellerID << setw(10) << it->second.buyerID << endl;
			}
			cout << "*************************************************************************" << endl;
		}
		else if (instruction == "SELECT * FROM user") {
			cout << "********************************************************************************************************************************************" << endl;
			//用户ID,用户名,密码,联系方式,地址,钱包余额,用户状态
			cout << left << setw(10) << "用户ID" << setw(userName_len + 4) << "用户名" << setw(password_len + 4) << "密码"
				<< setw(phoneNumber_len + 4) << "联系方式" << setw(address_len + 4) << "地址"
				<< setw(10) << "钱包余额" << setw(10) << "用户状态" << endl;
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
				if (!(it->second.commodityName.find(a_name) == string::npos)) {
					if (!is_find) {
						cout << left << setw(ID_len + 6) << "商品ID" << setw(commodityName_len + 4) << "名称"
							<< setw(10) << "价格" << setw(14) << "上架时间"
							<< setw(10) << "数量" << setw(10) << "商品状态" << endl;
					}
					is_find = true;
					cout << left << setw(ID_len + 6) << it->second.commodityID << setw(commodityName_len + 4) << it->second.commodityName
						<< setw(10) << fixed << setprecision(1) << it->second.price << setw(14) << it->second.addedDate
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
		cout << "指令有误！！！" << endl;
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
			//printf("%-10s %-20s %-6s %-15s %-10s %-10s\n", "ID", "名称", "价格", "上架时间", "卖家ID","商品状态");
			cout << left << setw(ID_len + 6) << "商品ID" << setw(commodityName_len + 4) << "名称"
				<< setw(10) << "价格" << setw(14) << "上架时间"
				<< setw(10) << "数量" << setw(10) << "商品状态" << endl;
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
			cout << left << setw(10) << "订单ID" << setw(10) << "商品ID"
				<< setw(10) << "商品单价"
				<< setw(10) << "商品数量"
				<< setw(14) << "交易时间" << setw(10) << "卖家ID" << endl;
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
				cout << "您发布的商品中未找到该商品！！！" << endl;
				return;
			}
			cout << "商品信息如下：" << endl;
			cout << "************************" << endl;
			cout << "商品名称：" << a_commodity->second.get_commodityName() << endl;
			cout << "商品价格：" << fixed << setprecision(1) << a_commodity->second.get_price() << endl;
			cout << "商品数量：" << a_commodity->second.get_number() << endl;
			cout << "商品描述：" << a_commodity->second.get_description() << endl;
			cout << "************************" << endl;
			cout << "您确定要下架该商品吗？？？（y/n）";
			cin >> y_or_n;
			if (y_or_n == "n") {
				cout << "已放弃下架该商品！！！";
				return;
			}
			cout << "商品下架成功！！！" << endl;
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
		cout << "请确认发布的商品信息无误！！！" << endl;
		cout << "**************************************" << endl;
		cout << "商品名称：" << commodityName << endl;
		cout << "商品价格：" << price << endl;
		cout << "商品数量：" << number << endl;
		cout << "商品描述：" << description << endl;
		cout << "**************************************" << endl;
		cout << "确定要发布该商品吗？？？(y/n)";
		while (true) {
			cin >> y_or_n;
			if (y_or_n == "n") {
				cout << "已放弃发布该商品！！！" << endl;
				return;
			}
			else if (y_or_n != "y") {
				cout << "请输入y或者n！！！！" << endl;
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
		cout << "指令有误！！！" << endl;
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
			//printf("%-10s %-20s %-6s %-15s %-10s %-10s\n", "ID", "名称", "价格", "上架时间", "卖家ID","商品状态");
			cout << left << setw(ID_len + 6) << "商品ID" << setw(commodityName_len + 4) << "名称"
				<< setw(10) << "价格" << setw(14) << "上架时间"
				<< setw(10) << "数量" << setw(10) << "卖家ID" << endl;
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
			cout << left << setw(10) << "订单ID" << setw(10) << "商品ID"
				<< setw(10) << "商品单价"
				<< setw(10) << "商品数量"
				<< setw(14) << "交易时间" << setw(10) << "卖家ID" << endl;
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
					cout << "商品名称：" << a_commodity->second.get_commodityName() << endl;
					cout << "商品价格：" << a_commodity->second.get_price() << endl;
					cout << "商品描述：" << a_commodity->second.get_description() << endl;
					cout << "上架时间：" << a_commodity->second.get_addedDate() << endl;
					cout << "卖家ID：" << a_commodity->second.get_sellerID() << endl;
					cout << "*********************************" << endl;
				}
				else {
					cout << "出售中的商品没有找到你想要的商品！！！即将返回上一界面！！！" << endl;
				}
			}
			else {
				string commodityName = instruction.substr(53, instruction.length() - 53);
				bool is_find = false;
				cout << "****************************************************************************************" << endl;
				for (Commodity_map::iterator it = mydate.commodity.begin(); it != mydate.commodity.end(); it++) {
					if (it->second.get_commodityName().find(commodityName) != string::npos && it->second.get_state() != commodityState_r) {
						if (!is_find) {
							cout << left << setw(ID_len + 6) << "商品ID" << setw(commodityName_len + 4) << "名称"
								<< setw(10) << "价格" << setw(14) << "上架时间"
								<< setw(10) << "数量" << setw(10) << "商品状态" << endl;
						}
						is_find = true;
						cout << left << setw(ID_len + 6) << it->second.get_commodityID() << setw(commodityName_len + 4) << it->second.get_commodityName()
							<< setw(10) << fixed << setprecision(1) << it->second.get_price() << setw(14) << it->second.get_addedDate()
							<< setw(10) << it->second.get_number() << setw(10) << it->second.get_state() << endl;
					}
				}
				if (!is_find) cout << "没有找到想要的商品！！！" << endl;
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
