#pragma once
#include<string>
using namespace std;

class Commodity
{
public:
	Commodity(string commodityID1, string commodityName1, double price1, int number1, string description1, string sellerID1, string addedDate1, string state1);
	~Commodity();
	void add_commodity();

	friend void admin_instruction(string instruction);
	friend void seller_instruction(string instruction, string sellerid);

private:
	string commodityID, commedityName, description, sellerID, addedDate, state;
	int number;
	double price;
};

