#include <iostream>

using namespace std;

int n;
int A[1001];
int dp[1002][1001];

int f(int pre, int index) {
    // base case
    if (index == n) return 0;
    if(dp[pre][index] != -1) return dp[pre][index];

    if (A[index] < pre)
        return dp[pre][index] = max(f(pre, index + 1), f(A[index], index + 1) + 1);
    else
        return dp[pre][index] = f(pre, index + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < 1002; i++) {
        for (int j = 0; j < 1001; j++) {
            dp[i][j] = -1;
        }
    }

    cout << f(1001, 0) << '\n';
}