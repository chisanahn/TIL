#include <iostream>
#include <vector>

using namespace std;

int triangle[500][500];

int sum[500][500];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            cin >> triangle[i][j];
        }
    }

    sum[0][0] = triangle[0][0];

    for(int i=1; i<n; i++) {
        int j;
        sum[i][0] = sum[i-1][0] + triangle[i][0];
        for(j=1; j<i; j++) {
            sum[i][j] = triangle[i][j] + max<int>(sum[i-1][j-1], sum[i-1][j]);
        }
        sum[i][j] = sum[i-1][j-1] + triangle[i][j];
    }

    int ret = 0;
    for(int i=0; i<n; i++) {
        if(ret < sum[n-1][i]) ret = sum[n-1][i];
    }
    cout << ret << '\n';
}