#include <iostream>

using namespace std;

const int MOD = 10007;

int dp[1001];

int f(int n) {
    if (n < 0) return 0;
    if (dp[n] != -1) return dp[n];
    int ret = f(n - 1) + f(n - 2)*2;
    ret %= MOD;
    return dp[n] = ret;
}

int main() {
    int n;
    cin >> n;

    dp[0] = 1;
    for (int i = 1; i <= n; i++) dp[i] = -1;

    cout << f(n) << '\n';
}