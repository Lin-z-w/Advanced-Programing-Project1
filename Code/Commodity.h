#pragma once
#include<string>
#include"Administrator.h"
using namespace std;

class Commodity
{
public:
	Commodity();
	Commodity(string commodityID1, string commodityName1, double price1, int number1, string description1, string sellerID1, string addedDate1, string state1);
	~Commodity();

	string get_commodityID();
	string get_commodityName();
	string get_description();
	string get_sellerID();
	string get_addedDate();
	string get_state();
	int get_number();
	double get_price();
	void set_price(double p);
	void set_description(string d);
	void remove_it();

	friend void admin_instruction(string instruction);
	friend void seller_instruction(string instruction, string sellerid);
	friend void Administrator::Choice();

private:
	string commodityID, commodityName, description, sellerID, addedDate, state;
	int number;
	double price;
};

