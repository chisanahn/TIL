#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    map<int, int> arr;
    for(int i=0; i<n; i++) {
        int item;
        cin >> item;
        arr[item] += 1;
    }

    for(auto& a : arr) {
        for(int i=0; i<a.second; i++) {
            cout << a.first << '\n';
        }
    }
}