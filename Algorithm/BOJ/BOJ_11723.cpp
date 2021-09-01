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

    map<int, int> S;
    int m;
    cin >> m;
    while (m--) {
        string cmd;
        cin >> cmd;
        if (cmd == "add") {
            int n;
            cin >> n;
            S[n] = 1;
        } else if (cmd == "remove") {
            int n;
            cin >> n;
            S[n] = 0;
        } else if (cmd == "check") {
            int n;
            cin >> n;
            cout << S[n] << '\n';
        } else if (cmd == "toggle") {
            int n;
            cin >> n;
            if (S[n] == 0)
                S[n] = 1;
            else
                S[n] = 0;
        } else if (cmd == "all") {
            for (int i = 1; i <= 20; i++) {
                S[i] = 1;
            }
        } else if (cmd == "empty") {
            for (int i = 1; i <= 20; i++) {
                S[i] = 0;
            }
        }
    }
}