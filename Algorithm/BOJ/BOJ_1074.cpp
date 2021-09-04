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

int pow_2(int n) {
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int r, c;
    cin >> r >> c;

    vector<int> pw;
    int tmp = 1;
    for (int i = 0; i < 29; i++) {
        pw.push_back(tmp);
        tmp *= 2;
    }

    int ret = 0;
    while (n--) {
        ret += pw[2 * n] * (r / pw[n] * 2 + c / pw[n]);
        r %= pw[n];
        c %= pw[n];
    }

    cout << ret << '\n';
}