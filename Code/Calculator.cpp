#include<string>
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

bool is_valid_number(string num) {
	if (num[0] == '0' && num.length() != 1) {
		cerr << "数字输入非法" << endl;
		return false;
	}
	for (int i = 0; i < num.length(); i++) {
		if (num[i] == '.') {
			if (num.length() - i > 2) {
				cerr << "数字输入非法" << endl;
				return false;
			}
			else if (num.length() - i == 0) {
				cerr << "数字输入非法" << endl;
				return false;
			}
			else if (num[i + 1] == '.') {
				cerr << "数字输入非法" << endl;
				return false;
			}
			break;
		}
	}
	return true;
}
bool is_num(char a) {
	return a - '0' >= 0 && a - '9' <= 0;
}
int priority(string a) {
	int num = 0;
	if (a == "+" || a == "-") num = 1;
	else if (a == "*" || a == "/") num = 2;
	else if (a == "(") num = 3;
	return num;
}
double Calculator(string formula) {
	if (formula.length() == 1) {
		cerr << "请勿输入空表达式！！！" << endl;
		exit(-1);
	}
	bool last_is_number = false, last_is_operator = false, last_is_left_half_bracket = false, last_is_right_half_bracket = false;
	vector<double> result;
	vector<string> formula_vector;
	stack<string> ioperator_stack;
	string number;
	for (int cur = 0; cur < formula.length(); cur++) {
		if (formula[cur] == '+' || formula[cur] == '*' || formula[cur] == '/') {
			if (last_is_operator) {
				cerr << "操作符不可连用！！！" << endl;
				exit(-1);
			}
			last_is_number = false;
			last_is_operator = true;
			last_is_left_half_bracket = false;
			last_is_right_half_bracket = false;
			if (ioperator_stack.empty()) {
				ioperator_stack.push(formula.substr(cur,1));
			}
			else if (ioperator_stack.top() == "(") {
				ioperator_stack.push(formula.substr(cur, 1));
			}
			else if (priority(ioperator_stack.top()) < priority(formula.substr(cur, 1))) {
				ioperator_stack.push(formula.substr(cur, 1));
			}
			else {
				while (!ioperator_stack.empty() && ioperator_stack.top() != "(") {
					formula_vector.push_back(ioperator_stack.top());
					ioperator_stack.pop();
				}
				ioperator_stack.push(formula.substr(cur, 1));
			}
			cur++;
		}
		else if (formula[cur] == '-') {
			if (last_is_operator) {
				cerr << "操作符不可连用！！！" << endl;
				exit(-1);
			}
			last_is_number = false;
			last_is_operator = true;
			last_is_left_half_bracket = false;
			last_is_right_half_bracket = false;
			if (cur == 0 || formula[cur - 1] == '(') {
				ioperator_stack.push(formula.substr(cur, 1));
				formula_vector.push_back("0");
			}
			else if (ioperator_stack.empty()) {
				ioperator_stack.push(formula.substr(cur, 1));
				cur++;
			}
			else if (ioperator_stack.top() == "(") {
				ioperator_stack.push(formula.substr(cur, 1));
				cur++;
			}
			else if (priority(ioperator_stack.top()) < priority(formula.substr(cur, 1))) {
				ioperator_stack.push(formula.substr(cur, 1));
				cur++;
			}
			else {
				while (!ioperator_stack.empty() && ioperator_stack.top() != "(") {
					formula_vector.push_back(ioperator_stack.top());
					ioperator_stack.pop();
				}
				ioperator_stack.push(formula.substr(cur, 1));
				cur++;
			}
		}
		else if (formula[cur] == '(') {
			if (last_is_number) {
				cerr << "数字与括号间不能省略符号！！！" << endl;
				exit(-1);
			}
			if (last_is_right_half_bracket) {
				cerr << "括号之间不能直接连接！！！" << endl;
				exit(-1);
			}
			last_is_number = false;
			last_is_operator = false;
			last_is_left_half_bracket = true;
			last_is_right_half_bracket = false;
			ioperator_stack.push(formula.substr(cur, 1));
		}
		else if (formula[cur] == ')') {
			if (cur == 0) {
				cout << "括号不匹配！！！" << endl;
				exit(-1);
			}
			if (last_is_left_half_bracket) {
				cerr << "括号内不能为空！！！" << endl;
				exit(-1);
			}
			if (last_is_operator) {
				cerr << "括号内的式子不能以符号结尾！！！" << endl;
				exit(-1);
			}
			last_is_number = false;
			last_is_operator = false;
			last_is_left_half_bracket = false;
			last_is_right_half_bracket = true;
			if (ioperator_stack.empty()) {
				cerr << "括号不匹配！！！" << endl;
				exit(-1);
			}
			while (ioperator_stack.top() != "(") {
				formula_vector.push_back(ioperator_stack.top());
				ioperator_stack.pop();
				if (ioperator_stack.empty()) {
					cerr << "括号不匹配！！！" << endl;
					exit(-1);
				}
			}
			cur++;
			ioperator_stack.pop();
		}
		else if (is_num(formula[cur])) {
			if (last_is_number) {
				cerr << "数字间必须有符号连接！！！" << endl;
				exit(-1);
			}
			last_is_number = true;
			last_is_operator = false;
			last_is_left_half_bracket = false;
			last_is_right_half_bracket = false;
			for (int i = cur; i < formula.length(); i++) {
				if (formula[i] == ' ') {
					number = formula.substr(cur, i - cur);
					cur = i;
					break;
				}
				else if (formula[i] == ')') {
					number = formula.substr(cur, i - cur);
					cur = i - 1;
					break;
				}
				if (!is_num(formula[i]) && formula[i] != '.') {
					cerr << "数字中不能含有字符！！！" << endl;
					exit(-1);
				}
				else if (i == formula.length() - 1) {
					number = formula.substr(cur, formula.length() - cur);
					cur = i;
					break;
				}
			}
			if (is_valid_number(number)) {
				formula_vector.push_back(number);
			}
			else {
				exit(-1);
			}
		}
		else {
			cerr << "含有非法操作符！！！" << endl;
			exit(-1);
		}
	}
	while (!ioperator_stack.empty()) {
		if (ioperator_stack.top() == "(") {
			cerr << "括号不匹配！！！" << endl;
			exit(-1);
		}
		formula_vector.push_back(ioperator_stack.top());
		ioperator_stack.pop();
	}
	/*for (int i = 0; i < formula_vector.size(); i++) {
		cout << formula_vector[i] << " ";
	}*/
	//cout << endl;
	for (int i = 0; i < formula_vector.size(); i++) {
		double temp = 0;
		if (formula_vector[i] == "+") {
			if (result.size() < 2) {
				cerr << "操作符误用！！！" << endl;
				exit(-1);
			}
			temp = result.back();
			result.pop_back();
			temp += result.back();
			result.pop_back();
			result.push_back(temp);
		}
		else if (formula_vector[i] == "-") {
			if (result.size() < 2) {
				cerr << "操作符误用！！！" << endl;
				exit(-1);
			}
			temp = result.back();
			result.pop_back();
			temp = result.back() - temp;
			result.pop_back();
			result.push_back(temp);
		}
		else if (formula_vector[i] == "*") {
			if (result.size() < 2) {
				cerr << "操作符误用！！！" << endl;
				exit(-1);
			}
			temp = result.back();
			result.pop_back();
			temp = temp * result.back();
			result.pop_back();
			result.push_back(temp);
		}
		else if (formula_vector[i] == "/") {
			if (result.size() < 2) {
				cerr << "操作符误用！！！" << endl;
				exit(-1);
			}
			if (result.back() == 0) {
				cerr << "除数不能为0！！！" << endl;
				exit(-1);
			}
			temp = result.back();
			result.pop_back();
			temp = result.back() / temp;
			result.pop_back();
			result.push_back(temp);
		}
		else {
			result.push_back(atof(formula_vector[i].c_str()));
		}
		//cout << temp << " ";
	}
	//cout << endl;
	return result[0];
}

//int main() {
//	string a = "((4 * 3 + 2) / (6.4 - 2.4) - 10) * (6.4 - 7.2) + (-2) * 4";
//	cout << Calculator(a);
//
//	return 0;
//}

//1 + 2 - 3
//2 * 3 / 4
//(2 + 4 * 3.5) * 6
//((4 * 3 + 2) / (6.4 - 2.4) - 10) * (6.4 - 7.2) + (-2) * 4
//
//1++1
//((1 + 1) * (2 - 1)
//1..1 + 1
//1 / (2 * 4 - 8)

