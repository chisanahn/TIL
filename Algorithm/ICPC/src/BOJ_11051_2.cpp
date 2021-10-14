#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long, long>;

const int MOD = 10007;

int modmul(int a, int b) {
    return (a % MOD) * (b % MOD) % MOD;
}

int modpow(int x, int y) {
    if (y == 0) return 1;
    int ret = modpow(x, y / 2);
    ret = modmul(ret, ret);
    if (y % 2 == 1) ret = modmul(ret, x);
    return ret;
}

int modinv(int x) {
    return modpow(x, MOD - 2);
}

int modfact(int n) {
    if (n == 0)
        return 1;
    else
        return modmul(modfact(n - 1), n);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    
    int ret = modfact(n);
    ret = modmul(ret, modinv(modfact(n - k)));
    ret = modmul(ret, modinv(modfact(k)));
    cout << ret << '\n';
}