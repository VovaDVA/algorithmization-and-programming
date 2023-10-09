#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(const int& left, const int& right)
{
    return left < right;
}

int main()
{
    int n;
    cin >> n;

    vector<int> N(n);
    for (int i = 0; i < n; i++) {
        cin >> N[i];
    }

    int m;
    cin >> m;

    vector<int> M(m);
    for (int i = 0; i < m; i++) {
        cin >> M[i];
    }

    vector<int> res(n + m);
    for (int i = 0; i < n + m; i++) {
        if (i < n) {
            res[i] = N[i];
        }
        else {
            res[i] = M[i - n];
        }
    }

    sort(begin(res), end(res), compare);
    for (int i = 0; i < n + m; i++) {
        cout << res[i] << ' ';
    }
}
