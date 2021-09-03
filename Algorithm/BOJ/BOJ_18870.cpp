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
    map<int, int> M;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        arr.push_back(input);
        M[input] = 1;
    }
    int index = 0;
    for(auto& m : M) {
        m.second = index++; 
    }

    for(auto& a : arr) cout << M[a] << " ";
    cout << '\n';
}