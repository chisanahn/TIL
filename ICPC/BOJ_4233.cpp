#include <iostream>

using namespace std;

using ll = long long;

ll modmul(ll a, ll b, ll mod) {
    return ((a%mod)*(b%mod))%mod;
}

ll modpow(ll x, ll y, ll mod) {
    if(y==0) return 1;
    ll ret = modpow(x, y/2, mod);
    ret = modmul(ret, ret, mod);
    if(y%2==1) ret = modmul(ret, x, mod);
    return ret;
}

bool prime(ll n) {
    for(ll i=2; i*i<=n; i++)
        if(n%i==0) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll p, a;
    while(1) {
        cin >> p >> a;
        if(p==0 && a ==0) return 0;
        
        if(prime(p)) cout << "no\n";
        else if(modpow(a, p, p) == a%p) cout << "yes\n";
        else cout << "no\n";
    }
}