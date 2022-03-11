#pragma once
#include"User.h"
class Seller: public User
{
public:
	Seller(string userID_in, string userName_in, string password_in, string phoneNumber_in, string address_in, double balance_in, string userState_in);
	~Seller();

	void Choice();

private:

};

