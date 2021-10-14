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

int arr[1000000] = {0,};
int arr2[1000000] = {0,};

int func(int n) {
    if (arr[n] != 0 || n == 1)
        return arr[n];
    else {
        int ret = func(n - 1);
        int index = n - 1;
        if (n % 3 == 0 && n >= 3) {
            if(ret > func(n/3)) {
                ret = func(n/3);
                index = n/3;
            }
        }
        if (n % 2 == 0 && n >= 2) {
            if(ret > func(n/2)) {
                ret = func(n/2);
                index = n/2;
            }
        }
        arr[n] = ret + 1;
        arr2[n] = index;
        return arr[n];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    cout << func(n) << '\n';
    while(n!=1) {
        cout << n << " ";
        n = arr2[n];
    }
    cout << "1\n";
}