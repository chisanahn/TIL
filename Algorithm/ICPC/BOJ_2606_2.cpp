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

    int n, t;
    cin >> n >> t;

    vector<vector<int>> graph(n);

    while (t--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> visited(n, 0);
    queue<int> Q;
    visited[0] = 1;
    Q.push(0);

    int ret = 0;
    while (!Q.empty()) {
        int index = Q.front();
        Q.pop();
        vector<int>& adj = graph[index];
        int i;
        for (i = 0; i < adj.size(); i++) {
            int next = adj[i];
            if (visited[next] == 0) {
                visited[next] = 1;
                Q.push(next);
                ret++;
            }
        }
    }

    cout << ret << '\n';
}