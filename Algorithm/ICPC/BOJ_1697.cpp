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

vector<vector<int>> graph(100001);

int bfs(int n, int k) {
    if (n == k) return 0;

    vector<int> visited(100001, 0);
    vector<int> count(100001, 0);

    queue<int> Q;
    Q.push(n);
    visited[n] = 1;

    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        vector<int>& adj = graph[cur];
        for (auto& a : adj) {
            if (a == k) {
                return count[cur] + 1;
            }
            if (visited[a] == 0) {
                visited[a] = 1;
                Q.push(a);
                count[a] = count[cur] + 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    graph[0].push_back(1);
    for (int i = 1; i < graph.size(); i++) {
        graph[i].push_back(i - 1);
        if (i < graph.size() - 1)
            graph[i].push_back(i + 1);
        if (2 * i <= graph.size() - 1)
            graph[i].push_back(2 * i);
    }

    int n, k;
    cin >> n >> k;

    cout << bfs(n, k) << '\n';
}