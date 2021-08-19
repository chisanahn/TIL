#include <iostream>

using namespace std;

int prime[5000001] = { 0, };

void factorization(int k) {
	while (prime[k] != 0) {
		cout << prime[k] << " ";
		k /= prime[k];
	}
	if (k > 1) cout << k << "\n";
	else cout << "\n";
}

int main() {
	for (int i = 2; i * i < 5000001; i++) {
		if (prime[i] == 0) {
			for (int j = i * i; j < 5000001; j += i) {
				if (prime[j] == 0) {
					prime[j] = i;
				}
			}
		}
	}

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int k;
		cin >> k;
		factorization(k);
	}
}