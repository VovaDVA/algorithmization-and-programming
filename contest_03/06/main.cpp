#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

int main() {
	int n;
	cin >> n;
	map<string, int> users;

	for (int i = 0; i < n; ++i) {
		string login;
		int balance;
		cin.ignore();
		getline(cin, login, ';');
		cin >> balance;
		users[login] = balance;
	}
	
	int m;
	cin >> m;
	vector<int> user_bal;

	for (int i = 0; i < m; ++i) {
		string login;
		cin >> login;
		user_bal.push_back(users[login]);
	}

	for (const auto& bal : user_bal) {
		cout << bal << " ";
	}

}
