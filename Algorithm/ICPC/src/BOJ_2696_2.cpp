#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long, long>;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        priority_queue<int> front;
        priority_queue<int, vector<int>, greater<int>> back;
        vector<int> ret;
        for (int i = 0; i < n; i++) {
            int input;
            cin >> input;
            if (front.size() < back.size())
                front.push(input);
            else
                back.push(input);

            if (!front.empty() && front.top() > back.top()) {
                int f = front.top();
                int b = back.top();
                front.pop();
                back.pop();
                front.push(b);
                back.push(f);
            }

            if (i % 2 == 0) ret.push_back(back.top());
        }

        // 결과 출력
        cout << ret.size() << '\n';
        for (int i = 0; i < ret.size(); i++) {
            cout << ret[i];
            if ((i + 1) % 10 == 0 && i != ret.size() - 1)
                cout << '\n';
            else
                cout << " ";
        }
        cout << '\n';
    }
}