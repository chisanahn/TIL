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

void explode(string& str, string& explosion) {
    stack<int> index;  // 폭발물 시작지점 저장.
    deque<char> ret;
    int check = 0;
    for (auto& s : str) {
        ret.push_back(s);
        if (s == explosion[check] || s == explosion[0]) {
            // 폭발물 중간에 폭발물이 있는 경우
            if (s == explosion[0] && check != 0) {
                index.push(check);
                check = 0;
            }
            // 폭발
            if (check == explosion.size() - 1) {
                for (int i = 0; i < explosion.size(); i++) ret.pop_back();
                // 이전 폭발물 이어서 시작
                if (!index.empty()) {
                    check = index.top() - 1;
                    index.pop();
                } else
                    check = -1;
            }
            check += 1;
        }
        // 폭발물이 중간에 끊긴 경우
        else {
            check = 0;
            while (!index.empty()) {
                index.pop();
            }
        }
    }
    if (ret.empty())
        cout << "FRULA";
    else
        for (auto& r : ret) cout << r;
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s, explosion;
    cin >> s >> explosion;

    explode(s, explosion);
}