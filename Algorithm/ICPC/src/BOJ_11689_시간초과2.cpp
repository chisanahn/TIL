#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a%b);
}

ll EulerPhi(ll n) {
    ll count = 0;
    for(ll i=1; i<n; i++) {
        if(gcd(n, i) == 1) count++;
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    cout << EulerPhi(n) << '\n';
}