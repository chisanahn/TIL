#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    map <pair<int, string>, int> M;

    while(n--) {
        string s;
        cin >> s;
        M[{s.size(), s}] += 1;
    }

    for(auto& m : M) cout << m.first.second << '\n';
}