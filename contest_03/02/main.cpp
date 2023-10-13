#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string s;
    getline(cin, s, '!');

    stack<char> stack;

    for (char c : s) {
        switch (c) {
            case '(': stack.push(')'); break;
            case '[': stack.push(']'); break;
            case '{': stack.push('}'); break;

            case ')':
            case ']':
            case '}':
                if (stack.empty() || stack.top() != c) {
                    cout << "NO";
                    return 0;
                }
                stack.pop();
                break;
            default:
                break;
            }
    }

    cout << (stack.empty() ? "YES" : "NO");
}
