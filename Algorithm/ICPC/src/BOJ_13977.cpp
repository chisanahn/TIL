#include <iostream>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

ll modmul(ll a, ll b)
{
    return ((a % MOD) * (b % MOD)) % MOD;
}

ll modpow(ll x, ll y)
{
    if(y==0) return 1;

    ll ret = modpow(x, y/2);
    ret = modmul(ret, ret);
    if(y%2==1) ret = modmul(ret, x);
    return ret;
}

ll modinv(ll a)
{
    return modpow(a, MOD - 2);
}

ll mod_fact[4000001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    mod_fact[0] = mod_fact[1] = 1;
    for(int i=2; i<=4000000; i++) {
        mod_fact[i] = modmul(mod_fact[i-1], i);
    }

    int T;
    cin >> T;
    while (T--)
    {
        ll n, k;
        cin >> n >> k;
        ll ret = mod_fact[n];
        ret = modmul(ret, modinv(mod_fact[n-k]));
        ret = modmul(ret, modinv(mod_fact[k]));
        cout << ret << '\n';
    }
}