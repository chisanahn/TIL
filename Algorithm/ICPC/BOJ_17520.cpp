#include <iostream>

using namespace std;

using ll = long long;

const ll MOD = 16769023;

// a*b%MOD
ll mod_mul(ll a, ll b) {
    return (a%MOD)*(b%MOD)%MOD;
}

// 2^k%MOD
ll mod_pow(ll k) {
    if(k==0) return 1;
    ll ret = mod_pow(k/2);
    ret = mod_mul(ret, ret);
    if(k%2 == 1) ret = mod_mul(ret, 2);
    return ret;
}

int main() {
    ll n;
    cin >> n;
    cout << mod_pow((n+1)/2) << '\n';
}