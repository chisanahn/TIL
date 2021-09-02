#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long, long>;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> visit(n, 0);
    int count = 0;
    while (1) {
        int start;
        for (start = 0; start < n; start++) {
            if (visit[start] == 0) break;
        }
        if (start == n) break;

        count++;
        queue<int> Q;
        Q.push(start);
        visit[start] = 1;
        while (!Q.empty()) {
            int cur = Q.front();
            Q.pop();
            for (auto& adj : graph[cur]) {
                if (visit[adj] == 0) {
                    visit[adj] = 1;
                    Q.push(adj);
                }
            }
        }
    }
    cout << count << '\n';
}