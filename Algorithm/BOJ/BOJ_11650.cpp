#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    map<pair<int, int>, int> M;
    while(n--) {
        int x, y;
        cin >> x >> y;
        M[{x, y}] += 1;
    }

    for(auto& m : M) {
        cout << m.first.first << " " << m.first.second << '\n';
    }
}