#include <iostream>
#include <vector>

using namespace std;

int A[1001];
int n;

int dp[1001][1001];

int f(int pre, int index) {
    cout << "dp[" << pre << "][" << index << "]\n";
    // base case
    if(index==n) return 0;
    if(dp[pre][index] != -1) {
        cout << "중복되는 부분\n";  
        return dp[pre][index];
    }
    
    if(A[index] > pre) {
        return dp[pre][index] = max(f(pre, index+1), f(A[index], index+1)+A[index]);
    }
    else {
        return dp[pre][index] = f(pre, index+1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i=0; i<1001; i++) {
        for(int j=0; j<1001; j++) {
            dp[i][j] = -1;
        }
    }
    cin >> n;
    for(int i=0; i<n; i++) cin >> A[i];
    cout << f(0, 0) << '\n';
}