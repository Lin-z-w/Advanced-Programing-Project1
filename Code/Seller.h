#pragma once
#include"User.h"
class Seller: public User
{
public:
	Seller();
	~Seller();

	void choice();
	void issue_commodity();
	void look_up_icommodity();
	void change_icommodity_attribute();
	void pull_icommodity();
	void look_up_iorder();

private:

};

