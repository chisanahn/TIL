#include <iostream>
#include <vector>

using namespace std;

int n;
int A[250];
int B[250];

int dp[250][65201][2];

int f(int pos, int diff, bool typeA) {
    // base case
    if (pos == n) return diff;
    if(dp[pos][diff][typeA] != -1) return dp[pos][diff][typeA];

    int ret;
    if (typeA) {
        ret = f(pos + 1, diff + A[pos], true);
        if (diff >= B[pos])
            ret = min(ret, B[pos] + f(pos + 1, diff - B[pos], true));
        else
            ret = min(ret, diff + f(pos + 1, B[pos] - diff, false));
    } else {
        ret = f(pos + 1, diff + B[pos], false);
        if (diff >= A[pos])
            ret = min(ret, A[pos] + f(pos + 1, diff - A[pos], false));
        else
            ret = min(ret, diff + f(pos + 1, A[pos] - diff, true));
    }
    return dp[pos][diff][typeA] = ret;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i] >> B[i];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 65201; j++)
            for (int k = 0; k < 2; k++)
                dp[i][j][k] = -1;

    cout << f(0, 0, 0) << '\n';
}