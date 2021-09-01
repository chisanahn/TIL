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

const ll MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<ll> fact;
    fact.push_back(0);
    fact.push_back(1);

    int index = 2;
    while (index < 1002) {
        fact.push_back((fact[index - 1] + fact[index - 2]) % MOD);
        index++;
    }
    cout << fact.back() << '\n';
}