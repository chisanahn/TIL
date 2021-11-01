#include <iostream>
#include <queue>
#include <string>

using namespace std;
using pii = pair<int, int>;

int n, m;
int ret = -1;

int map[1001][1001];
int len[1001][1001][2];  // 방문여부 및 경로 길이

int d[2][4] = {{-1, 0, 1, 0}, {0, -1, 0, 1}};

void BFS() {
    queue<pair<pii, int>> Q;
    Q.push({{0, 0}, map[0][0]});
    len[0][0][map[0][0]] = 1;
    while (!Q.empty()) {
        int i = Q.front().first.first;
        int j = Q.front().first.second;
        int w = Q.front().second;
        if (i == n - 1 && j == m - 1) {
            ret = len[i][j][w];
            break;
        }
        Q.pop();
        for (int k = 0; k < 4; k++) {
            int y = i + d[0][k];
            int x = j + d[1][k];
            // 범위를 벗어나는 경우
            if (y < 0 || x < 0 || y > n - 1 || x > m - 1)
                continue;
            // 벽이고 아직 벽을 뚫지 않은 경우
            else if (map[y][x] == 1 && w == 0) {
                Q.push({{y, x}, 1});
                len[y][x][1] = len[i][j][w] + 1;
            }
            // 벽이 아니고 방문하지 않은 경우
            else if (map[y][x] == 0 && len[y][x][w] == 0) {
                Q.push({{y, x}, w});
                len[y][x][w] = len[i][j][w] + 1;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < m; j++) {
            map[i][j] = input[j] - '0';
            len[i][j][0] = 0;
            len[i][j][1] = 0;
        }
    }
    BFS();
    cout << ret << '\n';
}