#include <cstdlib>
#include<iostream>
#include <string.h>

using namespace std;

int main() {
    string code;

    cin >> code;

    for (int i = 0; i < code.length(); i++) {
        int count = 1;

        while (code[i] == code[i + 1] && i < code.length() - 1) {
            count++;
            i++;
        }

        (count > 1) ? (cout << code[i] << count) : (cout << code[i]);
    }
    return 0;
}
