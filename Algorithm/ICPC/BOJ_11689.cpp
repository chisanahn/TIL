#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

ll EulerPhiFunc(ll n)
{
    // 소인수분해
    vector<ll> prime;
    ll div = n;
    for(ll i=2; i*i<=n && div > 1; i++) {
        int count = 0;
        while(div%i==0) {
            if(count==0) prime.push_back(i);
            count++;
            div/=i;
        }
    }
    if(div > 1) prime.push_back(div);

        // 오일러 파이 함수 계산
        for (auto &p : prime)
        {
            n /= p;
            n *= (p - 1);
        }

    return n;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    cout << EulerPhiFunc(n) << '\n';
}