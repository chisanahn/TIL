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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<string> V;
    ll num = 1;
    while (num < 1000000000000000000) {
        string s;
        ll div = num;
        while (div > 0) {
            s.push_back('0' + div % 10);
            div /= 10;
        }
        reverse(s.begin(), s.end());
        V.push_back(s);
        num *= 2;
    }

    int T;
    cin >> T;
    while (T--) {
        string S;
        cin >> S;
        int ret = 123456789;
        for (auto& pw2 : V) {
            if (pw2.size() > S.size()*2) break;
            int count = 0;
            for (auto& s : S) {
                if (pw2.size() == count) break;
                if (pw2[count] == s) count++;
            }
            ret = min(ret, (int)(pw2.size() - count + S.size() - count));
        }
        cout << ret << '\n';
    }
}