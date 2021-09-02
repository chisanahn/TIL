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

    int n;
    cin >> n;
    vector<pii> time(n);
    for (auto& t : time) cin >> t.first >> t.second;
    sort(time.begin(), time.end());

    vector<pii> ret;
    ret.push_back(time[0]);
    for (int i = 1; i < n; i++) {
        if(time[i].second < ret.back().second) {
            ret[ret.size()-1] = time[i];
        }
        else if(time[i].first >= ret.back().second) {
            ret.push_back(time[i]);
        }
    }

    cout << ret.size() << '\n';
}