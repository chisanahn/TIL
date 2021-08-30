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

struct seg {
    int n;
    vector<long long> S;
    long long e = 0;
    seg(const vector<long long>& A) {
        n = A.size();
        S.resize(4 * n);
        init(A, 0, n - 1, 1);
    }
    long long init(const vector<long long>& A, int nodeleft, int noderight, int node) {
        if (nodeleft == noderight) {
            return S[node] = A[nodeleft];
        }
        int mid = (nodeleft + noderight) / 2;
        return S[node] = init(A, nodeleft, mid, node * 2) + init(A, mid + 1, noderight, node * 2 + 1);
    }

    long long query(int left, int right, int node, int nodeleft, int noderight) {
        if (right < nodeleft || noderight < left) return e;
        if (left <= nodeleft && noderight <= right) return S[node];

        int mid = (nodeleft + noderight) / 2;
        return query(left, right, node * 2, nodeleft, mid) + query(left, right, node * 2 + 1, mid + 1, noderight);
    }
    long long query(int left, int right) {
        return query(left, right, 1, 0, n - 1);
    }
    void update(int index, long long newvalue, int node, int nodeleft, int noderight) {
        if (index < nodeleft || noderight < index) return;
        if (nodeleft == noderight) {
            S[node] = newvalue;
            return;
        }
        int mid = (nodeleft + noderight) / 2;
        update(index, newvalue, node * 2, nodeleft, mid);
        update(index, newvalue, node * 2 + 1, mid + 1, noderight);
        S[node] = S[node * 2] + S[node * 2 + 1];
    }
    void update(int index, long long newvalue) {
        update(index, newvalue, 1, 0, n - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> arr(n);
    for (auto& a : arr) cin >> a;

    seg S(arr);

    for (int i = 0; i < m + k; i++) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int b;
            ll c;
            cin >> b >> c;
            b--;
            S.update(b, c);
        }
        if (cmd == 2) {
            int b, c;
            cin >> b >> c;
            b--;
            c--;
            cout << S.query(b, c) << '\n';
        }
    }
}
