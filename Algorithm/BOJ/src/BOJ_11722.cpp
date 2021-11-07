#include <iostream>

using namespace std;

int A[1001];
int dp[1001];

int main() {
    int n;
    cin >> n;
    int ret = 0;
    for(int i=0; i<n; i++) {
        cin >> A[i];
        dp[i] = 1;
        for(int j=0; j<i; j++) {
            if(A[i]<A[j] && dp[i]<dp[j]+1)
            dp[i] = dp[j]+1;
        }
        ret = max(ret, dp[i]);
    }

    cout << ret << '\n';
}