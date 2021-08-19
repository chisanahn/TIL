#include <algorithm>
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

    int n;
    cin >> n;
    // vector<pair<string, pair<string, int>>> files;
    map<string, pair<int, string>> files;

    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        for (int i = 0; i < input.size(); i++) {
            for (int j = 1; j <= input.size() - i; j++) {
                string substr = input.substr(i, j);
                if (files.find(substr) != files.end()) {
                    if (files[substr].second != input) {
                        files[substr].first += 1;
                        files[substr].second = input;
                    }
                } else
                    files[substr] = {1, input};
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        string input;
        cin >> input;
        int count = 0;
        string ret = "-";
        if (files.find(input) != files.end()) {
            count = files[input].first;
            ret = files[input].second;
        }
        cout << count << " " << ret << '\n';
    }
}
