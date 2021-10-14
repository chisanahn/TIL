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

    int v, e;
    cin >> v >> e;
    vector<vector<pii>> graph(v);
    while(e--) {
        int a, b, c;
        cin>>a>>b>>c;
        a--;b--;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    vector<int> visited(v, 0);
    priority_queue<pii, vector<pii>, greater<pii>> Q;
    Q.push({0, 0});
    int ret = 0;
    while(!Q.empty()) {
        int cur = Q.top().second;
        int w = Q.top().first;
        Q.pop();
        if(visited[cur] == 0) {
            visited[cur] = 1;
            ret += w;
        }else continue;

        for(auto& adj: graph[cur]) {
            if(visited[adj.first] == 0) {
                Q.push({adj.second, adj.first});
            }
        }
    }

    cout << ret << '\n';
}