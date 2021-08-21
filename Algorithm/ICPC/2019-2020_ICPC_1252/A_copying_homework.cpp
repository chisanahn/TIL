#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <deque>

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
    for(auto& a : A) cin >> a;
    for(int i=1; i<A.size(); i++) {
        cout << A[i] << " ";
    }
    cout << A[0] << '\n';
}