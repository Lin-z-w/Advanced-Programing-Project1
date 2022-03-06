#include "Datebase.h"
#include<iostream>
#include<fstream>
using namespace std;

Datebase::Datebase() {
	initial_user_imformation();
	initial_commodity_imformation();
	initial_order_imformation();
}
Datebase::~Datebase() {

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

}
void Datebase::final_commodity_imformation() {

}
void Datebase::final_order_imformation() {

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