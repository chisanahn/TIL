#include <iostream>
#include <vector>

using namespace std;

// n개의 재료를 최소금액으로 구매
int buy(int n, int Sm, int Pm, int Sv, int Pv) {
    int ret = 123456789;
    for (int v = (n-1)/Sv+1; v>=0; v--) {
        int a = n-Sv*v;
        if(a<=0) ret = min(ret, Pv*v);
        else ret = min(ret, Pv*v + ((a-1)/Sm+1)*Pm);
    }
    return ret;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(6));
    for (auto& a : A) {
        for (auto& _a : a) {
            cin >> _a;
        }
    }

    int min = 0;
    int max = (m/10*99+100)/n;
    int mid;
    while (min < max) {
        mid = (min + max + 1) / 2;
        int money = m;
        for (int i = 0; i < n; i++) {
            vector<int>& a = A[i];
            if (mid * a[0] > a[1]) {
                money -= buy(mid * a[0] - a[1], a[2], a[3], a[4], a[5]);
            }
        }
        if (money >= 0)
            min = mid;
        else
            max = mid - 1;
    }
    cout << max << '\n';
}