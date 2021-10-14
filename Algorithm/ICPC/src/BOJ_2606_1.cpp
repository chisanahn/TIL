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

    int n, t;
    cin >> n >> t;

    // 인접 노드
    vector<vector<int>> graph(n);
    // 방문여부
    vector<int> visit(n, 0);

    while (t--) {
        int a, b;
        cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }

    // dfs - 0에서 시작
    stack<int> S;
    int index = 0;
    visit[0] = 1;
    int ret = 0;
    
    while (1) {
        int i;
        // index 노드와 인접한 노드 중 방문하지 않은 노드 방문
        vector<int>& adj = graph[index];
        for (i = 0; i < adj.size(); i++) {
            int next = adj[i];
            if (visit[next] == 0) {
                visit[next] = 1;
                S.push(index);
                index = next;
                ret++;
                break;
            }
        }
        // 더이상 방문할 노드가 없는 경우 이전 노드로 이동
        if (i == adj.size()) {
            if (S.empty()) break;
            index = S.top();
            S.pop();
        }
    }

    cout << ret << '\n';
}