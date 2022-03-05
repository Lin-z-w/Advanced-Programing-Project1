#pragma once
#include<string>
using namespace std;

class Order
{
public:
	Order(string orderID1, string commodityID1, double unitPrice1, int number1, string date1, string sellerID1, string buyerID1);
	~Order();
	void add_order();

private:
	string orderID, commodityID, sellerID, buyerID, date;
	int number;
	double unitPrice;
};