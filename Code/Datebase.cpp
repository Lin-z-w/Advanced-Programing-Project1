#include "Datebase.h"
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

Datebase::Datebase() {
	initial_user_imformation();
	initial_commodity_imformation();
	initial_order_imformation();
}
Datebase::~Datebase() {
	final_user_imformation();
	final_commodity_imformation();
	final_order_imformation();
}

void Datebase::initial_user_imformation() {
	string information;
	ifstream in_file("user.txt", ios::in);
	if (!in_file) {
		in_file.close();
		ofstream out_file("user.txt", ios::app);
		out_file.close();
		return;
	}
	//first line: userID,username,password,phoneNumber,address,balance,userState
	in_file >> information;
	while (!in_file.eof()) {
		string userID, username, password, phoneNumber, address, userState;
		double balance = 0;
		int cnt = 0, past = 0;
		in_file >> information;
		for (int cur = 0; cur < information.length(); cur++) {
			if (information[cur] == ',') {
				switch (cnt)
				{
				case 0:
					userID = information.substr(past, cur - past);
					cnt++;
					past = cur + 1;
					break;
				case 1:
					username = information.substr(past, cur - past);
					cnt++;
					past = cur + 1;
					break;
				case 2:
					password = information.substr(past, cur - past);
					cnt++;
					past = cur + 1;
					break;
				case 3:
					phoneNumber = information.substr(past, cur - past);
					cnt++;
					past = cur + 1;
					break;
				case 4:
					address = information.substr(past, cur - past);
					cnt++;
					past = cur + 1;
					break;
				case 5:
					balance = atof(information.substr(past, cur - past).c_str());
					userState = information.substr(cur + 1);
					cnt++;
					break;
				default:
					break;
				}
			}
		}
		//User(string userID_in, string userName_in, string password_in, string phoneNumber_in, string adress_in, string userState_in, int balance_in);
		User a_user(userID, username, password, phoneNumber, address, balance, userState);
		user.insert(pair<string, User>(userID, a_user));
	}
	in_file.close();
}
void Datebase::initial_commodity_imformation() {
	string information;
	ifstream in_file("commodity.txt", ios::in);
	if (!in_file) {
		in_file.close();
		ofstream out_file("commodity.txt", ios::app);
		out_file.close();
		return;
	}
	//first line: commodityID,commodityName,price,number,description,sellerID,addedDate,state
	in_file >> information;
	while (!in_file.eof()) {
		string commodityID, commodityName, description, sellerID, addedDate, state;
		double  price = 0;
		int cnt = 0, past = 0, number = 0;
		in_file >> information;
		for (int cur = 0; cur < information.length(); cur++) {
			if (information[cur] == ',') {
				switch (cnt)
				{
				case 0:
					commodityID = information.substr(past, cur - past);
					break;
				case 1:
					commodityName = information.substr(past, cur - past);
					break;
				case 2:
					price = atof(information.substr(past, cur - past).c_str());
					break;
				case 3:
					number = atoi(information.substr(past, cur - past).c_str());
					break;
				case 4:
					description = information.substr(past, cur - past);
					break;
				case 5:
					sellerID = information.substr(past, cur - past);
					break;
				case 6:
					addedDate = information.substr(past, cur - past);
					state = information.substr(cur + 1);
					break;
				default:
					break;
				}
				cnt++;
				past = cur + 1;
			}
		}
		Commodity a_commodity(commodityID, commodityName, price, number, description, sellerID, addedDate, state);
		commodity.insert(pair<string, Commodity>(commodityID, a_commodity));
	}
	in_file.close();
}
void Datebase::initial_order_imformation() {
	string information;
	ifstream in_file("order.txt", ios::in);
	if (!in_file) {
		in_file.close();
		ofstream out_file("order.txt", ios::app);
		out_file.close();
		return;
	}
	//first line: orderID,commodityID,unitPrice,number,date,sellerID,buyerID
	in_file >> information;
	while (!in_file.eof()) {
		string orderID, commodityID, date, sellerID, buyerID;
		double unitPrice = 0;
		int cnt = 0, past = 0, number = 0;
		in_file >> information;
		for (int cur = 0; cur < information.length(); cur++) {
			if (information[cur] == ',') {
				switch (cnt)
				{
				case 0:
					orderID = information.substr(past, cur - past);
					cnt++;
					past = cur + 1;
					break;
				case 1:
					commodityID = information.substr(past, cur - past);
					cnt++;
					past = cur + 1;
					break;
				case 2:
					unitPrice = atof(information.substr(past, cur - past).c_str());
					cnt++;
					past = cur + 1;
					break;
				case 3:
					number = atoi(information.substr(past, cur - past).c_str());
					cnt++;
					past = cur + 1;
					break;
				case 4:
					date = information.substr(past, cur - past);
					cnt++;
					past = cur + 1;
					break;
				case 5:
					sellerID = information.substr(past, cur - past);
					buyerID = information.substr(cur + 1);
					cnt++;
					break;
				default:
					break;
				}
			}
		}
		Order a_order(orderID, commodityID, unitPrice, number, date, sellerID, buyerID);
		order.insert(pair<string, Order>(orderID, a_order));
	}
	in_file.close();
}

