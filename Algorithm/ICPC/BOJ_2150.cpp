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

stack<int> S;
vector<int> order;
vector<int> out;
int order_count;

vector<vector<int>> E;
vector<vector<int>> SCC;

int tarjan(int cur) {
    order[cur] = ++order_count;
    S.push(cur);

    int order_min = order[cur];
    for (auto next : E[cur]) {
        if (order[next] == 0)
            order_min = min(order_min, tarjan(next));
        else if(out[next] == 0)
        order_min = min(order_min, order[next]);
        
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}