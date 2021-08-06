#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<int> arr;
		arr.push_back(1);
		for (int i = 2; i * i <= N; i++) {
			if (N % i == 0) {
				arr.push_back(i);
				if(i != N/i)
					arr.push_back(N / i);
			}
		}
		int sum = 0;
		for (int i = 0; i < arr.size(); i++) {
			sum += arr[i];
		}

		if (sum == N) cout << "Perfect" << "\n";
		else if (sum < N) cout << "Deficient" << "\n";
		else cout << "Abundant" << "\n";
	}
}