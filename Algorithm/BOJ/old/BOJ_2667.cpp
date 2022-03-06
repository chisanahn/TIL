#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using pii = pair<int, int>;

int map[25][25];
int n;

int d[2][4] = {{-1, 0, 1, 0}, {0, 1, 0, -1}};

int DFS(int start_i, int start_j) {
    map[start_i][start_j] = 0;
    stack<pii> S;
    S.push({start_i, start_j});
    int ret = 1;
    while(!S.empty()) {
        int i = S.top().first;
        int j = S.top().second;
        S.pop();

        for (int k = 0; k < 4; k++) {
        int y = i + d[0][k];
        int x = j + d[1][k];
        if (y < 0 || x < 0 || y > n - 1 || x > n - 1) continue;
        if (map[y][x] == 1) {
            ret++;
            map[y][x] = 0;
            S.push({i, j});
            S.push({y, x});
        }
    }
    }
    return ret;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < n; j++) {
            map[i][j] = input[j] - '0';
        }
    }

    vector<int> R;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 1) {
                R.push_back(DFS(i, j));
            }
        }
    }
    sort(R.begin(), R.end());
    cout << R.size() << '\n';
    for (auto& r : R) cout << r << '\n';
}