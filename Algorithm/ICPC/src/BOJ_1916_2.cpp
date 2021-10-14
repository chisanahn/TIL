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

    int n, m;
    cin >> n >> m;
    vector<vector<pii>> graph(n);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        graph[a].push_back({b, c});
    }

    vector<int> visited(n, 0);
    vector<int> len(n, 100000000);
    priority_queue<pii, vector<pii>, greater<pii>> Q;
    int start, end;
    cin >> start >> end;
    start--;
    end--;

    len[start] = 0;
    Q.push({0, start});
    while (!Q.empty()) {
        int cur = Q.top().second;
        Q.pop();
        if (visited[cur] == 0) {
            visited[cur] = 1;
        } else
            continue;

        // 인접한 노드 경로 업데이트
        for (auto& adj : graph[cur]) {
            if (visited[adj.first] == 0) {
                if (len[adj.first] > len[cur] + adj.second) {
                    len[adj.first] = len[cur] + adj.second;
                    Q.push({len[adj.first], adj.first});
                }
            }
        }
    }

    cout << len[end] << '\n';
}