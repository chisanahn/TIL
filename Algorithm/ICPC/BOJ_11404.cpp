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

const int max_fee = 100000;

int fee[100][100];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fee[i][j] = max_fee * 100 + 1;
        }
    }
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        fee[a - 1][b - 1] = min(fee[a - 1][b - 1], c);
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    fee[i][j] = min(fee[i][j], fee[i][k] + fee[k][j]);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 한번에 가는 버스가 없는 경우 최소 비용이 100000보다 클 수 있다.
            if (fee[i][j] > max_fee * 100)
                cout << "0 ";
            else
                cout << fee[i][j] << " ";
        }
        cout << '\n';
    }
}