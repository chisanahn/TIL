#include <iostream>
#include <vector>
#include <string>

using namespace std;

int count(vector<string>& board, int x, int y) {
    int count = 0;
    char arr[] = {'B', 'W'};

    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            if(board[i+x][j+y] == arr[(i+j)%2])
                count++;
        }
    }
    
    int ret = count;
    count = 0;

    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            if(board[i+x][j+y] != arr[(i+j)%2])
                count++;
        }
    }

    if(count < ret) ret = count;
    return ret;
}

int main() {
    ios_base::sync_with_stdio;
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    vector<string> board(n);
    for(auto& b:board) cin >> b;

    int min = n*m;
    for(int i=0; i<=n-8; i++) {
        for(int j=0; j<=m-8; j++) {
            int ret = count(board, i, j);
            if(ret < min) min = ret;
        }
    }
    cout << min << '\n';
}