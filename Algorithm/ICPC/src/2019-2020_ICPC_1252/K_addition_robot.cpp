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

const ll MOD = 1000000007;

void toggle(string& s, int L, int R) {
    for(int i=L-1; i<R; i++) {
        if(s[i]=='A') s[i]='B';
        else s[i]='A';
    }
}

void f(string& s, int L, int R, ll A, ll B) {
    for(int i=L-1; i<R; i++) {
        if(s[i]=='A') A = (A+B)%MOD;
        else B=(A+B)%MOD;
    }
    cout << A << " " << B << '\n';
}

// A += (B)*A나온개수

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    while(q--) {
        int cmd;
        cin >> cmd;
        if(cmd == 1) {
            int L, R;
            cin >> L >> R;
            toggle(s, L, R);
        }
        else if(cmd == 2) {
            int L, R;
            ll A, B;
            cin >> L >> R >> A >> B;
            f(s, L, R, A, B);
        }
    }
}