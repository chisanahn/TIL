#include <iostream>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int visit[300][300];
int d[][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--) {
        int l;
        cin >> l;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < l; j++) {
                visit[i][j] = 0;
            }
        }
        pii start, end;
        cin >> start.first >> start.second;
        cin >> end.first >> end.second;
        visit[start.first][start.second] = 1;
        queue<pii> Q;
        Q.push(start);
        int ret;
        while (!Q.empty()) {
            pii cur = Q.front();
            Q.pop();
            if (cur == end) {
                ret = visit[cur.first][cur.second];
                break;
            }
            for (int k = 0; k < 8; k++) {
                int y = cur.first + d[k][0];
                int x = cur.second + d[k][1];
                if (y < 0 || x < 0 || y > l - 1 || x > l - 1) continue;
                if (visit[y][x] == 0) {
                    visit[y][x] = visit[cur.first][cur.second] + 1;

                    Q.push({y, x});
                }
            }
        }
        cout << ret - 1 << '\n';
    }
}