#include"User.h"

User::User() 
{
}

User::User(string userID_in, string userName_in, string password_in, string phoneNumber_in, string adress_in, double balance_in, string userState_in)
{
	userID = userID_in;
	userName = userName_in;
	password = password_in;
	phoneNumber = phoneNumber_in;
	adress = adress_in; 
	userState = userState_in;
	balance = balance_in;
}

User::~User()
{
}