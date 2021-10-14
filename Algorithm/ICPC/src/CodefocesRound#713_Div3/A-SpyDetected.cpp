#include <iostream>

using namespace std;

int checker(int n, int a[]) {
	int same = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] != same) {
			//a[i]가 다른 수인 경우
			if (i + 1 == n || a[i + 1] == same) return i + 1;
			//a[0]이 다른 수인 경우
			if (a[i + 1] != same) return 1;
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		int a[100];
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cout << checker(n, a) << "\n";
	}
}