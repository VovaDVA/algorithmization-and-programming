#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	long long ml, mr, summ = 0;
	cin >> n;

	vector<int> nums(n);
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}

	for (int i = 0; i < n; i++) {
		mr = 0;
		ml = 0;
		for (int j = 0; j < i; j++) {
			if (nums[j] > ml) {
				ml = nums[j];
			}
		}
		for (int k = i + 1; k < n; k++) {
			if (nums[k] > mr) {
				mr = nums[k];
			}
		}
		if (nums[i] < mr && nums[i] < ml) {
			summ += min(ml, mr) - nums[i];
		}
	}

	cout << summ << endl;
}
