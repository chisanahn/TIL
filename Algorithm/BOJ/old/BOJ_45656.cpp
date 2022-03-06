#include <iostream>

using namespace std;
using ll = long long;

// dp[i][j] = 길이가 i이고 j로 끝나는 계단수 개수
ll dp[101][10];

const ll MOD = 1000000000;

int main() {
    int n;
    cin >> n;

    // 길이가 1인 계단수 초기화
    dp[1][0] = 0;
    for(int i=1; i<=9; i++) dp[1][i] = 1;

    for (int i = 1; i < n; i++) {
        dp[i+1][0] += dp[i][1];
        for(int j=1; j<=8; j++) {
            dp[i+1][j] += dp[i][j-1];
            dp[i+1][j] += dp[i][j+1];
        }
        dp[i+1][9] += dp[i][8];

        for(int j=0; j<10; j++) dp[i+1][j] %= MOD;
    }

    ll ret = 0;
    for(int j=0; j<10; j++) {
        ret += dp[n][j];
        ret %= MOD;
    }
    cout << ret << '\n';
}