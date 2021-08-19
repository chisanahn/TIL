#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> arr(n+1);
    arr[0] = 0;
    int sum = 0;
    for(int i=1; i<=n; i++) {
        int num;
        cin >> num;
        sum += num;
        arr[i] = sum;
    }
    
    while(m--) {
        int i, j;
        cin >> i >> j;
        cout << arr[j] - arr[i-1] << '\n';
    }
}