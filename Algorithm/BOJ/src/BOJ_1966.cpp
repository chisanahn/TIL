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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        queue<pii> q;
        vector<int> priorities(10, 0);
        int m_p;

        for (int i = 0; i < n; i++)
        {
            int input;
            cin >> input;
            q.push({input, i});
            priorities[input]++;
            if(i==m) m_p = input;
        }

        int ret = 1;
        for(int i=9; i>=m_p; i--) {
            while(priorities[i] > 0) {
                if(q.front().first != i) {
                    pii temp = q.front();
                    q.pop();
                    q.push(temp);
                    continue;
                }
                if(q.front().second == m) break;
                q.pop();
                priorities[i]--;
                ret++;
            }
        }
        cout << ret << '\n';
    }
}
