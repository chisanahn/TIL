#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using pii = pair<int, int>;

const int MAX = 123456789;
vector<int> path(800, MAX);
vector<vector<pii>> graph(800);

void daijkstra(int start) {
    path[start] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> Q;
    Q.push({0, start});
    while (!Q.empty()) {
        int cur_w = Q.top().first;
        int cur_v = Q.top().second;
        Q.pop();
        if(cur_w > path[cur_v]) continue;
        vector<pii>& adj = graph[cur_v];
        for (auto& a : adj) {
            if (path[a.first] > cur_w + a.second) {
                path[a.first] = cur_w + a.second;
                Q.push({path[a.first], a.first});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        v1--;
        v2--;
        graph[v1].push_back({v2, w});
        graph[v2].push_back({v1, w});
    }

    int v1, v2;
    cin >> v1 >> v2;
    v1--;
    v2--;

    for (int i = 0; i < n; i++) path[i] = MAX;
    daijkstra(0);
    int toV1 = path[v1], toV2 = path[v2];

    for (int i = 0; i < n; i++) path[i] = MAX;
    daijkstra(n - 1);
    int fromV1 = path[v1], fromV2 = path[v2];

    int ret = MAX;
    // 1 -> v1, v2 -> 목적지 경로가 존재하는 경우
    if (toV1 != MAX && fromV2 != MAX) {
        // 1 -> v2, v1 -> 목적지 경로가 존재하는 경우
        if (toV2 != MAX && fromV1 != MAX) {
            ret = min(toV1 + fromV2, toV2 + fromV1);
        } else {
            ret = toV1 + fromV2;
        }
    } else if (toV2 != MAX && fromV1 != MAX) {
        ret = toV2 + fromV1;
    }

    // v1 -> v2 경로가 있는지 확인 및 결과 출력
    if (ret != MAX) {
        for (int i = 0; i < n; i++) path[i] = MAX;
        daijkstra(v1);
        if (path[v2] != MAX)
            cout << ret + path[v2] << '\n';
        else
            cout << "-1\n";
    } else
        cout << "-1\n";
}