#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long, long>;

int ground_check(map<int, int>& ground) {
    int count = 0;
    int ret;
    for(auto& g : ground) {
        if(g.second > 0) {
            count++;
        }
        ret = g.first;
    }
    if(count == 1) return ret;
    else return 0;
}

// 높이가 가장 높은 블록, 낮은 블록 기준으로 한다.
// 높이가 낮은 블록이 높은 블록의 2배보다 많을때 1층을 줄인다.
// if(block[low] <= block[high*2] || user_block >= low)
//     1층 추가;
//     low+1;
// else
//     1층 제거;
//     high-1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    map<int, int> ground;
    int n, m, block;
    cin >> n >> m >> block;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int height;
            cin >> height;
            ground[height] += 1;
        }
    }

    int min = 256, max = 0;
    for(auto& g : ground) {
        if(min > g.first) min = g.first;
        if(max < g.first) max = g.first;
    }

    int time = 0;
    while(min < max) {
        if(ground[min] <= ground[max]*2 && block >= ground[min]) {
            block -= ground[min];
            time += ground[min];
            ground[min+1] += ground[min];
            min++;
        }
        else {
            block += ground[max];
            time += ground[max]*2;
            ground[max-1] += ground[max];
            max--;
        }
    }
    cout << time << " " << min << '\n';
}

