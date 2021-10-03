#include <iostream>
#include <queue>

using namespace std;

int box[100][100][100];

queue<pair<int, pair<int, int>>> Q;

// z, y, x
int d[3][6] = {{0, 0, 0, 0, 1, -1}, {0, 1, -1, 0, 0, 0}, {-1, 0, 0, 1, 0, 0}};

int main() {
    int m, n, h;
    cin >> m >> n >> h;

    int tomato = 0;  // 익지 않은 토마토 개수
    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> box[k][i][j];
                if (box[k][i][j] == 1) {
                    Q.push({k, {i, j}});
                } else if (box[k][i][j] == 0) {
                    tomato++;
                }
            }
        }
    }
    int cnt = 0;
    int day = 0;
    while (!Q.empty()) {
        pair<int, pair<int, int>> cur = Q.front();
        Q.pop();

        for (int k = 0; k < 6; k++) {
            int z = cur.first + d[0][k];
            int y = cur.second.first + d[1][k];
            int x = cur.second.second + d[2][k];
            if (z < 0 || y < 0 || x < 0 || z > h - 1 || y > n - 1 || x > m - 1) continue;
            if (box[z][y][x] == 0) {
                box[z][y][x] = box[cur.first][cur.second.first][cur.second.second] + 1;
                day = box[z][y][x] - 1;
                cnt++;
                Q.push({z, {y, x}});
            }
        }
    }
    if(cnt != tomato) cout << "-1\n";
    else cout << day << '\n';
}