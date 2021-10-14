#include <iostream>

using namespace std;
using ll = long long;

ll ret[101][101][101];
int check[101][101][101] = {0, };

ll w(int a, int b, int c) {
    if(check[a+50][b+50][c+50] == 0) {
        if(a<=0 || b<=0 || c<=0) {
            ret[a+50][b+50][c+50] = 1;
        }
        else if(a>20 || b>20 || c>20) {
            ret[a+50][b+50][c+50] = w(20, 20, 20);
        }
        else if(a<b && b<c) {
            ret[a+50][b+50][c+50] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
        }
        else {
            ret[a+50][b+50][c+50] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
        }
        check[a+50][b+50][c+50] = 1;
    }
    return ret[a+50][b+50][c+50];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int a, b, c;
    while(1) {
        cin >> a >> b >> c;
        if(a==-1 && b==-1 && c==-1) break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a,b,c) << '\n';
    }
}