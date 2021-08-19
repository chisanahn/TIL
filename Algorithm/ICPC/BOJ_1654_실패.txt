#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

ll count(const vector<ll>& lengths, ll length) {
	ll ret = 0;
	for (ll i = 0; i < lengths.size(); i++) {
		ret += lengths[i] / length;
	}
	return ret;
}

ll max_length(const vector<ll>& lengths, ll N) {
	ll left, half, right;
	left = 1;
	right = lengths[0];  // 젤 짧은 로프의 길이
	
	while (right - left > 5) {
		half = left + (right - left) / 2;
		// 갯수가 N보다 작으면 크기를 줄인다.
		if (count(lengths, half) < N) {
			right = half - 1;
		}
		// 갯수가 N보다 크거면 크기를 늘린다.
		else if (count(lengths, half) > N) {
			left = half + 1;
		}
		// 갯수가 같으면 half를 포함해서 크기를 늘린다.
		else {
			left = half;
		}
	}

	ll ret = 0;
	for (ll i = left; i <= right; i++) {
		if (count(lengths, i) >= N) {
			if (ret < i) ret = i;
		}
	}
	return ret;
}

int main() {
	ll K, N, temp;
	vector<ll> lengths;
	cin >> K >> N;
	while (K--) {
		cin >> temp;
		lengths.push_back(temp);
	}

	sort(lengths.begin(), lengths.end());
	cout << max_length(lengths, N) << '\n';
}