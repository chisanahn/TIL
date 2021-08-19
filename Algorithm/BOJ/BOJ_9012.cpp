#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool check_vps(const string& ps) {
    stack<int> s;
    for(auto& p : ps) {
        if(p=='(') s.push(1);
        if(p==')') {
            if(s.empty()) return false;
            else s.pop();
        }
    }
    if(s.empty()) return true;
    else return false;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string ps;
        cin >> ps;
        if(check_vps(ps)) cout << "YES\n";
        else cout << "NO\n";
    }
}