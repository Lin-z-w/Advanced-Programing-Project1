#include"User.h"

User::User() 
{
}

User::User(string userID_in, string userName_in, string password_in, string phoneNumber_in, string address_in, double balance_in, string userState_in)
{
	userID = userID_in;
	userName = userName_in;
	password = password_in;
	phoneNumber = phoneNumber_in;
	address = address_in; 
	userState = userState_in;
	balance = balance_in;
}

User::~User()
{
}

string User::get_ID() {
	return userID;
}
string User::get_name() {
	return userName;
}
string User::get_password() {
	return password;
}
string User::get_phoneNumber() {
	return phoneNumber;
}
string User::get_address() {
	return address;
}
string User::get_userState() {
	return userState;
}
double User::get_balance() {
	return balance;
}