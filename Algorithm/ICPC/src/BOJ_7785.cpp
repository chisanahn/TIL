#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
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
    set<string, greater<string>> log;
    while (n--) {
        string name, status;
        cin >> name >> status;
        if (status == "enter") {
            log.insert(name);
        } else if (status == "leave") {
            log.erase(name);
        }
    }
    
    for(auto& l : log) cout << l << '\n';
}