#include <iostream>

using namespace std;

const int MOD = 10007;

int dp[1005] = {
    0,
};

int main() {
    int n;
    cin >> n;

    dp[0] = 1;
    for (int i = 0; i <= n; i++) {
        dp[i] %= MOD;
        dp[i + 1] += dp[i];
        dp[i + 2] += dp[i] * 2;
    }

    cout << dp[n] << '\n';
}