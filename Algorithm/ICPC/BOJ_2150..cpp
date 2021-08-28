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
    while (e--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
    }

    // 타잔 알고리즘
    vector<vector<int>> SCC;

    stack<int> S;
    stack<int> realS;
    vector<int> num(v, 10001);
    vector<int> check(v, 0);
    while (1) {
        int start;
        for (start = 0; start < v; start++) {
            if (num[start] == 10001) {
                break;
            }
        }
        if (start == v) break;
        S.push(start);
        realS.push(start);
        num[start] = 1;
        while (!S.empty()) {
            int cur = S.top();
            S.pop();
            bool last = true;
            for (auto& g : graph[cur]) {
                if (num[g] == 10001) {
                    last = false;
                    S.push(cur);
                    S.push(g);
                    realS.push(g);
                    num[g] = num[cur] + 1;
                    break;
                }
            }
            // 방문하지 않은 인접한 정점이 없는 경우
            if (last) {
                int ret = num[cur];
                for (auto& g : graph[cur]) {
                    if (check[g] == 0) {
                        ret = min(ret, num[g]);
                    }
                }
                // SCC 최상단 정점인 경우
                if (ret == num[cur]) {
                    vector<int> scc;
                    while (!realS.empty() && realS.top() != cur) {
                        scc.push_back(realS.top());
                        check[realS.top()] = 1;
                        realS.pop();
                    }
                    scc.push_back(realS.top());
                    check[realS.top()] = 1;
                    realS.pop();
                    sort(scc.begin(), scc.end());
                    SCC.push_back(scc);
                } else
                    num[cur] = ret;
            }
        }
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