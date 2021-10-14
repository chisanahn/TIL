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

    int a, b;
    cin >> a >> b;
    set<int> A;
    for(int i=0; i<a; i++) {
        int input;
        cin >> input;
        A.insert(input);
    }
    set<int> B;
    for(int i=0; i<b; i++) {
        int input;
        cin >> input;
        B.insert(input);
    }

    int count = 0;
    int index = 0;
    for (auto& _a : A) {
        if (B.find(_a) != B.end()) count++;
    }

    cout << a + b - count * 2 << '\n';
}