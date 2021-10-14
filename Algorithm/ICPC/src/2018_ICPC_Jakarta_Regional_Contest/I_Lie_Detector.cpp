#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <deque>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long, long>;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    int count = 0;
    while(T--) {
        string s;
        cin >> s;
        if(s=="LIE") count++;
    }
    if(count%2==1) cout << "LIE\n";
    else cout << "TRUTH\n";
}