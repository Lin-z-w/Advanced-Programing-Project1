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
        case 1: {
            string commodityName, description;
            double price;
            int number;
            cout << "请输入商品名称:";
            cin >> commodityName;
            cout << "请输入商品价格:";
            cin >> price;
            if (cin.fail()) {
                cin.clear();
                cout << "输入错误！！！请重新输入。" << endl;
                cin.ignore(10000, '\n');
                continue;
            }
            cout << "请输入商品数量:";
            cin >> number;
            if (cin.fail()) {
                cin.clear();
                cout << "输入错误！！！请重新输入。" << endl;
                cin.ignore(10000, '\n');
                break;
            }
            cout << "请输入商品描述";
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
            cout << "请输入要修改的商品ID：";
            cin >> commodityID;
            Commodity_map::iterator a_commodity = mydate.commodity.find(commodityID);
            if (a_commodity == mydate.commodity.end() || a_commodity->second.get_sellerID() != userID) {
                cout << "您发布的商品中未找到该商品！！！" << endl;
                break;
            }
            cout << "请输入要修改的商品属性（1、价格 2、描述）：";
            cin >> my_change;
            if (my_change == "1") {
                cout << "请输入修改后的价格：";
                cin >> price;
                if (cin.fail()) {
                    cin.clear();
                    cout << "输入错误！！！即将返回上一界面....." << endl;
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
                cout << "请输入修改后的描述：";
                cin >> description;
                a_commodity->second.set_description(description);
                instruction = "UPDATE commodity SET description = " + description + str + commodityID;
            }
            else {
                cout << "不存在该属性！！！" << endl;
                break;
            }
            cout << "请确认修改后的商品信息无误！！！" << endl;
            cout << "************************" << endl;
            cout << "商品名称：" << a_commodity->second.get_commodityName() << endl;
            cout << "商品价格：" << fixed << setprecision(1) << a_commodity->second.get_price() << endl;
            cout << "商品数量：" << a_commodity->second.get_number() << endl;
            cout << "商品描述：" << a_commodity->second.get_description() << endl;
            cout << "************************";
            cout << "确定要修改这一属性吗？？？";
            cin >> y_or_n;
            if (y_or_n == "n") {
                cout << "已放弃修改！！！" << endl;
                break;
            }
            seller_instruction(instruction, userID);
            break;
        }
        case 4: 
        {
            string commodityID;
            cout << "请输入商品ID：";
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
            cout << "错误输入！！！请重新输入。" << endl;
            break;
        }
    }
}