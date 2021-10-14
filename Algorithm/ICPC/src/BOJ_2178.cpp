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

struct cor {
    int x;
    int y;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> maze(n);
    for (auto& a : maze) {
        cin >> a;
    }

    vector<int> px = {0, -1, 1, 0};
    vector<int> py = {-1, 0, 0, 1};

    // maze[i][j]에서 이동할 수 있는 칸 저장.
    vector<vector<cor>> graph(n * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // if(maze[i][j] == '1')을 넣으면 수행시간이 개선될거같다. -> 실제로 넣어보니 별로 차이가 안나는것같다. 4ms로 똑같았다.
            for (int k = 0; k < 4; k++) {
                int x = i + px[k], y = j + py[k];
                if (x >= 0 && y >= 0 && x < n && y < m) {
                    if (maze[x][y] == '1')
                        graph[i * m + j].push_back({x, y});
                }
            }
        }
    }

    // bfs로 이동할 수 있는지 판단.
    vector<int> visited(n * m, 0);
    vector<int> count(n * m, 0);
    queue<cor> Q;
    Q.push({0, 0});
    visited[0] = 1;
    count[0] = 1;
    while (!Q.empty()) {
        cor cur = Q.front();
        Q.pop();
        vector<cor>& adj = graph[cur.x * m + cur.y];
        for (auto& a : adj) {
            if(a.x == n-1 && a.y == m-1) {
                cout << count[cur.x * m + cur.y] + 1 << '\n';
                return 0;
            }
            if (visited[a.x * m + a.y] == 0) {
                visited[a.x * m + a.y] = 1;
                count[a.x * m + a.y] = count[cur.x * m + cur.y] + 1;
                Q.push(a);
            }
        }
    }
}