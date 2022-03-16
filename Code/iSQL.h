#pragma once
#include<string>
using namespace std;

void admin_instruction(string instruction);//分辨指令是否合法，以及属于哪一类的指令
void seller_instruction(string instruction,string sellerID);
void buyer_instruction(string instruction,string buyerID);
void commond_in_file(string instruction);

