#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <deque>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long, long>;

void explode(string& str, string& explosion) {
    stack<deque> s;  // 문자열 저장.
    int check = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == explosion[check] || str[i] == explosion[0]) {
            // 폭발물 시작 지점.
            if (str[i] == explosion[0]) {
                s.push(i);
                check = 0;
            }
            // 폭발물 종료 지점.
            if (check == explosion.size() - 1) {
                // 폭발
                str.erase(s.top(), explosion.size());
                s.pop();
                i -= explosion.size();
                // 이전 폭발물 이어서 시작
                if (!s.empty()) {
                    check = i - s.top();
                } else
                    check = -1;
            }
            check += 1;
        }
        // 폭발물이 중간에 끊긴 경우
        else {
            check = 0;
            while (!s.empty()) {
                s.pop();
            }
        }

        if (str == "") break;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s, explosion;
    cin >> s >> explosion;

    explode(s, explosion);
    if (s == "")
        cout << "FRULA\n";
    else
        cout << s << '\n';
}