#include <iostream>
#include <vector>

using namespace std;

int A[1001];
int n;

int dp[1001][1001];

int f(int pre, int index) {
    // base case
    if(index==n) return 0;
    if(dp[pre][index] != -1) return dp[pre][index];
    
    if(A[index] > pre) {
        return dp[pre][index] = max(f(pre, index+1), f(A[index], index+1)+A[index]);
    }
    else {
        return dp[pre][index] = f(pre, index+1);
    }
}

int main() {
    for(int i=0; i<1001; i++) {
        for(int j=0; j<1001; j++) {
            dp[i][j] = -1;
        }
    }
    cin >> n;
    for(int i=0; i<n; i++) cin >> A[i];
    cout << f(0, 0) << '\n';
}