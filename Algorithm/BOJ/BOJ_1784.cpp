#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long, long>;

string check(int n)
{
    vector<int> cmd(n);
    for(auto& c : cmd) cin >> c;
    stack<int> s;
    string ret;

    int num = 1;
    for (auto& c : cmd)
    {
        if (s.empty())
        {
            for (num; num <= c; num++)
            {
                s.push(num);
                ret.push_back('+'); 
            }
        }

        if (s.top() == c)
        {
            s.pop();
            ret.push_back('-');
        }
        else if (s.top() < c)
        {
            for (num; num <= c; num++)
            {
                s.push(num);
                ret.push_back('+');
            }
            s.pop();
            ret.push_back('-');
        }
        else if (s.top() > c)
        {
            return "";
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string ret = check(n);
    if (ret == "")
        cout << "NO\n";
    else
    {
        for (auto &r : ret)
            cout << r << '\n';
    }
}
