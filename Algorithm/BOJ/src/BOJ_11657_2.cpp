#include <iostream>
#include <vector>

using namespace std;
using pii = pair<int, int>;
using ll = long long;

const ll INF = 987654321;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> G(n);
    vector<ll> time(n, INF);
    time[0] = 0;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        G[a].push_back({b, c});
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            if (time[j] == INF) continue;
            vector<pii> adj = G[j];
            for (auto& a : adj) {
                time[a.first] = min(time[a.first], time[j] + a.second);
            }
        }
    }
    // 음수 사이클 체크
    bool cycle = false;
    for (int j = 0; j < n; j++) {
        if (time[j] == INF) continue;
        vector<pii> adj = G[j];
        for (auto& a : adj) {
            if (time[a.first] > time[j] + a.second)
                cycle = true;
        }
    }

    if(cycle) cout << "-1\n";
    else {
        for(int i=1; i<n; i++) {
            if(time[i] == INF) cout << "-1\n";
            else cout << time[i] << '\n';
        }
    }
}