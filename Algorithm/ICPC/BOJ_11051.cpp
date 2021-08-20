#include <algorithm>
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

const int MOD = 10007;

int arr[1001][1001] = {0, };

int func(int arr[1001][1001], int n, int k) {
    if(arr[n][k] != 0) return arr[n][k];
    arr[n][k] = (func(arr, n - 1, k - 1) % MOD + func(arr, n - 1, k)) % MOD;
    return arr[n][k];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    arr[0][0] = 1;
    for(int i=1; i<=n; i++) {
        arr[i][0] = 1;
        arr[i][i] = 1;
    }

    cout << func(arr, n, k) << '\n';
}