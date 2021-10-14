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

int fee[1000][1000];

const int max_fee = 100000;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fee[i][j] = max_fee * 1000;
        }
    }
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        fee[a][b] = min(fee[a][b], c);
    }

    int start, end;
    cin >> start >> end;
    start--;
    end--;
    vector<int> visited(n, 0);
    int cur = start;
    while (1) {
        if(cur == end) {
            cout << fee[start][end] << '\n';
            return 0;
        }
        visited[cur] = 1;
        // 경로 업데이트
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                fee[start][i] = min(fee[start][i], fee[start][cur] + fee[cur][i]);
            }
        }
        // 젤 작은 경로 선택
        int min = max_fee * 1000;
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                if(fee[start][i] < min) {
                    min = fee[start][i];
                    cur = i;
                }
            }
        }
    }
}