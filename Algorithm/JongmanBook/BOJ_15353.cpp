#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string addbig(string a, string b) {
    if (a.size() < b.size()) return addbig(b, a);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int i = 0;
    vector<int> arr;
    for (; i < b.size(); i++) {
        arr.push_back(a[i] - '0' + b[i] - '0');
    }
    for (; i < a.size(); i++) {
        arr.push_back(a[i]-'0');
    }
    arr.push_back(0);

    // 올림수 계산
    string ret;
    for (i = 0; i < arr.size(); i++) {
        if (arr[i] > 9) {
            arr[i] %= 10;
            arr[i + 1] += 1;
        }
        ret.push_back(arr[i] + '0');
    }

    // 0 제거
    for (i = ret.size() - 1; i > 0; i--) {
        if (ret[i] == '0')
            ret.pop_back();
        else
            break;
    }

    reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;
    cout << addbig(a, b) << '\n';
}