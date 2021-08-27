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
        vector<int> arr;
        vector<int> ret;
        for (int i = 0; i < n; i++) {
            int input;
            cin >> input;
            arr.push_back(input);
            if (i % 2 == 0) {
                sort(arr.begin(), arr.end());
                ret.push_back(arr[i / 2]);
            }
        }
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