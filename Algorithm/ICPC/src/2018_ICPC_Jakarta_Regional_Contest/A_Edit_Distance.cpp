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

    string S;
    cin >> S;
    int zero = 0, one = 0;
    for (auto& s : S) {
        if (s == '0')
            zero++;
        else
            one++;
    }
    // 0과 1 개수가 다른 경우: 더 적은 숫자로 다 바꿔버리기
    if (zero != one) {
        if (zero > one) {
            for (auto& s : S) {
                cout << '1';
            }
            cout << '\n';
        } else {
            for (auto& s : S) {
                cout << '0';
            }
            cout << '\n';
        }
    }
    // 0과1이 반복되어서 나오는 부분이 길이의 절반 이상인 경우
    else {
        if (S.back() == '0') {
            for (int i = 1; i < S.size(); i++) cout << '0';
            cout << "1\n";
        } else {
            for (int i = 1; i < S.size(); i++) cout << '1';
            cout << "0\n";
        }
    }
}