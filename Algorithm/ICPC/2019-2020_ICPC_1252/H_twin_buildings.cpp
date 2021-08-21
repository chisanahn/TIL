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
    long double ret = 0;
    vector<pll> lands;
    for(int i=0; i<n; i++) {
        ll l, w;
        cin >> l >> w;
        lands.push_back({l, w});
        // 한 땅에 세우는 경우
        ret = max(ret, (long double)(l*w)/2);
    }

    // 두 땅에 세우는 경우
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            ll l, w;
            // 방향이 같은 경우
            l = min(lands[i].first, lands[j].first);
            w = min(lands[i].second, lands[j].second);
            ret = max(ret, (long double)l*w);
            // 방향이 반대인 경우
            l = min(lands[i].first, lands[j].second);
            w = min(lands[i].second, lands[j].first);
            ret = max(ret, (long double)l*w);
        }
    }

    cout << fixed;
    cout.precision(1);
    cout << ret << '\n';
}