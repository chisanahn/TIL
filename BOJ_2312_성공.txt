#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;

		for (int i = 2; N > 1; i++) {
			int count = 0;
			while (N % i == 0) {
				if (!count) cout << i << " ";
				count++;
				N /= i;
			}
			if (count) cout << count << "\n";
		}

	}
}