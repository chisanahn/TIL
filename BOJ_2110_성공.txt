#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int func(vector<int>& A, int c) {
	int left = 1;
	int right = (A.back() - A.front()) / (c - 1);
	int mid;
	int dist, count;
	while (right - left > 5) {
		mid = left + (right - left) / 2;
		dist = 0; count = 1;
		for (int i = 1; i < A.size(); i++) {
			dist += A[i] - A[i - 1];
			if (dist >= mid) {
				dist = 0;
				count++;
			}
		}

		if (count < c) {
			right = mid - 1;
		}
		else {
			left = mid;
		}
	}

	int max = 0;
	for (int mid = left; mid <= right; mid++) {
		dist = 0; count = 1;
		for (int i = 1; i < A.size(); i++) {
			dist += A[i] - A[i - 1];
			if (dist >= mid) {
				dist = 0;
				count++;
			}
		}
		if (count >= c) {
			if (max < mid) max = mid;
		}
	}

	return max;
}

int main() {
	int n, c;
	cin >> n >> c;
	vector<int> A(n);
	for (auto& a : A) cin >> a;
	sort(A.begin(), A.end());

	cout << func(A, c) << "\n";
}