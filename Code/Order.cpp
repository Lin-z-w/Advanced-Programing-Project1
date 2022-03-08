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

string Order::get_orderID() {
	return orderID;
}
string Order::get_commodityID() {
	return commodityID;
}
string Order::get_sellerID() {
	return sellerID;
}
string Order::get_buyerID() {
	return buyerID;
}
string Order::get_date() {
	return date;
}
int Order::get_number() {
	return number;
}
double Order::get_unitPrice() {
	return unitPrice;
}