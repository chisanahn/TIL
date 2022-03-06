#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

bool check(vector<ll> &trees, ll H, ll M)
{
    ll count = 0;
    for (auto &t : trees)
    {
        if (t > H)
        {
            count += (t - H);
        }
    }
    if (count >= M)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N, M;
    cin >> N >> M;
    vector<ll> trees;
    int min = 0, max = 0;
    for (ll i = 0; i < N; i++)
    {
        ll height;
        cin >> height;
        if (height > max)
            max = height;
        trees.push_back(height);
    }

    ll mid;
    while (max - min > 3)
    {
        mid = min + (max - min) / 2;
        if (check(trees, mid, M)) min = mid;
        else max = mid - 1;
    }
    ll ret;
    for(ll i=min; i<=max; i++) {
        if(check(trees, i, M)) ret = i;
        else break;
    }
    cout << ret << '\n';
}