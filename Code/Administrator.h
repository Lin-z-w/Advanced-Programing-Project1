#pragma once
#include<string>
using namespace std;

class Administrator
{
public:
	Administrator();
	~Administrator();

	void Choice();//管理员的选择
	string get_name();
	string get_password();


private:
	string name, password;//分别为admin，123456（保存在Constant.h文件中）
};
