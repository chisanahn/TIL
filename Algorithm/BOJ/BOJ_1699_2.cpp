#include <iostream>

using namespace std;

int dp[100001];

int main() {
    int n;
    cin >> n;

    dp[0] = 0; dp[1] = 1;
    for(int i=2; i<=n; i++) {
        int ret = 987654321;
        for(int j=1; j*j<=i; j++) {
            ret = min(ret, dp[i-j*j]+1);
        }
        dp[i] = ret;
    }

    cout << dp[n] << '\n';
}