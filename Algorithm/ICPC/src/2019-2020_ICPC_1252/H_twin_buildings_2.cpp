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

struct land {
    ll L;
    ll W;
};

bool comp(land a, land b) {
    return a.L * a.W > b.L * b.W;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    long double ret = 0;
    vector<land> lands;
    ll l, w;
    for (int i = 0; i < n; i++) {
        cin >> l >> w;
        lands.push_back({l, w});
        // 한 땅에 세우는 경우
        ret = max(ret, (long double)(l * w) / 2);
    }
    // 두 땅에 세우는 경우
    sort(lands.begin(), lands.end(), comp);
    // 방향이 같은 경우
    l = min(lands[0].L, lands[1].L);
    w = min(lands[0].W, lands[1].W);
    ret = max(ret, (long double)l * w);
    // 방향이 반대인 경우
    l = min(lands[0].L, lands[1].W);
    w = min(lands[0].W, lands[1].L);
    ret = max(ret, (long double)l * w);

    cout << fixed;
    cout.precision(1);
    cout << ret << '\n';
}