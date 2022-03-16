#include<string>
#include<iostream>
#include<stack>
#include<vector>
using namespace std;


//error
//操作符误用
//圆括号不匹配
//数字格式有误
//除数为0

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
	vector<double> result;
	vector<string> formula_vector;
	stack<string> ioperator_stack;
	string number;
	for (int cur = 0; cur < formula.length(); cur++) {
		if (formula[cur] == '+' || formula[cur] == '*' || formula[cur] == '/') {
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
			ioperator_stack.push(formula.substr(cur, 1));
		}
		else if (formula[cur] == ')') {
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
		else if (formula[cur] - '0' <= 9 && formula[cur] - '0' >= 0) {
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
	for (int i = 0; i < formula_vector.size(); i++) {
		cout << formula_vector[i] << " ";
	}
	cout << endl;
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
			temp *= result.back();
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
	}
	return result[0];
}

int main() {
	string a = "((4 * 3 + 2) / (6.4 - 2.4) - 10) * (6.4 - 7.2) + (-2) * 4";
	cout << Calculator(a);
	
	return 0;
}
