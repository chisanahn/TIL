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
    int x;
    int y;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> R(n);
    vector<int> C(n);
    for (int i=0; i<n; i++) {
        int input;
        cin >> input;
        R[i] = input/2;
    }
    for (int i=0; i<n; i++) {
        int input;
        cin >> input;
        C[i] = input/2;
    }

    map<cor, int> groups;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            groups[{i, j}] = 
        }
    }


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