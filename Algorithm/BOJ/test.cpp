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

    int n;
    cin >> n;
    vector<int> arr;
    vector<int> ret;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        arr.push_back(input);
        if (i == 0) {
            ret.push_back(0);
        }
        else {
            int count = 0;
            for(int j=0; j<i; j++) {
                if(input < arr[j]) ret[j]++;
                if(input > arr[j]) count++;
            }
            ret.push_back(count);
        }
    }
    for(auto& r : ret) cout << r << " ";
    cout << '\n';
}