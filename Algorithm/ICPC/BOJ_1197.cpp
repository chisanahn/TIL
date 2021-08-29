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

struct DSU {
    vector<int> dsu;
    vector<int> len;
    DSU(int n) {
        for (int i = 0; i < n; i++) {
            dsu.push_back(i);
            len.push_back(1);
        }
    }
    bool onlyone() {
        int count = 0;
        for (auto& l : len) {
            if (l > 0) count++;
        }
        if (count == 1)
            return true;
        else
            return false;
    }
    int find(int n) {
        if (dsu[n] == n)
            return n;
        else {
            dsu[n] = find(dsu[n]);
            return dsu[n];
        }
    }
    bool merge(int a, int b) {
        int ap = find(a);
        int bp = find(b);
        // 이미 같은 그룹에 속해있는 경우
        if (ap == bp) return false;

        if (len[ap] == len[bp]) {
            dsu[bp] = dsu[ap];
            len[ap] += 1;
            len[bp] = 0;
        } else if (len[ap] > len[bp]) {
            dsu[bp] = ap;
            len[bp] = 0;
        } else {
            dsu[ap] = bp;
            len[ap] = 0;
        }
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int v, e;
    cin >> v >> e;
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> edges;
    while (e--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        edges.push({c, {a, b}});
    }

    DSU D(v);

    int ret = 0;
    while (!edges.empty() && !D.onlyone()) {
        pair<int, pii> cur = edges.top();
        edges.pop();
        if(D.merge(cur.second.first, cur.second.second)) {
            ret += cur.first;
        };
    }

    cout << ret << '\n';
}