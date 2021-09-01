#include <iostream>

using namespace std;

using ll = long long;

ll madd(ll a, ll b, ll p) { return (a + b) % p; }
ll msub(ll a, ll b, ll p) { return (a - b + p) % p; }
ll mmul(ll a, ll b, ll p) { return (a * b) % p; }

ll mpow(ll x, ll y, ll p) {
	ll ret = 1;
	while (1) {
		if (y % 2) ret = mmul(ret, x, p);
		if (y <= 1) break;
		ret = mmul(ret, ret, p);
		y /= 2;
	}
	return ret;
}
ll mdiv(ll a, ll b, ll p) { return mmul(a, mpow(b, p - 2, p), p); }

ll mfact(ll a, ll p) {
	ll ret = 1;
	for (ll i = 1; i <= a; i++) {
		ret = mmul(ret, i, p);
	}
	return ret;
}

ll c(ll N, ll K, ll p) {
	ll ret = mfact(N, p);
	ret = mdiv(ret, mfact(K, p), p);
	ret = mdiv(ret, mfact(N - K, p), p);
	return ret;
}

int main() {
	const ll MOD = 1000000007;
	ll M, N, K;
	cin >> M;
	while (M--) {
		cin >> N >> K;
		cout << c(N, K, MOD) << "\n";
	}
}