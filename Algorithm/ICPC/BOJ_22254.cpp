#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;

bool check(vector<ll> &present, int num, ll x)
{
    priority_queue<ll, vector<ll>, greater<ll>> lines;
    int i;
    for (i = 0; i < num; i++)
    {
        lines.push(present[i]);
    }
    for (; i < present.size(); i++)
    {
        ll lines_top = lines.top();
        lines.pop();
        if(lines_top + present[i] > x) return false;
        lines.push(lines_top + present[i]);
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    ll x;
    cin >> n >> x;
    vector<ll> present(n);
    for (auto &p : present)
        cin >> p;

    int min = 1, max = n;
    int mid;
    while (max - min > 3)
    {
        mid = (min + max) / 2;
        if (check(present, mid, x))
            max = mid;
        else
            min = mid + 1;
    }
    int ret;
    for (int i = min; i <= max; i++)
    {
        if (check(present, i, x))
        {
            ret = i;
            break;
        }
    }
    cout << ret << '\n';
}
