#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;
    stack<int> s;
    while(k--) {
        int item;
        cin >> item;
        if(item == 0) s.pop();
        else s.push(item);
    }
    int ret = 0;
    while(!s.empty()) {
        ret += s.top();
        s.pop();
    }
    cout << ret << '\n';
}