void Datebase::final_user_imformation() {
	ofstream out_file("user.txt",ios::out);
	out_file << "userID,username,password,phoneNumber,address,balance,userState" << endl;
	if (user.empty()) {
		return;
	}
	for (User_map::iterator it = user.begin(); it != user.end(); it++) {
		out_file << it->second.get_ID() + "," + it->second.get_name() + "," + it->second.get_password() + "," +
			it->second.get_phoneNumber() + "," + it->second.get_address() + "," << fixed << setprecision(1) << it->second.get_balance() 
			<< "," + it->second.get_userState() << endl;
	}
	out_file.close();
}
void Datebase::final_commodity_imformation() {
	ofstream out_file("commodity.txt", ios::out);
	out_file << "commodityID,commodityName,price,number,description,sellerID,addedDate,state" << endl;
	if (commodity.empty()) {
		return;
	}
	for (Commodity_map::iterator it = commodity.begin(); it != commodity.end(); it++) {
		out_file << it->second.get_commodityID() + "," + it->second.get_commodityName() + ","
			<< fixed << setprecision(1) << it->second.get_price() << "," << it->second.get_number()
			<< "," + it->second.get_description() + "," + it->second.get_sellerID() 
			<< "," + it->second.get_addedDate() + "," + it->second.get_state() << endl;
	}
	out_file.close();
}
void Datebase::final_order_imformation() {
	ofstream out_file("order.txt", ios::out);
	out_file << "orderID,commodityID,unitPrice,number,date,sellerID,buyerID" << endl;
	if (order.empty()) {
		return;
	}
	for (Order_map::iterator it = order.begin(); it != order.end(); it++) {
		out_file << it->second.get_orderID() + "," + it->second.get_commodityID() + ","
			<< fixed << setprecision(1) << it->second.get_unitPrice()
			<< "," << it->second.get_number() << "," + it->second.get_date() + "," + it->second.get_sellerID() + "," + it->second.get_buyerID() << endl;
	}
	out_file.close();
}

string Datebase::new_userID() {
	if (user.empty()) {
		return "U001";
	}
	string userID;
	User_map::iterator last_user = user.end();
	last_user--;
	userID = last_user->second.get_ID();
	int cnt = 3;
	while (cnt != 0) {
		if (userID[cnt] == '9') {
			userID[cnt] = '0';
		}
		else {
			userID[cnt]++;
			return userID;
		}
		cnt--;
	}
	return "用户人数已满！！！";
}
string Datebase::new_commodityID() {
	if (commodity.empty()) {
		return "M001";
	}
	string commodityID;
	Commodity_map::iterator last_commodity = commodity.end();
	last_commodity--;
	commodityID = last_commodity->second.get_commodityID();
	int cnt = 3;
	while (cnt != 0) {
		if (commodityID[cnt] == '9') {
			commodityID[cnt] = '0';
		}
		else {
			commodityID[cnt]++;
			return commodityID;
		}
		cnt--;
	}
	return "商品目录已满！！！";
}
string Datebase::new_orderID() {
	if (order.empty()) {
		return "T001";
	}
	string new_orderID;
	Order_map::iterator last_order = order.end();
	last_order--;
	new_orderID = last_order->second.get_orderID();
	int cnt = 3;
	while (cnt != 0) {
		if (new_orderID[cnt] == '9') {
			new_orderID[cnt] = '0';
		}
		else {
			new_orderID[cnt]++;
			return new_orderID;
		}
		cnt--;
	}
	return "订单目录已满！！！";
}

bool Datebase::is_repeat_name(string name) {
	for (User_map::iterator it = user.begin(); it != user.end(); it++) {
		if (name == it->second.get_name()) {
			return true;
		}
	}
	return false;
}

//User_map Datebase::get_user() {
//	return user;
//}
//Commodity_map Datebase::get_commodity() {
//	return commodity;
//}
//Order_map Datebase::get_order() {
//	return order;
//}
//Administrator Datebase::get_admin() {
//	return admin;
//}