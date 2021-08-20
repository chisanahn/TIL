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

    int max = A[0];
    int sum = 0;
    for (auto& a : A) {
        sum += a;
        if (sum < a) {
            sum = a;
        }
        if (sum > max) max = sum;
    }

    cout << max << '\n';
}