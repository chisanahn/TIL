#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int n;
ll w, coin;

int main() {
    coin = 0;
    cin >> n >> w;
    vector<int> prices(n);
    for(auto& p : prices) cin >> p;

    for(int i=0; i<n-1; i++) {
        // 저점 구입
        if(prices[i] < prices[i+1]) {
            coin += w / prices[i];
            w %= prices[i];
        }
        // 고점 판매
        else if(prices[i] > prices[i+1]) {
            w += coin*prices[i];
            coin = 0;
        }
    }
    // 마지막에 남아있는 코인 판매
    w += prices[n-1]*coin;
    cout << w <<'\n';
}