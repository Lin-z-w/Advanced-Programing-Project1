#pragma once
#include<iostream>
#include<string>
using namespace std;

class Order
{
public:
	Order();
	~Order();

private:
	struct Node {
		string orderID, commodityID, sellerID, buyerID, date;
		int number;
		float unitPrice;
		Node* next;
	};
	Node* orderhead, * ordertail;
};