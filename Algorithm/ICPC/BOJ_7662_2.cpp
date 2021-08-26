#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
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

    int T;
    cin >> T;
    while (T--) {
        map<int, int> Q;
        int K;
        cin >> K;
        while (K--) {
            string cmd;
            cin >> cmd;
            if (cmd == "I") {
                int n;
                cin >> n;
                Q[n] += 1;
            } else if (cmd == "D") {
                int n;
                cin >> n;
                if (!Q.empty()) {
                    if (n == 1) {
                        (--Q.end())->second -= 1;
                        if ((--Q.end())->second == 0) {
                            Q.erase(--Q.end());
                        }
                    } else if (n == -1) {
                        Q.begin()->second -= 1;
                        if (Q.begin()->second == 0) {
                            Q.erase(Q.begin());
                        }
                    }
                }
            }
        }
        if (Q.empty())
            cout << "EMPTY\n";
        else
            cout << (--Q.end())->first << " " << Q.begin()->first << '\n';
    }
}