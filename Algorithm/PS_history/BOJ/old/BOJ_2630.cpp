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

// 종이
int arr[128][128];

int paper[2];

// x1<x2, y1<y2
int cal(int x1, int y1, int x2, int y2) {
    // base case: 한 칸인 경우
    if (x1 == x2 && y1 == y2) {
        return arr[x1][y1];
    }

    int c1, c2, c3, c4;
    // 4개로 나눠서 체크
    c1 = cal(x1, y1, (x1 + x2) / 2, (y1 + y2) / 2);
    c2 = cal((x1 + x2) / 2 + 1, y1, x2, (y1 + y2) / 2);
    c3 = cal(x1, (y1 + y2) / 2 + 1, (x1 + x2) / 2, y2);
    c4 = cal((x1 + x2) / 2 + 1, (y1 + y2) / 2 + 1, x2, y2);

    // 모두 같은 경우
    if (c1 == c2 && c1 == c3 && c1 == c4) return c1;
    // 다른 경우
    if (c1 != -1) {
        paper[c1]++;
    }
    if (c2 != -1) {
        paper[c2]++;
    }
    if (c3 != -1) {
        paper[c3]++;
    }
    if (c4 != -1) {
        paper[c4]++;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    // 종이 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int input;
            cin >> input;
            arr[i][j] = input;
        }
    }

    // 종이 개수 계산
    paper[0] = paper[1] = 0;
    int ret = cal(0, 0, n - 1, n - 1);
    if (ret == 0)
        paper[0]++;
    else if (ret == 1)
        paper[1]++;

    cout << paper[0] << '\n';
    cout << paper[1] << '\n';
}