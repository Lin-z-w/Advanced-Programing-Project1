#pragma once
#include<string>
using namespace std;

class Order
{
public:
	Order();
	~Order();
	void add_order();

private:
	string orderID, commodityID, sellerID, buyerID, date;
	int number;
	float unitPrice;
};