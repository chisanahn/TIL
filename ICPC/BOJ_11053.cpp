#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for(auto& a : A) cin >> a;

    /// B[i]는 A[j]<A[i] && B[j]의 값이 가장 큰 j에 1을 더한값.
    int max = 0;
    vector<int> B(n);
    for(int i=0; i<n; i++) {
        int length = 0;
        for(int j=0; j<i; j++) {
            if(A[j]<A[i] && length < B[j]) length = B[j];
        }
        B[i] = length + 1;
        if(max < B[i]) max = B[i];
    }

    cout << max << '\n';
}