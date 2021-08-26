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

    // arr[3] = 높이가 3인 AVL Tree 중 최소 정점개수
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    int ret = 0;
    for (int i = 2; ret <= 1000000000; i++) {
        ret = 1 + arr[i - 2] + arr[i - 1];
        arr.push_back(ret);
    }

    int T;
    cin >> T;
    while (T--) {
        int V;
        cin >> V;
        int height = 0;
        while(arr[height] <= V) {
            height++;
        }
        cout << height << '\n';
    }
}