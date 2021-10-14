#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		vector<int> num;
		int input;
		for (int i = 0; i < 4; i++) {
			cin >> input;
			num.push_back(input);
		}
		sort(num.begin(), num.end());
		cout << num[0] * num[2] << "\n";
	}
}