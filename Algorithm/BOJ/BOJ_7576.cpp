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

int tomato[1000][1000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    queue<pii> Q;
    vector<int> xp = {0, 1, 0, -1};
    vector<int> yp = {-1, 0, 1, 0};

    int m, n;
    cin >> m >> n;
    int remain = m * n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int input;
            cin >> input;
            tomato[i][j] = input;
            if (input == 1) {
                Q.push({i, j});
                remain--;
            } else if (input == -1)
                remain--;
        }
    }

    int ret = 1;
    while(!Q.empty()) {
        int y = Q.front().first;
        int x = Q.front().second;
        Q.pop();
        for(int k=0; k<4; k++) {
            int y2 = y+yp[k];
            int x2 = x+xp[k];
            if(0<=y2 && y2 < n && 0<=x2 && x2<m) {
                if(tomato[y2][x2] == 0) {
                    tomato[y2][x2] = tomato[y][x] + 1;
                    Q.push({y2, x2});
                    remain--;
                    ret = max(ret, tomato[y2][x2]);
                }
            }
        }
    }
    if(remain != 0) {
        cout << "-1\n";
    }
    else cout << ret - 1 << '\n';
}