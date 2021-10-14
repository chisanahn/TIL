#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    map<int, int> M;
    M[0] = 1;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        sum = (sum + input) % m;
        M[sum] += 1;
    }

    long long ret = 0;
    for (auto& i : M) {
        ret += (long long)i.second * (i.second - 1) / 2;
    }
    cout << ret << '\n';
}