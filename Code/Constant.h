#pragma once

#ifndef CONSTANT_NUM_STRING
#define CONSTANT_NUM_STRING
#include<string>
using namespace std;

const string userState_a = "active", userState_i = "inactive";//用户状态
const string commodityState_r = "remove", commodityState_o = "onSale";//商品状态
const string administratorName = "admin", administratorPassword = "123456";//管理员账号密码
const int ID_len = 4, userName_len = 10, password_len = 20,
phoneNumber_len = 20, address_len = 40, commodityName_len = 20;//各种字符串长短限制

#endif // !CONSTANT_NUM_STRING

