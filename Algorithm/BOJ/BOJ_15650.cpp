#include <iostream>
#include <string>

using namespace std;

void f(int n, int cur, int len, string ret) {
    ret.push_back('0' + (char)cur);
    if (len == 1) {
        cout << ret << '\n';
        return;
    }
    ret.push_back(' ');
    len--;

    for (int i = cur + 1; i <= n - len + 1; i++) {
        f(n, i, len, ret);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n - m + 1; i++) {
        f(n, i, m, "");
    }
}