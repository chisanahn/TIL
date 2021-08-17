#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n+1);
    arr[0] = 0;
    int sum = 0;
    for(int i=1; i<=n; i++) {
        int num;
        cin >> num;
        sum += num;
        arr[i] = sum;
    }

    int max = -1000;
    for(int i=1; i<=n; i++) {
        for(int j=0; j<i; j++) {
            int ret = arr[i] - arr[j];
            if(ret > max) max = ret;
        }
    }
    // 시간 복잡도 어림짐작.
    // O(1+2+...n) = O(n^2)
    // 입력 사이즈가 최대 10^5
    // 100억. 흠.. 시간초과 날거같다. 정답!

    cout << max << '\n';
}