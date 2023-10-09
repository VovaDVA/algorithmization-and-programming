#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
	int n, m;
	cin >> n;
	set<string> first;

	for (int i = 0; i < n; ++i) {
		string word;
		cin >> word;
		first.insert(word);
	}

	cin >> m;
	set<string> second;

	for (int i = 0; i < m; ++i) {
		string word;
		cin >> word;
		second.insert(word);
	}

	set<string> words;
	for (const string& word : first) {
		if (second.find(word) != second.end()) {
			words.insert(word);
		}
	}

	if (words.empty()) {
		cout << -1;
	}
	else {
		for (const string& word : words) {
			cout << word << " ";
		}
	}

}
