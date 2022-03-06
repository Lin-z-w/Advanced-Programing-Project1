#include<iostream>
#include"Commodity.h"
using namespace std;

Commodity::Commodity(string commodityID1, string commodityName1, double price1, int number1, string description1, string sellerID1, string addedDate1, string state1)
{
	commodityID = commodityID1;
	commedityName = commodityName1;
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

