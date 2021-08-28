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

bool comp(vector<int>& a, vector<int>& b) {
    return a[0] < b[0];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // 입력
    int v, e;
    cin >> v >> e;
    vector<vector<int>> graph(v);
    vector<vector<int>> graph_r(v);  // 역방향 그래프
    while (e--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph_r[b].push_back(a);
    }

    // 코사라주 알고리즘

    // 1단게
    stack<int> ret;
    stack<int> S;
    vector<int> visited(v, 0);
    while (ret.size() < v) {
        int start;
        for (int i = 0; i < v; i++) {
            if (visited[i] == 0) {
                start = i;
                break;
            }
        }
        S.push(start);
        visited[start] = 1;
        while (!S.empty()) {
            int cur = S.top();
            S.pop();
            bool check = true;
            for (auto& g : graph[cur]) {
                if (visited[g] == 0) {
                    check = false;
                    S.push(cur);
                    S.push(g);
                    visited[g] = 1;
                    break;
                }
            }
            if (check) ret.push(cur);
        }
    }

    // 2단계
    vector<vector<int>> SCC;
    for (auto& v : visited) v = 0;
    while (!ret.empty()) {
        vector<int> scc;
        int start = ret.top();
        ret.pop();
        if (visited[start] == 1) continue;

        S.push(start);
        visited[start] = 1;
        scc.push_back(start);
        while (!S.empty()) {
            int cur = S.top();
            S.pop();
            for (auto& g : graph_r[cur]) {
                if (visited[g] == 0) {
                    S.push(cur);
                    S.push(g);
                    visited[g] = 1;
                    scc.push_back(g);
                    break;
                }
            }
        }
        sort(scc.begin(), scc.end());
        SCC.push_back(scc);
    }

    //출력
    sort(SCC.begin(), SCC.end(), comp);
    cout << SCC.size() << '\n';
    for (auto& scc : SCC) {
        for (auto& s : scc) {
            cout << s + 1 << " ";
        }
        cout << "-1\n";
    }
}