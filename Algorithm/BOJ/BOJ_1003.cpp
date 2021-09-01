#include <iostream>
#include <vector>

using namespace std;

vector<int> zero(41, -1);
vector<int> one(41, -1);

void fibo(int n) {
    if(zero[n] != -1 && one[n] != -1) return;
    fibo(n-1);
    fibo(n-2);
    zero[n] = zero[n-1] + zero[n-2];
    one[n] = one[n-1] + one[n-2];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    zero[0] = 1;
    zero[1] = 0;
    one[0] = 0;
    one[1] = 1;
    while(T--) {
        int n;
        cin >> n;
        fibo(n);
        cout << zero[n] << " " << one[n] << '\n';
    }
}