#include <iostream>

using namespace std;

// dp[i][j] = 길이가 i이고 j로 끝나는 수 
int dp[1001][10] = {0};

const int MOD = 10007;

int main() {
    int n;
    cin >> n;

    // 길이가 1인 경우 초기화
    for(int i=0; i<10; i++) {
        dp[1][i] = 1;
    }

    for(int i=1; i<n; i++) {
        for(int j=0; j<10; j++) {
            // j로 끝나는 경우 10-j만큼 추가
            for(int k=j; k<10; k++) {
                dp[i+1][k] += dp[i][j];
                dp[i+1][k] %= MOD;
            }
        }
    }

    long long ret = 0;
    for(int i=0; i<10; i++) {
        ret += dp[n][i];
        ret %= MOD;
    }
    cout << ret << '\n';
}