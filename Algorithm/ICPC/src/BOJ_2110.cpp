#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

bool dist_ok(vector<ll> &house, int wifi, int mid)
{
    int dist = 0, count = 1;
    for (int i = 0; i < house.size() - 1; i++)
    {
        dist += house[i + 1] - house[i];
        if (dist >= mid)
        {
            dist = 0;
            count++;
        }
    }
    if (count < wifi)
        return false;
    else
        return true;
}

ll max_dist(vector<ll> &house, int wifi)
{
    int min = 1, max = house.back();
    int mid;
    while (max - min > 5)
    {
        mid = min + (max - min + 1) / 2;

        if (dist_ok(house, wifi, mid))
            min = mid;
        else
            max = mid - 1;
    }
    int ret;
    for (int i = min; i <= max; i++)
    {
        if (dist_ok(house, wifi, i))
            ret = i;
        else
            break;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, c;
    cin >> n >> c;
    vector<ll> house(n);
    for (auto &h : house)
        cin >> h;
    sort(house.begin(), house.end());
    cout << max_dist(house, c);
}