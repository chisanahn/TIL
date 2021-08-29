// dfs 재귀함수로 구현

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

vector<vector<int>> graph(100);
vector<int> visit(100, 0);
stack<int> S;

void dfs(int cur) {
    S.push(cur);
    visit[cur] = 1;
    for(auto& g : graph[cur]) {
        if(visit[g] == 0) dfs(g);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, t;
    cin >> n >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }

    dfs(0);
    cout << S.size()-1 << '\n';
}