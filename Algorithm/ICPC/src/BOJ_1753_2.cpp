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

    int v, e;
    cin >> v >> e;
    int k;
    cin >> k;
    k--;
    vector<vector<pii>> graph(v);
    while (e--) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        graph[u].push_back({v, w});
    }

    vector<int> ret(v, -1);
    priority_queue<pii, vector<pii>, greater<pii>> Q;
    Q.push({0, k});

    while (!Q.empty()) {
        int cur = Q.top().second;
        int cur_w = Q.top().first;
        Q.pop();
        if (ret[cur] == -1) {
            ret[cur] = cur_w;
        } else
            continue;

        vector<pii>& adj = graph[cur];
        for (int i = 0; i < adj.size(); i++) {
            pii a = adj[i];
            if (ret[a.first] == -1)
                Q.push({ret[cur] + a.second, a.first});
        }
    }

    for (auto& r : ret) {
        if (r == -1)
            cout << "INF\n";
        else
            cout << r << '\n';
    }
}