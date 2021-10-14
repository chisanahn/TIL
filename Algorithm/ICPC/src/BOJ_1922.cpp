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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<pii>> graph(n);
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;b--;
        graph[a].push_back({b, c});
        graph[b].push_back({a,c});
    }

    priority_queue<pii, vector<pii>, greater<pii>> Q;
    vector<int> visit(n, 0);
    Q.push({0, 0});
    int ret = 0;
    while(!Q.empty()) {
        int cur = Q.top().second;
        int w = Q.top().first;
        Q.pop();
        if(visit[cur] == 0) {
            visit[cur] = 1;
            ret += w;
        }
        else continue;

        for(auto& adj : graph[cur]) {
            if(visit[adj.first] == 0) {
                Q.push({adj.second, adj.first});
            }
        }
    }

    cout << ret << '\n';
}