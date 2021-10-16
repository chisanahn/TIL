#include <iostream>

using namespace std;
using ll = long long;

// dp[i][j] = 길이가 i이고 j로 끝나는 이친수의 개수
ll dp[91][2];

int main() {
    ll n;
    cin >> n;

    // 길이가 1인 경우 초기화
    dp[1][0] = 0;
    dp[1][1] = 1;

    for(ll i=2; i<=n; i++) {
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }

    cout << dp[n][0] + dp[n][1] << '\n';
}