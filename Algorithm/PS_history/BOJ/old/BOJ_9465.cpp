#include <iostream>
#include <vector>

using namespace std;

int n;
int stickers[2][100000];

int dp[100000][3];

int f(int col, int sort) {
    // base case
    if (col == n) return 0;
    if (dp[col][sort] != -1) return dp[col][sort];

    int ret = f(col + 1, 0);
    // 그 전 열에서 방문 x
    if (sort == 0) {
        ret = max(ret, stickers[0][col] + f(col + 1, 1));
        ret = max(ret, stickers[1][col] + f(col + 1, 2));
    }
    // 그 전 열에서 1번째 줄을 방문
    else if (sort == 1) {
        ret = max(ret, stickers[1][col] + f(col + 1, 2));
    }
    // 그 전 열에서 2번째 줄을 방문
    else {
        ret = max(ret, stickers[0][col] + f(col + 1, 1));
    }

    return dp[col][sort] = ret;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cin >> stickers[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                dp[i][j] = -1;
            }
        }
        cout << f(0, 0) << '\n';
    }
}