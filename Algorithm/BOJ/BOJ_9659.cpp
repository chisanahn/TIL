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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    switch (n % 4) {
        case 0:
            cout << "CY\n";
            break;
        case 1:
            cout << "SK\n";
            break;
        case 2:
            cout << "CY\n";
            break;
        case 3:
            cout << "SK\n";
            break;
        default:
            break;
    }
}