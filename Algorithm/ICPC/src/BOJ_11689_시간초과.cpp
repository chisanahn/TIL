#include <iostream>
#include <map>

using namespace std;

using ll = long long;

ll pow(ll a, ll b)
{
    ll ret = 1;
    for (ll i = 0; i < b; i++)
        ret *= a;
    return ret;
}

// p가 소수일떄 p^k와 서로소인 수
ll gcd_prime(ll p, ll k)
{
    return pow(p, k) - pow(p, k - 1);
}

ll gcd(ll n)
{
    // 소인수분해
    map<ll, ll> prime;
    for(ll i=2; n>1; i++) {
        while(n%i==0) {
            prime[i] += 1;
            n/=i;
        }
    }

    // 오일러 파이 함수 계산 - 곱셈적 함수임을 이용
    ll ret = 1;
    for (auto &p : prime)
        ret *= gcd_prime(p.first, p.second);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll n;
    cin >> n;
    cout << gcd(n) << '\n';
}