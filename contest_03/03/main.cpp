#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int priority(char op) {
	if (op == '^') {
		return 3;
	}
	else if (op == '*' || op == '/' || op == '%') {
		return 2;
	}
	else if (op == '+' || op == '-') {
		return 1;
	}
	else {
		return 0;
	}
}

vector<string> to_afterchar(const string& per) {
	stack<char> list;
	vector<string> afterchar;
	string str;
	for (char ch : per) {
		if (isdigit(ch)) {
			str += ch;
		}
		else if (ch == '(') {
			list.push(ch);
		}
		else if (ch == ')') {
			while (!list.empty() && list.top() != '(') {
				afterchar.push_back(str);
				str = "";
				str = list.top();
				list.pop();
			}
			if (!list.empty() && list.top() == '(') {
				list.pop();
			}
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^') {
			afterchar.push_back(str);
			str = "";
			while (!list.empty() && priority(ch) <= priority(list.top()) && priority(ch) != 3) {
				str = list.top();
				afterchar.push_back(str);
				str = "";
				list.pop();
			}
			list.push(ch);
		}
	}
	while (!list.empty()) {
		afterchar.push_back(str);
		str = "";
		str = list.top();
		list.pop();
	}
	afterchar.push_back(str);
	return afterchar;
}

int main() {
	string per;
	cin >> per;
	vector <string> afterchar{ to_afterchar(per) };

	for (int i = 0; i < afterchar.size(); i++) {
		cout << afterchar[i] << " ";
	}
}
