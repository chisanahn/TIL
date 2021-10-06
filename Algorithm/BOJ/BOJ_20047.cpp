#include <iostream>
#include <string>

using namespace std;

int n;
int coins[2];

string S, T;

bool check(int si, int ti, int ci) {
    // 따로 빼둔 코인
    if (si == coins[0] || si == coins[1]) return check(si + 1, ti, ci);
    // base case
    if (ti > n - 1) return true;

    // 따로 빼둔 코인을 사용하지 않는 경우
    if (si < n && S[si] == T[ti]) {
        if (check(si + 1, ti + 1, ci)) return true;
    }
    // 따로 빼둔 코인을 사용하는 경우
    if (ci > 1) return false;
    else if (S[coins[ci]] == T[ti]) return check(si, ti + 1, ci + 1);
    else return false;
}

int main() {
    cin >> n;
    cin >> S >> T;
    cin >> coins[0] >> coins[1];

    if (check(0, 0, 0)) cout << "YES\n";
    else cout << "NO\n";
}