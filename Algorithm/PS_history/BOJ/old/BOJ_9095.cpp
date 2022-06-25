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

vector<int> ret(11, 0);
vector<int> fact(11, 0);

int f(int n) {
    if (fact[n] != 0) return fact[n];
    fact[n] = f(n - 1) * n;
    return fact[n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fact[0] = 1;
    for (int i = 1; i < 11; i++) {
        for (int n3 = 0; n3 <= i; n3 += 3) {
            for (int n2 = 0; n2 + n3 <= i; n2 += 2) {
                // 3이 x개, 2가 y개, 1이 z개
                // 배열하는 방법: (x+y+z)!/(x!y!z!)
                int x = n3 / 3;
                int y = n2 / 2;
                int z = i - n2 - n3;
                ret[i] += f(x + y + z) / (f(x) * f(y) * f(z));
            }
        }
    }

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << ret[n] << '\n';
    }
}