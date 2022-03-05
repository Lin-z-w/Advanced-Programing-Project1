#include"Order.h"

Order::Order(string orderID1, string commodityID1, double unitPrice1, int number1, string date1, string sellerID1, string buyerID1)
{
	orderID = orderID1;
	commodityID = commodityID1;
	unitPrice = unitPrice1;
	number = number1;
	date = date1;
	sellerID = sellerID1;
	buyerID = buyerID1;
}

Order::~Order()
{
}