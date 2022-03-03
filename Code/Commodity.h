#pragma once
#include<iostream>
#include<string>
using namespace std;

class Commodity
{
public:
	Commodity();
	~Commodity();
	void add_commodity();

private:
	struct Node {
		string commodityID, commedityName, description, sellerID, addedDate, state;
		int number;
		float price;
		Node* next;
	};
	Node* commodityhead, * commoditytail;
};

