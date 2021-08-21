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

int arr[1025][1025];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int x = 1; x <= n; x++) {
        arr[x][0] = 0;
        for (int y = 1; y <= n; y++) {
            int input;
            cin >> input;
            arr[x][y] = arr[x][y - 1] + input;
        }
    }

    for (int i = 0; i < m; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int sum = 0;
        for (int x = x1; x <= x2; x++) {
            sum += arr[x][y2] - arr[x][y1-1];
        }
        cout << sum << '\n';
    }
}