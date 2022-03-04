#pragma once
#include<string>
using namespace std;

class Commodity
{
public:
	Commodity();
	~Commodity();
	void add_commodity();

private:
	string commodityID, commedityName, description, sellerID, addedDate, state;
	int number;
	float price;
};

