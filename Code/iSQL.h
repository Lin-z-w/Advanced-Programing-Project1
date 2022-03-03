#pragma once
#include<string>
using namespace std;

void Instruction_choose(string instruction);//分辨指令是否合法，以及属于哪一类的指令
void INSERT_instruction(string instruction);//执行INSERT指令相关的操作
void UPDATE_instruction(string instruction);//执行UPDATE指令相关的操作
void SELECT_instruction(string instruction);//执行SELECT指令相关的操作

