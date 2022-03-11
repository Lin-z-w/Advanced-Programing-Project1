#include"Seller.h"
#include<iostream>
using namespace std;

Seller::Seller(string userID_in, string userName_in, string password_in, string phoneNumber_in, string address_in, double balance_in, string userState_in)
{
	userID = userID_in;
	userName = userName_in;
	password = password_in;
	phoneNumber = phoneNumber_in;
	address = address_in;
	userState = userState_in;
	balance = balance_in;
}
Seller::~Seller()
{
}

void Seller::Choice() {
    int num = 0;
    while (true) {
        cout << endl;
        cout << "===================================================================================" << endl;
        cout << "1.发布商品 2.查看发布商品 3.修改商品信息 4.下架商品 5.查看历史订单 6.返回用户主界面" << endl;
        cout << "===================================================================================" << endl;
        cout << endl;
        cout << "请选择：";
        cin >> num;
        if (cin.fail()) {
            cin.clear();
            cout << "输入错误！！！请重新输入。" << endl;
            cin.ignore(10000, '\n');
            continue;
        }
        switch (num)
        {
        case 1:
            
            break;
        case 2:
            
            break;
        case 3:
            
            break;
        case 4:
            
            break;
        case 5:
            
            break;
        case 6:
            return;
        default:
            cout << "错误输入！！！请重新输入。" << endl;
            break;
        }
    }
}