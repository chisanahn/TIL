#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    int max = 0;
    for(int i=0; i<k; i++) {
        cin >> A[i];
        max += A[i];
    }
    int sum = max;
    for(int i=k; i<n; i++) {
        cin >> A[i];
        sum += A[i];
        sum -= A[i-k];
        if(max < sum) max = sum;
    }
    cout << max << '\n';
}