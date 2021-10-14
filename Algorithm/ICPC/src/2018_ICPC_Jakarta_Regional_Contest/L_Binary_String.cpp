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

    ll K;
    cin >> K;
    string S;
    cin >> S;

    // k의 이진수 문자열 길이
    ll ksize = 0;
    ll div = K;
    while (div > 0) {
        div /= 2;
        ksize++;
    }

    // K가 S보다 큰 경우 예외처리
    if (ksize > S.size()) {
        cout << "0\n";
        return 0;
    }

    ll ret = S.size() - ksize;

    // mins: S로 만들 수 있는 길이가 K인 숫자 중 가장 작은값.
    vector<ll> arr(S.size(), 0);
    arr[0] = 1;  // no leading zero
    ll count = 1;
    for (ll i = 0; i < S.size(); i++) {
        if (count == ksize) break; // 이 부분을 if 문 뒤에 놨을때 예외 상황 발생.
        if (S[i] == '0') {
            arr[i] = 1;
            count++;
        }
    }
    for (ll i = S.size() - 1; i >= 0; i--) {
        if (count == ksize) break;
        if (arr[i] == 0) {
            arr[i] = 1;
            count++;
        }
    }

    ll mins = 0;
    ll w = 1;
    for (ll i = arr.size() - 1; i >= 0; i--) {
        if (arr[i] == 1) {
            mins += (S[i] - '0') * w;
            w *= 2;
        }
    }

    // K보다 작거나 같은 수를 만들수없다면 ret += 1
    if (mins > K) ret++;

    cout << ret << '\n';
}