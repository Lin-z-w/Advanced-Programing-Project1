#pragma once
#include<string>
using namespace std;

class Administrator
{
public:
	Administrator();
	~Administrator();

	void choice();
	void look_up_commodity();
	void search_commodity();
	void look_up_order();
	void look_up_users();
	void ban_user();
	void pull_commodity();

private:
	string name, password;
};
