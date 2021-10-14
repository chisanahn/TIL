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

    int n, m;
    cin >> n >> m;
    vector<string> dict;
    map<string, int> dict2;
    for(int i=0; i<n; i++) {
        string name;
        cin >> name;
        dict.push_back(name);
        dict2[name] = i;
    }
    while (m--) {
        string input;
        cin >> input;
        if (input[0] >= '0' && input[0] <= '9') {
            cout << dict[stoi(input) - 1] << '\n';
        } else {
            cout << dict2[input] + 1 << '\n';
        }
    }
}