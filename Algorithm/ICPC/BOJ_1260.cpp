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

    int n, m, v;
    cin >> n >> m >> v;
    v--;

    vector<vector<int>> graph(n);
    while(m--) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(auto& g : graph) {
        sort(g.begin(), g.end());
    }
    
    // DFS
    vector<int> dfs_check(n, 0);
    stack<int> S;
    dfs_check[v] = 1;
    S.push(v);
    cout << v+1 << " ";
    while(!S.empty()) {
        int index = S.top();
        S.pop();
        vector<int>& adj = graph[index];
        for(auto& node : adj) {
            if(dfs_check[node] == 0) {
                dfs_check[node] = 1;
                S.push(index);
                S.push(node);
                cout << node+1 << " ";
                break;
            }
        }
    }
    cout <<'\n';

    // BFS
    vector<int> bfs_check(n, 0);
    queue<int> Q;
    bfs_check[v] = 1;
    Q.push(v);
    cout << v+1 << " ";
    while(!Q.empty()) {
        int index = Q.front();
        Q.pop();
        vector<int>& adj = graph[index];
        for(auto& node : adj) {
            if(bfs_check[node] == 0) {
                bfs_check[node] = 1;
                Q.push(node);
                cout << node+1 << " ";
            }
        }
    }
    cout <<'\n';
}