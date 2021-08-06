#include <iostream>
#include <vector>

using namespace std;

// 2부터 n까지의 수들 중 소수 출력
void eratos(int m, int n) {
	vector<int> arr(n + 1, 1);
	arr[0] = arr[1] = 0;

	for (int i = 2; i * i <= n; i++) {
		for (int j = 2; j * i <= n; j++) {
			arr[i * j] = 0;
		}
	}

	for (int i = m; i < arr.size(); i++) {
		if (arr[i] == 1)
			cout << i << "\n";
	}
}

int main() {
	int M, N;
	cin >> M >> N;
	eratos(M, N);
}