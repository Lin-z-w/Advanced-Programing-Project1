#include<iostream>
#include"Commodity.h"
#include"Constant.h"
using namespace std;

Commodity::Commodity() {

}

Commodity::Commodity(string commodityID1, string commodityName1, double price1, int number1, string description1, string sellerID1, string addedDate1, string state1)
{
	commodityID = commodityID1;
	commodityName = commodityName1;
	price = price1;
	number = number1;
	description = description1;
	sellerID = sellerID1;
	addedDate = addedDate1;
	state = state1;
}

Commodity::~Commodity()
{
}

string Commodity::get_commodityID() {
	return commodityID;
}
string Commodity::get_commodityName() {
	return commodityName;
}
string Commodity::get_description() {
	return description;
}
string Commodity::get_sellerID() {
	return sellerID;
}
string Commodity::get_addedDate() {
	return addedDate;
}
string Commodity::get_state() {
	return state;
}
int Commodity::get_number() {
	return number;
}
double Commodity::get_price() {
	return price;
}
void Commodity::set_price(double p) {
	price = p;
}
void Commodity::set_description(string d) {
	description = d;
}
void Commodity::remove_it() {
	state = commodityState_r;
}
