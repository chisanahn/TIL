#include <iostream>
#include <vector>

using namespace std;

int n;
int A[250];
int B[250];

int dp_a[250][65201];
int dp_b[250][65201];

// A의 누적 시간이 B보다 크되, B에게 최대한 많이 넘겨주기.
// 리턴값 : a_sum에서 줄어든 값
int a(int pos, int k) {
    // base case
    if (pos == n) return 0;
    if (dp_a[pos][k] != -1) return dp_a[pos][k];

    // B공장으로 작업을 넘겨주지 않는 경우
    int ret = a(pos + 1, k);
    // B공장으로 작업을 넘겨주는 경우
    if (k >= A[pos] + B[pos])
        ret = max(ret, A[pos] + a(pos + 1, k - A[pos] - B[pos]));
    return dp_a[pos][k] = ret;
}

// B의 누적 시간이 큰 경우
int b(int pos, int k) {
    // base case
    if (pos == n) return 0;
    if (dp_b[pos][k] != -1) return dp_b[pos][k];

    // A공장으로 작업을 넘겨주지 않는 경우
    int ret = b(pos + 1, k);
    // A공장으로 작업을 넘겨주는 경우
    if (k >= A[pos] + B[pos])
        ret = max(ret, B[pos] + b(pos + 1, k - B[pos] - A[pos]));
    return dp_b[pos][k] = ret;
}

int main() {
    int a_sum = 0, b_sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i] >> B[i];
        a_sum += A[i];
        b_sum += B[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 65201; j++) {
            dp_a[i][j] = -1;
            dp_b[i][j] = -1;
        }
    }
    int ret1 = a_sum - a(0, a_sum);
    int ret2 = b_sum - b(0, b_sum);
    cout << (ret1 < ret2 ? ret1 : ret2) << '\n';
}