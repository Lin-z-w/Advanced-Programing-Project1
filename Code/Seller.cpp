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
        cout << "1.������Ʒ 2.�鿴������Ʒ 3.�޸���Ʒ��Ϣ 4.�¼���Ʒ 5.�鿴��ʷ���� 6.�����û�������" << endl;
        cout << "===================================================================================" << endl;
        cout << endl;
        cout << "��ѡ��";
        cin >> num;
        if (cin.fail()) {
            cin.clear();
            cout << "������󣡣������������롣" << endl;
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
            cout << "�������룡�������������롣" << endl;
            break;
        }
    }
}