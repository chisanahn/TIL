#include <iostream>

using namespace std;

int n;
int A[301];
int dp[301][3];

// 꼭 첫번째 계단에서 시작하라는 법이 없다.
int f(int index, int cnt) {
    // base case;
    if (index == n) return A[n];
    if (dp[index][cnt] != -1) return dp[index][cnt];

    // 3번 조건
    if (index == n - 1) return dp[index][cnt] = A[index] + A[n];
    // 2번 조건 & 3번 조건
    if ((n > 2 && index == n - 2) || cnt > 1) return dp[index][cnt] = f(index + 2, 1) + A[index];

    return dp[index][cnt] = max(f(index + 2, 1), f(index + 1, cnt + 1)) + A[index];
}

int main() {
    // 초기화
    for (int i = 0; i < 301; i++) {
        for (int j = 0; j < 3; j++) {
            dp[i][j] = -1;
        }
    }

    cin >> n;
    A[0] = 0;  // 시작점은 계단에 포함되지 않는다.
    for (int i = 1; i <= n; i++) cin >> A[i];

    cout << f(0, 0) << '\n';
}