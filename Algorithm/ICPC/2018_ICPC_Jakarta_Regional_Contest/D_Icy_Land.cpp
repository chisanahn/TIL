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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int R, C;
    cin >> R >> C;

    vector<vector<char>> land(R, vector<char>(C));
    for (auto& r : land) {
        for (auto& rc : r) {
            cin >> rc;
        }
    }

    // 안쪽부분 얼음이 몇개인지 체크
    int ret = 0;
    if (R > 2 && C > 2) {
        for (int i = 1; i < R - 1; i++) {
            for (int j = 1; j < C - 1; j++) {
                if (land[i][j] == '.') {
                    ret++;
                }
            }
        }
        // 테두리 부분에 얼음이 하나 있는지 체크. 없으면 +1
        bool empty = true;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                // 코너가 아닌 바깥쪽 부분
                if ((i == 0 || i == R - 1 || j == 0 || j == C - 1) && !(i == 0 || i == R - 1) && (j == 0 || j == C - 1)) {
                    if (land[i][j] == '#') {
                        empty = false;
                    }
                }
            }
        }
        if (empty) ret++;
    } else {
        if (R <= 2) {
            for (int i = 1; i < C - 1; i++) {
                bool empty = true;
                for (int j = 0; j < R; j++) {
                    if (land[j][i] == '#') {
                        empty = false;
                    }
                }
                if (empty) {
                    ret++;
                }
            }
        } else {
            for (int i = 1; i < R - 1; i++) {
                bool empty = true;
                for (int j = 0; j < C; j++) {
                    if (land[i][j] == '#') {
                        empty = false;
                    }
                }
                if (empty) {
                    ret++;
                }
            }
        }
    }

    cout << ret << '\n';
}