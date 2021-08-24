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

int fee[1000];
vector<vector<pii>> bus(1000);


const int max_fee = 100000;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        fee[i] = max_fee * 1000;
    }
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        bus[a].push_back({b, c});
    }

    int start, end;
    cin >> start >> end;
    start--;
    end--;
    priority_queue<pii, vector<pii>, greater<pii>> Q;
    Q.push({0, start});
    fee[start] = 0;
    while (!Q.empty()) {
        // 젤 짧은 경로 선택
        int cur = Q.top().second;
        int cost = Q.top().first;
        Q.pop();
        if(cost > fee[cur]) continue;
        // 경로 업데이트
        vector<pii>& adj = bus[cur];
        for (auto& a : adj) {
            int next = a.first;
            int next_cost = fee[cur] + a.second;
            if (fee[next] < next_cost) {
                fee[next] = next_cost;
                Q.push({next_cost, next});
            }
        }
    }
    cout << fee[end] << '\n';
}