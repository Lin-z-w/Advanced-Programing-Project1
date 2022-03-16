#include"Seller.h"
#include"iSQL.h"
#include"Datebase.h"
#include<iostream>
#include<iomanip>
using namespace std;

extern Datebase mydate;
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
    string instruction, y_or_n;
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
        case 1: {
            string commodityName, description;
            double price;
            int number;
            cout << "��������Ʒ����:";
            cin >> commodityName;
            cout << "��������Ʒ�۸�:";
            cin >> price;
            if (cin.fail()) {
                cin.clear();
                cout << "������󣡣������������롣" << endl;
                cin.ignore(10000, '\n');
                continue;
            }
            cout << "��������Ʒ����:";
            cin >> number;
            if (cin.fail()) {
                cin.clear();
                cout << "������󣡣������������롣" << endl;
                cin.ignore(10000, '\n');
                break;
            }
            cout << "��������Ʒ����";
            cin >> description;
            instruction = "INSERT INTO commodity VALUES (" + commodityName 
                + "," + to_string(price) + "," + to_string(number) + "," + description + ")";
            seller_instruction(instruction, userID);
            break;
        }
        case 2:
            instruction = "SELECT * FROM commodity";
            seller_instruction(instruction, userID);
            break;
        case 3: 
        {
            string commodityID, my_change, description, str = " WHERE commodityID = ", str_price;
            double price;
            cout << "������Ҫ�޸ĵ���ƷID��";
            cin >> commodityID;
            Commodity_map::iterator a_commodity = mydate.commodity.find(commodityID);
            if (a_commodity == mydate.commodity.end() || a_commodity->second.get_sellerID() != userID) {
                cout << "����������Ʒ��δ�ҵ�����Ʒ������" << endl;
                break;
            }
            cout << "������Ҫ�޸ĵ���Ʒ���ԣ�1���۸� 2����������";
            cin >> my_change;
            if (my_change == "1") {
                cout << "�������޸ĺ�ļ۸�";
                cin >> price;
                if (cin.fail()) {
                    cin.clear();
                    cout << "������󣡣�������������һ����....." << endl;
                    cin.ignore(10000, '\n');
                    break;
                }
                a_commodity->second.set_price(price);
                str_price = to_string(price);
                for (int i = 0; i < str_price.length(); i++) {
                    if (str_price[i] == '.') {
                        str_price = str_price.substr(0, i + 2);
                    }
                }
                instruction = "UPDATE commodity SET price = " + str_price + str + commodityID;
            }
            else if (my_change == "2") {
                cout << "�������޸ĺ��������";
                cin >> description;
                a_commodity->second.set_description(description);
                instruction = "UPDATE commodity SET description = " + description + str + commodityID;
            }
            else {
                cout << "�����ڸ����ԣ�����" << endl;
                break;
            }
            cout << "��ȷ���޸ĺ����Ʒ��Ϣ���󣡣���" << endl;
            cout << "************************" << endl;
            cout << "��Ʒ���ƣ�" << a_commodity->second.get_commodityName() << endl;
            cout << "��Ʒ�۸�" << fixed << setprecision(1) << a_commodity->second.get_price() << endl;
            cout << "��Ʒ������" << a_commodity->second.get_number() << endl;
            cout << "��Ʒ������" << a_commodity->second.get_description() << endl;
            cout << "************************";
            cout << "ȷ��Ҫ�޸���һ�����𣿣���";
            cin >> y_or_n;
            if (y_or_n == "n") {
                cout << "�ѷ����޸ģ�����" << endl;
                break;
            }
            seller_instruction(instruction, userID);
            break;
        }
        case 4: 
        {
            string commodityID;
            cout << "��������ƷID��";
            cin >> commodityID;
            instruction = "UPDATE commodity SET commodityState = remove WHERE commodityID = " + commodityID;
            seller_instruction(instruction, userID);
            break;
        }
        case 5:
            instruction = "SELECT * FROM order";
            seller_instruction(instruction, userID);
            break;
        case 6:
            return;
        default:
            cout << "�������룡�������������롣" << endl;
            break;
        }
    }
}