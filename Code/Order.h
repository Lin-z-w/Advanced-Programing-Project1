#pragma once
#include<string>
using namespace std;

class Order
{
public:
	Order(string orderID1, string commodityID1, double unitPrice1, int number1, string date1, string sellerID1, string buyerID1);
	~Order();
	void add_order();

	string get_orderID();
	string get_commodityID();
	string get_sellerID();
	string get_buyerID();
	string get_date();
	int get_number();
	double get_unitPrice();

	friend void admin_instruction(string instruction);

private:
	string orderID, commodityID, sellerID, buyerID, date;
	int number;
	double unitPrice;
};