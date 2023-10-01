#include <iostream>
#include <string>
using namespace std;

string getName(int n)
{
    string name = "";

    while (n > 0)
    {
        int index = (n - 1) % 26;
        name = char(index + 'A') + name;
        n = (n - 1) / 26;
    }

    return name;
}

int main()
{
    int n;
    cin >> n;
    cout << getName(n);
}
