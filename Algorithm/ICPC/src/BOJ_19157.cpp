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

int row[100001];
int col[100001];

bool check_r(int r1, int r2) {
    if (r1 > r2) return check_r(r2, r1);
    return (row[r2] - row[r1 - 1]) % (r2 - r1 + 1) == 0;
}

bool check_c(int c1, int c2) {
    if (c1 > c2) return check_c(c2, c1);

    return (col[c2] - col[c1 - 1]) % (c2 - c1 + 1) == 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    row[0] = 0;
    col[0] = 0;
    for (int i = 1; i <= n; i++) {
        int input;
        cin >> input;
        row[i] = row[i - 1] + input % 2;
    }
    for (int i = 1; i <= n; i++) {
        int input;
        cin >> input;
        col[i] = col[i - 1] + input % 2;
    }

    while (q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        if (check_r(r1, r2) && check_c(c1, c2))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}