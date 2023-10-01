#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    unsigned long int a, b;
    cin >> a >> b;

    string as = to_string(a);
    string bs = to_string(b);

    for (int i = 0; i < as.length(); i++) {

        auto pointer = find(begin(bs), end(bs), as[i]);
        if (pointer == end(bs)) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;

}
