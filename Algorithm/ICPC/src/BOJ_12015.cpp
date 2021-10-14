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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> A(n);
    for (auto& a : A) cin >> a;

    vector<int> C;
    C.push_back(A[0]);
    for (int i = 1; i < n; i++) {
        // 이분 탐색으로 수정하기.
        if (C.back() < A[i]) {
            C.push_back(A[i]);
        }
        else {
            int min = 0, max = C.size() - 1;
            int mid;
            while (max - min > 3) {
                mid = (min + max) / 2;
                if (A[i] <= C[mid]) {
                    max = mid;
                }
                else min = mid + 1;
            }
            for (int j = min; j <= max; j++) {
                if (A[i] <= C[j]) {
                    C[j] = A[i];
                    break;
                }
            }
        }
    }

    cout << C.size() << '\n';
}