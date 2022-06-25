#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <deque>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long, long>;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> time(n);
    for(auto& t : time) cin >> t;
    sort(time.begin(), time.end());
    int ret = 0;
    for(int i=0; i<n; i++) {
        ret += time[i]*(n-i);
    }

    cout << ret << '\n';
}