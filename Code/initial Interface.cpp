#include"Initial Interface.h"
#include"Constant.h"
#include<iostream>
using namespace std;

void choose_identity() {
	int choice = 0;
	while (true) {
		cout << "=============================================" << endl;
		cout << "1.�û���¼ 2.�û�ע�� 3.����Ա��¼ 4.�˳�����" << endl;
		cout << "=============================================" << endl;
		cout << "��ѡ��";
		cin >> choice;
		if (cin.fail()) {
			cin.clear();
			cout << "������󣡣������������롣" << endl;
			cin.ignore(10000, '\n');
			continue;
		}
		switch (choice)
		{
		case 1:
		
			break;
		case 2:
		
			break;
		case 3:
			return;
			break;
		case 4:
			
			break;
		default:
			cout << "������󣡣������������롣" << endl;
			choose_identity();
			break;
		}
		choose_identity();
	}
}