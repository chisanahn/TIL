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

vector<vector<int>> graph(10000);

vector<vector<int>> SCC;

stack<int> S;
vector<int> num(10000, 10001);
vector<int> check(10000, 0);

int c = 1;

int tajan(int cur) {
    S.push(cur);
    num[cur] = c++;  // 몇번째로 방문한 정점인지 체크

    int ret = num[cur];
    for (auto& g : graph[cur]) {
        if (num[g] == 10001) {
            // dfs 재귀함수로 구현.
            ret = min(ret, tajan(g));
        } else if (check[g] == 0) {
            ret = min(ret, num[g]);
        }
    }
    // SCC 최상단 정점인 경우
    if (ret == num[cur]) {
        vector<int> scc;
        while (!S.empty() && S.top() != cur) {
            scc.push_back(S.top());
            check[S.top()] = 1;
            S.pop();
        }
        scc.push_back(S.top());
        check[S.top()] = 1;
        S.pop();
        sort(scc.begin(), scc.end());
        SCC.push_back(scc);
    } else
        num[cur] = ret;

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // 입력
    int v, e;
    cin >> v >> e;
    while (e--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
    }

    // 타잔 알고리즘
    for (int start = 0; start < v; start++) {
        if (num[start] == 10001) {
            tajan(start);
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