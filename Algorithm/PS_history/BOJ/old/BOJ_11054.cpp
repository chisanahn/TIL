#include <iostream>

using namespace std;

int n;
int A[1000];

int dp[1000][1001][2];

int f(int index, int pre, bool check) {
    // base case
    if (index == n) return 0;
    if(dp[index][pre][check] != -1) return dp[index][pre][check];

    int ret = 0;
    // 증가하고 있는 경우
    if (check) {
        // A[index]가 전보다 큰 경우
        if (pre < A[index]) {
            // A[index]를 포함하는 경우
            ret = max(ret, f(index + 1, A[index], check) + 1);
            ret = max(ret, f(index + 1, A[index], !check) + 1);
        }
        // A[index]를 포함하지 않는 경우
        ret = max(ret, f(index + 1, pre, check));
        ret = max(ret, f(index + 1, pre, !check));
    } else {
        if (pre > A[index]) {
            // A[index]를 포함하는 경우
            ret = max(ret, f(index + 1, A[index], check) + 1);
        }
        // A[index]를 포함하지 않는 경우
        ret = max(ret, f(index + 1, pre, check));
    }
    return dp[index][pre][check] = ret;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];

    for(int i=0; i<n; i++) {
        for(int j=0; j<1001; j++) {
            dp[i][j][0] = dp[i][j][1] = -1;
        }
    }

    cout << f(0, 0, true) << '\n';
}