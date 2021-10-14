#include <iostream>
#include <vector>

using namespace std;
using pii = pair<int, int>;

int n;
int W[100];
int V[100];

int dp[100][100001];

int knapsack(int pos, int k) {
    // base case
    if (pos == n) return 0;
    if(dp[pos][k] != -1) return dp[pos][k];
    // pos번째 물건을 넣지 않는 경우
    int ret = knapsack(pos + 1, k);
    // pos번째 물건을 넣는 경우
    if (k >= W[pos])
        ret = max(ret, V[pos] + knapsack(pos + 1, k - W[pos]));
    return dp[pos][k] = ret;
}

int main() {
    int k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> W[i] >> V[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = -1;
        }
    }
    cout << knapsack(0, k);
}