#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

ll modsum(ll a, ll b)
{
    return (a + b) % MOD;
}

ll modmul(ll a, ll b)
{
    return (a * b) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> p_count(2501, 0);

    p_count[0] = 1;
    p_count[1] = 1;
    for (int i = 2; i <= 2500; i++)
    {
        for (int j = 0; j < i; j++)
        {
            p_count[i] = modsum(p_count[i], modmul(p_count[j], p_count[i-j-1]));
        }
    }

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        if (n % 2 == 1)
            cout << "0\n";
        else
            cout << p_count[n / 2] << '\n';
    }
}