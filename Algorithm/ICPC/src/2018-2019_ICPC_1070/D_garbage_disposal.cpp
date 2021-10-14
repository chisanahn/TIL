#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
// 쓰레기를 버릴때 사용할 쓰레기봉투의 최소수

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // 날짜 수, 쓰레기 봉투 용량
    ll n, k;
    cin >> n >> k;
    // 하루에 발생하는 쓰레기수
    vector<ll> A(n);
    for (auto& a : A) cin >> a;

    ll num = 0;  // 사용한 쓰레기 봉투수
    ll must = 0;  // 오늘 꼭 버려야하는 쓰레기 <- 전날 넘긴 쓰레기
    for (ll i = 0; i < n; i++) {
        int temp = (A[i] + must) / k;
        // 전날 버린 쓰레기가 남아있는데 오늘 나온 쓰레기가 적은 경우
        if (temp == 0 && must != 0) {
            must = 0;
            num++;
        }
        else {
            num += temp;
            must = (A[i] + must) % k;
        }
        if (i == n - 1)
            if (must > 0)
                num++;
    }
    cout << num << '\n';
}