#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <deque>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long, long>;

struct cor {
    int x;
    int y;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> table(n, vector<int>(n, 0));
    for(auto& r : table) {
        for(auto& rc : r) {
            cin >> rc;
        }
    }

    vector<vector<int>> sum(n+1, vector<int>(n+1, 0));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            sum[i][j] = sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1] + table[i-1][j-1];
        }
    }

    while(m--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1] << '\n';
    }
}