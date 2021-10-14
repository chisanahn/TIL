#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool balance_check(string& str) {
    stack<char> bracket;
    for(auto& s : str) {
        if(s == '(') {
            bracket.push(s);
        }
        else if(s == '[') {
            bracket.push(s);
        }
        else if(s == ')') {
            if(bracket.empty()) return false;
            if(bracket.top() != '(') return false;
            bracket.pop();
        }
        else if(s == ']') {
            if(bracket.empty()) return false;
            if(bracket.top() != '[') return false;
            bracket.pop();
        }
    }
    if(bracket.empty()) return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string str;
    while(1) {
        getline(cin, str);
        if(str == ".") break;

        if(balance_check(str)) cout << "yes\n";
        else cout << "no\n";
    }
}