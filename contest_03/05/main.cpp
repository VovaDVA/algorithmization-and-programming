#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>

using namespace std;

int main() {
	int n;
	cin >> n;
	map<string, int> words;

	for (int i = 0; i < n; ++i) {
		string word;
		cin >> word;
		words[word]++;
	}

	int max_cnt = 0;

	for (const auto& [word, cnt] : words) {
		max_cnt = max(words[word], max_cnt);
	}

	for (const auto& [word, cnt] : words) {
		if (words[word] == max_cnt) {
			cout << word << " ";
		}
	}

}
