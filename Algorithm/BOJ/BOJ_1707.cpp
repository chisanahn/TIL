#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> graph(n);
        vector<int> group(n, -1);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        bool ret = true;
        for (int i = 0; i < n; i++) {
            if (group[i] == -1) {
                queue<int> Q;
                Q.push(i);
                group[i] = 0;
                while (!Q.empty()) {
                    int cur = Q.front();
                    Q.pop();
                    vector<int>& adj = graph[cur];
                    for (auto& a : adj) {
                        if (group[a] == -1) {
                            Q.push(a);
                            group[a] = !group[cur];
                        } else if (group[a] == group[cur]) {
                            ret = false;
                            break;
                        }
                    }
                }
            }
        }
        if (ret)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}