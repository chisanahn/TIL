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

    vector<vector<pii>> graph(v);
    while (e--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    vector<int> visited(v, 0);
    vector<int> len(v, 123456789);
    int cur = 0;
    visited[cur] = 1;
    len[cur] = 0;

    int ret = 0;
    while (1) {
        vector<pii>& adj = graph[cur];
        for (auto& a : adj) {
            if (len[a.first] > len[cur] + a.second) {
                len[a.first] = len[cur] + a.second;
            }
        }
        int min_len = 123456789;
        int next = -1;
        for (int i = 0; i < adj.size(); i++) {
            pii& a = adj[i];
            if (visited[a.first] == 0 && len[a.first] < min_len) {
                visited[a.first] = 1;
                next = i;
                min_len = a.first;
            }
        }
        if (next == -1) break;
        cur = adj[next].first;
        ret += adj[next].second;
    }

    cout << ret << '\n';
}