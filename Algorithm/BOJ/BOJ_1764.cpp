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

    int n, m;
    cin >> n >> m;
    map<string, int> M;
    while (n--) {
        string name;
        cin >> name;
        M[name] += 1;
    }
    vector<string> ret;
    while (m--) {
        string name;
        cin >> name;
        if (M[name] == 1) ret.push_back(name);
    }
    sort(ret.begin(), ret.end());

    cout << ret.size() << '\n';
    for (auto& r : ret) cout << r << '\n';
}