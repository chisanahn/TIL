#include <iostream>

using namespace std;

const int INF = 987654321;

int G[100][100];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            G[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        G[u][v] = min(G[u][v], w);
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j)
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (G[i][j] == INF)
                cout << "0";
            else
                cout << G[i][j];
            if (j == n - 1)
                cout << '\n';
            else
                cout << ' ';
        }
    }
}