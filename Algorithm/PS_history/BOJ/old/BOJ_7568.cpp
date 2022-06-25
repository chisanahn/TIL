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

struct human {
    int height;
    int weight;
};

// 입력의 크기가 최대 50이라 O(n^2)으로 풀어도 될 것 같다.

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<human> people(n);
    for (auto& p : people) cin >> p.weight >> p.height;
    for (auto& p : people) {
        int count = 1;
        for (auto& p2 : people) {
            if (p.height < p2.height && p.weight < p2.weight) count++;
        }
        cout << count << " ";
    }
    cout << '\n';
}