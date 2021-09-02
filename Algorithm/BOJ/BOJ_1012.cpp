#include <iostream>
#include <vector>

using namespace std;

int ground[51][51];
int visited[51][51];

void bfs(int i, int j) {
    int yp[4] = {0, -1, 0, 1};
    int xp[4] = {-1, 0, 1, 0};

    for (int k = 0; k < 4; k++) {
        int y = i + yp[k];
        int x = j + xp[k];
        if (ground[y][x] == 1 && visited[y][x] == 0) {
            visited[y][x] = 1;
            bfs(y, x);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int m, n, k;
        cin >> m >> n >> k;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ground[i][j] = 0;
                visited[i][j] = 0;
            }
        }

        while (k--) {
            int x, y;
            cin >> x >> y;
            ground[y][x] = 1;
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (ground[i][j] == 1 && visited[i][j] == 0) {
                    count++;
                    bfs(i, j);
                }
            }
        }

        cout << count << '\n';
    }
}