#pragma once
#ifndef CONSTANT_NUM_STRING
#define CONSTANT_NUM_STRING

#include<string>
#include"Commodity.h"
#include"Order.h"
#include"User.h"
using namespace std;

const string userState_a = "active", userState_i = "inactive";//�û�״̬
const string commodityState_r = "remove", commodityState_o = "onSale";//��Ʒ״̬
const string administratorName = "admin", administratorPassword = "123456";//����Ա�˺�����
const int ID_len = 4, userName_len = 10, password_len = 20,
phoneNumber_len = 20, adress_len = 40, commodityName_len = 20;//�����ַ�����������
//����Ϊ�û�����Ʒ�������������趨Ϊȫ�ֱ�����
User user;
Order order;
Commodity commodity;

#endif // !CONSTANT_NUM_STRING

