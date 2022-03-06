#include <iostream>

using namespace std;

int dp[100001];

int f(int n) {
    // base case
    if (n == 0) return 0;
    if (dp[n] != -1) return dp[n];

    int result = 987654321;
    for (int i = 1; i * i <= n; i++) {
        result = min(result, f(n - i * i) + 1);
    }
    return dp[n] = result;
}

int main() {
    for (int i = 0; i < 100001; i++) dp[i] = -1;

    int n;
    cin >> n;
    cout << f(n) << '\n';
}