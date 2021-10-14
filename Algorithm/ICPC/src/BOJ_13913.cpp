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

    vector<vector<int>> graph(100001);
    graph[0].push_back(1);
    for (int i = 1; i < graph.size(); i++) {
        graph[i].push_back(i - 1);
        if (i < graph.size() - 1)
            graph[i].push_back(i + 1);
        if (i * 2 < graph.size())
            graph[i].push_back(i * 2);
    }

    int n, k;
    cin >> n >> k;

    queue<int> Q;
    vector<int> visited(100001, 0);
    vector<int> prev(100001, -1);

    Q.push(n);
    visited[n] = 1;
    while(!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        vector<int>& adj = graph[cur];
        for(auto& a : adj) {
            if(visited[a] == 0) {
                visited[a] = 1;
                prev[a] = cur;
                Q.push(a);
            }
        }
    }

    vector<int> path;
    while(prev[k] != -1) {
        path.push_back(k);
        k = prev[k];
    }
    path.push_back(n);
    
    reverse(path.begin(), path.end());
    cout << path.size() - 1 << '\n';
    for(auto& p : path) cout << p << " ";
    cout << '\n';
}