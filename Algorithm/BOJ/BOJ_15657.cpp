#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void f(vector<int>& arr, int m, vector<int>& ret) {
    if (m == 0) {
        for (auto& r : ret) cout << arr[r] << " ";
        cout << '\n';
        return;
    }

    int i;
    if (ret.empty()) i = 0;
    else i = ret.back();

    for (; i<arr.size(); i++) {
        ret.push_back(i);
        f(arr, m - 1, ret);
        ret.pop_back();
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (auto& a : arr) cin >> a;
    sort(arr.begin(), arr.end());

    vector<int> ret;
    f(arr, m, ret);
}