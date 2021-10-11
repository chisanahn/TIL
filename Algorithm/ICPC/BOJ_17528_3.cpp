#include <iostream>
#include <vector>

using namespace std;

int n;
int A[250];
int B[250];
int dp[250][65201];

// A의 누적 시간이 B보다 크되, B에게 최대한 많이 넘겨주기.
// 리턴값 : a_sum에서 줄어든 값
int f(int pos, int a_sum) {
    // base case
    if (pos == n) return 0;
    if (dp[pos][a_sum] != -1) return dp[pos][a_sum];

    // B공장으로 작업을 넘겨주지 않는 경우
    int ret = f(pos + 1, a_sum);
    // B공장으로 작업을 넘겨주는 경우
    ret = max(ret, B[pos] + f(pos + 1, a_sum - A[pos]));
    return dp[pos][a_sum] = ret;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i] >> B[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 65201; j++) {
            dp[i][j] = -1;
        }
    }
    dp[1][0] = 0;
    f(0, 0);

    int ret = 987654321;
    for(int i=0; i<65201; i++) {
        ret = min(ret, max(dp[n-1][i], i));
    }
    cout << ret << '\n';
}