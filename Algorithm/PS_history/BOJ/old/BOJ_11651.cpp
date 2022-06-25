#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    map<pair<int, int>, int> cors;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        cors[{y, x}] += 1;
    }

    for(auto& c : cors) cout << c.first.second << " " << c.first.first << '\n';
}