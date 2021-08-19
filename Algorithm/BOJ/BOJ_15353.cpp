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

void big_add(vector<int>& A, vector<int>& B) {
    if (A.size() < B.size()) return big_add(B, A);

    vector<int> ret(A.size() + 1, 0);
    int i = 0;
    for (; i < B.size(); i++) {
        ret[i] = A[i] + B[i];
    }
    for(;i<A.size();i++) {
        ret[i] += A[i];
    }

    for(int i=0; i<ret.size(); i++) {
        if(ret[i] / 10 != 0) {
            ret[i] %= 10;
            ret[i+1] += 1;
        }
    }
    
    if(ret.back() != 0) {
        cout << ret.back();
    }
    for(int i=ret.size()-2; i>=0; i--) {
        cout << ret[i];
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;
    vector<int> A, B;
    for (int i = 1; i <= a.size(); i++) {
        A.push_back(a[a.size() - i] - '0');
    }
    for (int i = 1; i <= b.size(); i++) {
        B.push_back(b[b.size() - i] - '0');
    }

    big_add(A, B);
}
