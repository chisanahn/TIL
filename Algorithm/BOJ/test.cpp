#include <iostream>
#include <vector> 

using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;


    ll ret = 1;
    for(ll i=n-m+1; i<=n; i++) {
        ret *= i;
    }
    for(ll i=1; i<=m; i++) {
        ret /= i;
    }

    cout << ret << '\n';
}