#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> A(n);
    for(auto& a : A) cin >> a;

    int max_len = 0, max_index;
    vector<int> B(n, 1);
    vector<int> prev(n, -1);
    for(int i=1; i<n; i++) {
        int len = 0;
        for(int j=0; j<i; j++) {
            if(A[i]>A[j] && len < B[j]) {
                len = B[j];
                prev[i] = j;
            }
        }
        B[i] = len;
        if(max_len < B[i]) {
            max_len = B[i];
            max_index = i;
        }
    }

    cout << max_len << '\n';
    vector<int> arr(max_len);
    for(auto& a : arr) {
        a = A[max_index];
        max_index = prev[max_index];
    }
    for(int i=arr.size()-1; i>=0; i--) {
        cout << arr[i] << " ";
    }
    cout << '\n';
}