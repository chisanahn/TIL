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

    int a, b;
    cin >> a >> b;
    vector<int> A(a);
    for (auto& _a : A) cin >> _a;
    vector<int> B(b);
    for (auto& _b : B) cin >> _b;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int count = 0;
    int index = 0;
    for (auto& _a : A) {
        while (index < B.size() && _a >= B[index]) {
            if (_a == B[index++]) {
                count++;
                break;
            }
        }
    }

    cout << a + b - count * 2 << '\n';
}