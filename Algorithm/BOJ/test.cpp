#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int m, n, k;
        cin >> m >> n >> k;
        vector<vector<int>> ground(n, vector<int>(m, 0));
        while (k--) {
            int x, y;
            cin >> x >> y;
            ground[y][x] = 1;
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (ground[i][j] == 1) {
                    bool check = true;
                    if (i > 0 && ground[i - 1][j] == 1) {
                        check = false;
                    }
                    if (j > 0 && ground[i][j - 1] == 1) {
                        check = false;
                    }
                    if (check) count++;
                }
            }
        }

        cout << count << '\n';
    }
}