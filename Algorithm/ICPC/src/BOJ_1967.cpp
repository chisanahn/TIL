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

    int n;
    cin >> n;

    vector<vector<pii>> graph(n);

    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    queue<int> Q;
    // 루트 노드부터의 길이
    vector<int> len(n, -1);
    Q.push(0);
    len[0] = 0;
    int x = 0;
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        vector<pii>& adj = graph[cur];
        for (auto& a : adj) {
            if (len[a.first] == -1) {
                len[a.first] = len[cur] + a.second;
                if (len[a.first] > len[x]) x = a.first;
                Q.push(a.first);
            }
        }
    }

    // x 노드부터의 길이
    for (auto& l : len) l = -1;
    Q.push(x);
    len[x] = 0;
    int ret = 0;
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        vector<pii>& adj = graph[cur];
        for (auto& a : adj) {
            if (len[a.first] == -1) {
                len[a.first] = len[cur] + a.second;
                ret = max(ret, len[a.first]);
                Q.push(a.first);
            }
        }
    }
    cout << ret << '\n';
}