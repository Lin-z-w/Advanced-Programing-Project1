#pragma once
#include"User.h"
class Seller: public User
{
public:
	Seller();
	~Seller();

	void S_choice();
	void S_issue_commodity();
	void S_look_up_icommodity();
	void S_change_icommodity_attribute();
	void S_pull_icommodity();
	void S_look_up_iorder();

private:

};

