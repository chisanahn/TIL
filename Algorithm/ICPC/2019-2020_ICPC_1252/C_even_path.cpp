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

struct cor {
    int r;
    int c;
};

bool check(const vector<int>& R, const vector<int>& C, cor a) {
    // 범위 넘어가는지 체크
    if(a.r > R.size()) return false;
    if(a.c > C.size()) return false;

    if((R[a.r - 1] + C[a.c - 1]) % 2 == 0) return true;
    else return false;
}

bool func(const vector<int>& R, const vector<int>& C, cor a, cor b) {
    if (!check(R, C, a)) return false;
    if (a.r == b.r && a.c == b.c) return true;

    if (func(R, C, {a.r + a.r > b.r ? -1 : 1, a.c}, b)) {
        return true;
    } else if (func(R, C, {a.r, a.c + a.c > b.c ? -1 : 1}, b)) {
        return true;
    } else
        return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> R(n);
    for (auto& r : R) cin >> r;
    vector<int> C(n);
    for (auto& c : C) cin >> c;

    while (q--) {
        cor a, b;
        cin >> a.r >> a.c >> b.r >> b.c;

        // cell이 소수인 경우 예외처리
        if (!check(R, C, b))
            cout << "NO\n";
        else {
            if (func(R, C, a, b))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}