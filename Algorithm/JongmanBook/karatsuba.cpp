#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void normalize(vector<int>& arr) {
    // 자릿수 올림
    for (int i = 0; i < arr.size(); i++) {
        // 음수인 경우
        if (arr[i] < 0) {
            int borrow = (-arr[i] + 9) / 10;
            arr[i + 1] -= borrow;
            arr[i] += borrow * 10;
        }
        // 양수인 경우
        else if (arr[i] > 9) {
            arr[i + 1] += arr[i] / 10;
            arr[i] %= 10;
        }
    }
    // 0 제거
    for (int i = arr.size() - 1; i >= 0; i--) {
        if (arr[i] == 0)
            arr.pop_back();
        else
            break;
    }
}

vector<int> mul(vector<int> a, vector<int> b) {
    vector<int> arr(a.size() + b.size() + 1, 0);
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            arr[i + j] += a[i] * b[j];
        }
    }
    normalize(arr);
    return arr;
}

// a가 b보다 큰 경우만 고려.
void subbig(vector<int>& a, vector<int>& b) {
    for (int i = 0; i < b.size(); i++) {
        a[i] -= b[i];
    }
    normalize(a);
}
// a + b*10^n
void addbig(vector<int>& a, vector<int>& b, int n) {
    for (int i = a.size(); i <= b.size() + n + 1; i++) a.push_back(0);
    for (int i = 0; i < b.size(); i++) {
        a[i + n] += b[i];
    }
    normalize(a);
}

vector<int> mulbig(vector<int> a, vector<int> b) {
    if (a.size() < b.size()) return mulbig(b, a);
    if (b.empty()) {
        vector<int> ret(1, 0);
        return ret;
    }
    if (a.size() < 3) return mul(a, b);
    int half = a.size() / 2;
    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin() + half, a.end());
    vector<int> b0(b.begin(), min(b.end(), b.begin() + half));
    vector<int> b1(min(b.end(), b.begin() + half), b.end());

    vector<int> z0 = mulbig(a1, b1);
    vector<int> z2 = mulbig(a0, b0);
    addbig(a0, a1, 0);
    addbig(b0, b1, 0);
    vector<int> z1 = mulbig(a0, b0);
    subbig(z1, z0);
    subbig(z1, z2);

    vector<int> ret = z2;
    addbig(ret, z1, half);
    addbig(ret, z0, half * 2);
    return ret;
}

int main() {
    string a, b;
    cin >> a >> b;
    vector<int> A(a.size());
    for (int i = 0; i < A.size(); i++) A[i] = a[a.size() - i - 1] - '0';
    vector<int> B(b.size());
    for (int i = 0; i < B.size(); i++) B[i] = b[b.size() - i - 1] - '0';

    vector<int> ret = mulbig(A, B);
    for (int i = ret.size() - 1; i >= 0; i--) cout << ret[i];
    cout << '\n';
}