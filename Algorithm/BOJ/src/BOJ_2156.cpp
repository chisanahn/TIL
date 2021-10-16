#include <iostream>

using namespace std;

int A[10002];

// dp[i][j] = i번째 잔을 선택할 차례이고, 연속으로 j잔을 마셨을때의 최대 포도주양
int dp[10002][3] = {0};

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i];

    for (int i = 1; i <= n + 1; i++) {
        dp[i][0] = dp[i-1][0];
        for (int j = 1; j < 3; j++) {
            // i번째 잔을 마시지 않는 경우
            dp[i][0] = max(dp[i][0], dp[i - 1][j]);
            // 마시는 경우
            if (j == 1 || dp[i - 1][j - 1] != 0)
                dp[i][j] = dp[i - 1][j - 1] + A[i];
        }
    }

    cout << dp[n + 1][0] << '\n';
}