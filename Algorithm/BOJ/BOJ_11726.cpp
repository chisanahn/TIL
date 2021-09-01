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

const int MOD = 10007;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int ret[1001];
    ret[0] = 0;
    ret[1] = 1;
    ret[2] = 2;

    int n;
    cin >> n;

    for (int i = 3; i <= n; i++) {
        ret[i] = (ret[i - 1] + ret[i - 2]) % MOD;
    }

    cout << ret[n] << '\n';
}