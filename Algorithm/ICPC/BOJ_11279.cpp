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

    priority_queue<int> Q;

    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        if (x == 0) {
            if (Q.empty())
                cout << "0\n";
            else {
                cout << Q.top() << '\n';
                Q.pop();
            }
        } else {
            Q.push(x);
        }
    }
}