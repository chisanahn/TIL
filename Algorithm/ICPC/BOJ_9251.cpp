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

int arr[1001][1001];

int lcs(string& a, string& b, int a_i, int b_i) {
    if (arr[a_i][b_i] != -1) return arr[a_i][b_i];

    if (a_i >= a.size() || b_i >= b.size()) {
        return 0;
    }

    int ret = 0;
    if (a[a_i] == b[b_i]) ret = lcs(a, b, a_i + 1, b_i + 1) + 1;
    ret = max(ret, lcs(a, b, a_i + 1, b_i));
    ret = max(ret, lcs(a, b, a_i, b_i + 1));
    arr[a_i][b_i] = ret;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;

    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            arr[i][j] = -1;
        }
    }

    cout << lcs(a, b, 0, 0) << '\n';
}