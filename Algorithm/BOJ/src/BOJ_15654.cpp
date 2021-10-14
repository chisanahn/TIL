#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void f(vector<int>& arr, vector<int>& visit, int m, vector<int>& ret) {
    if(m==0) {
        for(auto& r : ret) cout << r << " ";
        cout << '\n';
    }
    for(int i=0; i<arr.size(); i++) {
        if(visit[i] == 0) {
            visit[i] = 1;
            ret.push_back(arr[i]);
            f(arr, visit, m-1, ret);
            visit[i] = 0;
            ret.pop_back();
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for(auto& a : arr) cin >> a;
    sort(arr.begin(), arr.end());

    vector<int> visit(n, 0);
    vector<int> ret;   
    f(arr, visit, m, ret);
}