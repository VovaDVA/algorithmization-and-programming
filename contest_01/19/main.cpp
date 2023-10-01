#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string curWord = "";
    vector<string> words;
    vector<string> result;

    while (curWord != "end") {
        cin >> curWord;
        words.push_back(curWord);
    }


    for (int i = 0; i < words.size(); ++i) {
        if (count(result.begin(), result.end(), words.at(i)) == 0 && count(words.begin(), words.end(), words.at(i)) > 1 && words.at(i) != "end") {
            result.push_back(words.at(i));
        }
    }


    sort(result.begin(), result.end());

    for (int i = 0; i < result.size(); i++) {
        cout << result.at(i) << ' ';
    }


        

}
