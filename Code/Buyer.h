#pragma once
#include"User.h"

class Buyer: public User
{
public:
	Buyer(string userID_in, string userName_in, string password_in, string phoneNumber_in, string address_in, double balance_in, string userState_in);
	~Buyer();
	void Choice();//Âò¼ÒÑ¡Ôñ

private:

};