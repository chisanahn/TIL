#include <iostream>

using namespace std;
using ll = long long;

const ll r = 31;
const ll M = 1234567891;

ll modsum(ll a, ll b)
{
    return (a % M + b % M) % M;
}

ll modmul(ll a, ll b)
{
    return (a % M) * (b % M) % M;
}

ll modpow(ll x, ll y)
{
    if (y == 0)
        return 1;
    ll ret = modpow(x, y / 2);
    ret = modmul(ret, ret);
    if (y % 2 == 1)
        ret = modmul(ret, x);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int L;
    cin >> L;
    ll ret = 0;
    for (int i = 0; i < L; i++)
    {
        char s;
        cin >> s;
        ret = modsum(ret, modmul((ll)(s - 'a' + 1), modpow(r, i)));
    }
    cout << ret << '\n';
}