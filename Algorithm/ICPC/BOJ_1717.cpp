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

class DSU {
    vector<int> parent;
    vector<int> count;

   public:
    DSU(int n) : parent(n), count(n, 0) {
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int find(int n) {
        if (parent[n] == n)
            return n;
        else
            return parent[n] = find(parent[n]);
    }
    void merge(int a, int b) {
        int u = find(a);
        int v = find(b);
        if (count[u] > count[v]) {
            parent[v] = u;
            count[u]++;
        } else {
            parent[u] = v;
            count[v]++;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    DSU dsu(n + 1);
    while (m--) {
        int cmd;
        cin >> cmd;
        if (cmd == 0) {
            int a, b;
            cin >> a >> b;
            dsu.merge(a, b);
        }
        if (cmd == 1) {
            int a, b;
            cin >> a >> b;
            if (dsu.find(a) == dsu.find(b))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}