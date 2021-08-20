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

bool check(int num) {
    string str = to_string(num);
    int count = 0;
    for (auto& s : str) {
        if (s == '6')
            count++;
        else
            count = 0;
        if (count == 3) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int arr[10000];
    int count = 0;
    for (int num = 666; count < 10000; num++) {
        // 666이 연속으로 나오는지 확인
        if (check(num)) {
            arr[count] = num;
            count++;
        }
    }

    int n;
    cin >> n;
    cout << arr[n - 1] << '\n';
}