#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

bool compare(pair<string, int>& a, pair<string, int>& b) {
    return a.second > b.second;
}

void map_sort(map<string, int>& M) {

    vector<pair<string, int>> A;

    for (auto& it : M) {
        A.push_back(it);
    }

    sort(A.begin(), A.end(), compare);

    int cnt = 0;
    for (auto& it : A) {
        if (cnt < 3) {
            cout << it.first << ' ';
            cnt++;
        }
    }
}

int main() {
    ifstream file("data.txt");

    string target;
    cin >> target;
    
    vector<string> words;

    if (file.is_open()) {
        string word;
        while (file >> word) {
            words.push_back(word);
        }
    }

    map<string, int> result;

    for (int i = 0; i < size(words) - 1; i++) {
        if (words[i] == target) {
            result[words[i + 1]]++;
        }
    }

    if (empty(result)) { cout << '-';  return 0; }

    map_sort(result);

}

