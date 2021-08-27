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

    vector<int> ret(v, 123456789);
    priority_queue<pii, vector<pii>, greater<pii>> Q;
    Q.push({0, k});
    ret[k] = 0;

    while (!Q.empty()) {
        int cur = Q.top().second;
        Q.pop();

        for (auto& a : graph[cur]) {
            if (ret[a.first] > ret[cur] + a.second) {
                ret[a.first] = ret[cur] + a.second;
                Q.push({ret[a.first], a.first});
            }
        }
    }

    for (auto& r : ret) {
        if (r == 123456789)
            cout << "INF\n";
        else
            cout << r << '\n';
    }
}