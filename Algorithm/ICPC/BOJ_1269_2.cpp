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
    map<int, int> M;
    for (int i = 0; i < a + b; i++) {
        int item;
        cin >> item;
        M[item] += 1;
    }
    int count = 0;
    for (auto& m : M) {
        if (m.second == 1)
            count++;
    }
    cout << count << '\n';
}