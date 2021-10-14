#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

const ll INF = 123456789;

ll n, m;
vector<vector<pii>> graph(500);
ll path[500];

void path_init() {
    for (ll i = 0; i < n; i++) path[i] = INF;
}

bool bellman_ford(ll start) {
    path[start] = 0;
    // 정점 개수만큼 반복
    for (ll i = 0; i < n - 1; i++) {
        // edge relaxation
        for (ll c1 = 0; c1 < n; c1++) {
            if (path[c1] != INF) {
                vector<pii>& adj = graph[c1];
                for (auto& a : adj) {
                    ll c2 = a.first;
                    ll w = a.second;
                    if (path[c2] > path[c1] + w) {
                        path[c2] = path[c1] + w;
                    }
                }
            }
        }
    }
    // 음수 사이클 존재 여부 확인
    for (ll c1 = 0; c1 < n; c1++) {
        if (path[c1] != INF) {
            vector<pii>& adj = graph[c1];
            for (auto& a : adj) {
                ll c2 = a.first;
                ll w = a.second;
                if (path[c2] > path[c1] + w) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    for (ll i = 0; i < m; i++) {
        ll c1, c2, time;
        cin >> c1 >> c2 >> time;
        c1--;
        c2--;
        graph[c1].push_back({c2, time});
    }
    path_init();
    bool check = bellman_ford(0);
    if (check) {
        for (ll i = 1; i < n; i++) {
            if (path[i] != INF)
                cout << path[i] << '\n';
            else
                cout << "-1\n";
        }
    } else {
        cout << "-1\n";
    }
}