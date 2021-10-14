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
    vector<int> weight(v, 10000000);
    weight[0] = 0;
    int ret = 0;
    int cur = 0;
    while(1) {
        visited[cur] = 1;
        ret += weight[cur];
        for(auto& adj: graph[cur]) {
            if(visited[adj.first] == 0) {
                weight[adj.first] = min(weight[adj.first], adj.second);
            }
        }

        int i=0;
        int min = 10000000;
        for(; i<v; i++) {
            if(visited[i] == 0 && weight[i] < min) {
                min = weight[i];
                cur = i;
            }
        }
        if(min == 10000000) break;
    }

    cout << ret << '\n';
}