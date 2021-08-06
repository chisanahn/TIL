#include <iostream>

using namespace std;

int prime(int num) {
	if (num == 1) return 0;
	for (int i = 2; i*i <= num; i++) {
		if (num % i == 0)
			return 0;
	}
	return 1;
}

int main() {
	int T;
	cin >> T;
	int count = 0;
	for(int i=0; i<T; i++) {
		int N;
		cin >> N;
		count += prime(N);
	}
	cout << count << "\n";
}