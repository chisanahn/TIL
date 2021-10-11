#include <iostream>
#include <vector>

using namespace std;

int n;
int a_sum = 0;
int A[250];
int B[250];

int dp[250][65201];

int f(int pos, int b_sum) {
    // base case
    if (pos == n) return a_sum > b_sum ? a_sum : b_sum;
    if(dp[pos][b_sum] != -1) return dp[pos][b_sum];
    // B공장으로 작업을 넘겨주는 경우
    a_sum -= A[pos];
    int ret = f(pos + 1, b_sum + B[pos]);
    a_sum += A[pos];
    // B공장으로 작업을 넘겨주지 않는 경우
    ret = min(ret, f(pos + 1, b_sum));
    return dp[pos][b_sum] = ret;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i] >> B[i];
        a_sum += A[i];
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<65201; j++) {
            dp[i][j] = -1;
        }
    }
    cout << f(0, 0) << '\n';
}