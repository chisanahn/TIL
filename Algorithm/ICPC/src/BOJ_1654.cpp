#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

ll cal(const vector<ll> &lines, int length)
{
    ll count = 0;
    for (auto &l : lines)
    {
        count += l / length;
    }
    return count;
}

ll func(const vector<ll> &lines, int n)
{
    int min = 1, max = lines.back();
    int middle;
    while (max - min > 5)
    {
        middle = min + (max - min) / 2;
        if (cal(lines, middle) < n)
            max = middle - 1;
        else
            min = middle;
    }
    int ret;
    for(int i=min; i<=max; i++) {
        if(cal(lines, i) >= n) ret = i;
        else break;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll k, n;
    cin >> k >> n;

    vector<ll> lines(k);
    for (auto &l : lines)
        cin >> l;
    sort(lines.begin(), lines.end());

    cout << func(lines, n) << '\n';
}